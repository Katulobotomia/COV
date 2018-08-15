// Fill out your copyright notice in the Description page of Project Settings.

#include "COVBlueprintFunctionLibrary.h"
#include "CollisionQueryParams.h"
#include "Engine.h"
#include "Kismet/KismetMathLibrary.h"

DEFINE_LOG_CATEGORY(COVBlueprintFunctionLibrary)

FHitResult UCOVBlueprintFunctionLibrary::SimpleTraceByChannel(UObject* inObj, FVector startPos, FVector endPos)
{
	//	LINETRACE	################################
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("Joonas")), false);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bTraceAsyncScene = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;
	RV_TraceParams.AddIgnoredActor(Cast<AActor>(inObj));

	//Re-initialize hit info
	FHitResult RV_Hit(ForceInit);

	//call GetWorld() from within an actor extending class
	bool blockingHit = inObj->GetWorld()->LineTraceSingleByChannel(
		RV_Hit,        //result
		startPos,    //start
		endPos, //end
		ECC_Camera, //collision channel
		RV_TraceParams
	);
	//	############################################
	return RV_Hit;
}

int32 UCOVBlueprintFunctionLibrary::GetNumberOfRowsInFile(FString FileName, FString folder)
{
	COV_LOG(COVBlueprintFunctionLibrary, Log, TEXT("Reading the number of lines in a file (%s)."), *FileName);

	int32 rowCount;
	TArray<FString> rows;
	FString filePath = FString(FPaths::GameDir()).Append(folder).Append(FileName);
	bool foundSomething = FFileHelper::LoadANSITextFileToStrings(*filePath, NULL, rows);

	if (foundSomething)
	{
		rowCount = rows.Num();
		COV_LOG(COVBlueprintFunctionLibrary, Log, TEXT("Found a number of (%d) rows in the file (%s)."), rowCount, *FileName);
		return rowCount;
	}
	return -1;
}

FString UCOVBlueprintFunctionLibrary::ReadConfigFileLine(FString fileName, FString configName)
{
	return ReadFileLine(fileName, FString(TEXT("/Config/")), configName);
}

FString UCOVBlueprintFunctionLibrary::ReadFileLine(FString fileName, FString folder, FString configName)
{
	TArray<FString> rows;
	FString filePath = FString(FPaths::GameDir()).Append(folder).Append(fileName);
	bool foundSomething = FFileHelper::LoadANSITextFileToStrings(*filePath, NULL, rows);

	if (foundSomething)
	{
		COV_LOG(COVBlueprintFunctionLibrary, Log, TEXT("Found a file with the name (%s). Processing words to locate the setting for configuration (%s)."), *fileName, *configName);

		for(auto & row : rows)
		{
			bool containsString = row.Contains(configName, ESearchCase::IgnoreCase, ESearchDir::FromStart);

			if (containsString)
			{
				TArray<FString> parsedLine;
				row.ParseIntoArray(parsedLine, TEXT("="), true);
				int32 parsedArrayLength = parsedLine.Num();
				FString valueFound = parsedLine[parsedArrayLength - 1];
				//	Remove spaces if any
				valueFound.RemoveFromStart(TEXT(" "));

				COV_LOG(COVBlueprintFunctionLibrary, Log, TEXT("Configuration (%s) found with the value of (%s)"), *configName, *valueFound);
				return parsedLine[parsedArrayLength - 1];
			}
		}
		COV_LOG(COVBlueprintFunctionLibrary, Warning, TEXT("No line (%s) was found�in the config file (%s)."), *configName, *fileName);

		return FString(TEXT(""));
	}
	else
	{
		COV_LOG(COVBlueprintFunctionLibrary, Warning, TEXT("Did not find a file named (%s)."), *fileName);
		return FString(TEXT(""));
	}
}

FString UCOVBlueprintFunctionLibrary::GetGameVersionAsString()
{
	float numberOfCommits = (float)GetNumberOfRowsInFile(FString(TEXT("HEAD")), FString(TEXT("/.git/logs/")));
	FString versionType = ReadConfigFileLine(FString(TEXT("COV_GameInfo.txt")), FString(TEXT("Version")));

	return FString::FormatAsNumber(numberOfCommits / 1000.0f).Append(TEXT(" ")).Append(versionType);
}