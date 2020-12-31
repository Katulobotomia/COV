// Fill out your copyright notice in the Description page of Project Settings.

#include "LootSpawner.h"

#include "Kismet/KismetMathLibrary.h"

DEFINE_LOG_CATEGORY(LogLootSpawner)

FString FLootSpawnDefinition::ToString() const
{
	FString FinalString = FString("\n......[LootType = ") + GetNameSafe(LootType);
	FinalString = FinalString + FString(", SpawnProbabilityWeight = ") + FString::FromInt(SpawnProbabilityWeight) + FString("]");
	return FinalString;
}

FString FLootProfile::ToString() const
{
	FString FinalString("...[Amount of loot to spawn (min ");
	FinalString = FinalString + FString::FromInt(AmountOfLootToSpawn.MinimumAmountToSpawn);
	FinalString = FinalString + FString(", max ");
	FinalString = FinalString + FString::FromInt(AmountOfLootToSpawn.MaximumAmountToSpawn);
	FinalString = FinalString + FString(")");
	
	for(const FLootSpawnDefinition& LSD : LootSpawnDefinitions)
	{
		FinalString = FinalString + LSD.ToString();
	}

	return FinalString;
}

// Sets default values
ALootSpawner::ALootSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

bool ALootSpawner::SpawnLoot(FLootProfile LootProfileToSpawn)
{
	UE_LOG(LogLootSpawner, Log, TEXT("Beginning loot spawning of profile =\n%s"), *LootProfileToSpawn.ToString());
	UWorld* World = GetWorld();
	check(IsValid(World));

	if(!ensureAlwaysMsgf(LootProfileToSpawn.LootSpawnDefinitions.Num() > 0, TEXT("No loot definitions defined. Did you forget to define some? (%s) can't spawn any loot."), *GetNameSafe(this)))
	{
		return false;
	}
	
	int32 LootSpawned = 0;
	int32 FailedSpawned = 0;
	FLootSpawnDefinition* LootSelectedForSpawn = nullptr;
	const int32 AmountOfLootToSpawn = UKismetMathLibrary::RandomIntegerInRange(LootProfileToSpawn.AmountOfLootToSpawn.MinimumAmountToSpawn, LootProfileToSpawn.AmountOfLootToSpawn.MaximumAmountToSpawn);
	
	do
	{
		//	See which loot will spawn next...
		int32 TotalWeightOfAllLoot = 0;
		for(const FLootSpawnDefinition& LootDefinition : LootProfileToSpawn.LootSpawnDefinitions)
		{
			TotalWeightOfAllLoot += LootDefinition.SpawnProbabilityWeight;
		}

		//	Throw dart...
		const int32 Dart = UKismetMathLibrary::RandomIntegerInRange(0, TotalWeightOfAllLoot);

		//	See where dart landed
		int32 LandingLocation = 0;
		int32 Index = 0;
		for(FLootSpawnDefinition& LootDefinition : LootProfileToSpawn.LootSpawnDefinitions)
		{
			LandingLocation += LootDefinition.SpawnProbabilityWeight;

			if(LandingLocation >= Dart)
			{
				ensureAlwaysMsgf(IsValid(LootDefinition.LootType), TEXT("LootDefinition is missing loot type. Can't spawn loot in the definition of index (%d) on (%s) spawner."), Index, *GetNameSafe(this));
				LootSelectedForSpawn = &LootDefinition;
				break;
			}

			Index++;
		}

		if(LootSelectedForSpawn && IsValid(LootSelectedForSpawn->LootType))
		{
			FActorSpawnParameters SpawnParams;
			const FVector& Location = GetActorLocation();
			const FRotator& Rotation = GetActorRotation();
			AActor* SpawnedActor = World->SpawnActor(LootSelectedForSpawn->LootType, &Location, &Rotation, SpawnParams);
		
			if(IsValid(SpawnedActor))
			{
				LootSpawned++;
				LootSelectedForSpawn->TimesAlreadySpawned++;

				//	If the loot can no longer be spawned, remove it from the definitions
				if(LootSelectedForSpawn->MaximumNumberOfSpawns > 0 && LootSelectedForSpawn->MaximumNumberOfSpawns == LootSelectedForSpawn->TimesAlreadySpawned)
				{
					const int32 IndexToRemove = LootProfileToSpawn.LootSpawnDefinitions.Find(*LootSelectedForSpawn);
					LootProfileToSpawn.LootSpawnDefinitions.RemoveAt(IndexToRemove);
					UE_LOG(LogLootSpawner, Verbose, TEXT("Maximum number of loot (%s) spawned by (%s). It will no longer spawn in this loot spawn event."), *GetNameSafe(LootSelectedForSpawn->LootType), *GetNameSafe(this));
				}
			}
			else
			{
				FailedSpawned++;
			}
		}
		else
		{
			FailedSpawned++;
		}

		LootSelectedForSpawn = nullptr;
	}
	while(LootSpawned < AmountOfLootToSpawn && LootProfileToSpawn.LootSpawnDefinitions.Num() > 0);

	ensureAlwaysMsgf(LootSpawned >= LootProfileToSpawn.AmountOfLootToSpawn.MinimumAmountToSpawn, TEXT("Loot spawner (%s) could not spawn the required amount (%d) of loot. Successful spawns (%d)"), *GetNameSafe(this), LootProfileToSpawn.AmountOfLootToSpawn.MinimumAmountToSpawn, LootSpawned);
	
	UE_LOG(LogLootSpawner, Log, TEXT("...loot spawning done. Successful spawns = %d, failures = %d"), LootSpawned, FailedSpawned);

	return FailedSpawned > 0;
}

// Called when the game starts or when spawned
void ALootSpawner::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ALootSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}