// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayObjectComponents/Public/HoveringMotion.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHoveringMotion() {}
// Cross Module References
	GAMEPLAYOBJECTCOMPONENTS_API UClass* Z_Construct_UClass_UHoveringMotion_NoRegister();
	GAMEPLAYOBJECTCOMPONENTS_API UClass* Z_Construct_UClass_UHoveringMotion();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_GameplayObjectComponents();
	GAMEPLAYOBJECTCOMPONENTS_API UFunction* Z_Construct_UFunction_UHoveringMotion_SetAnimating();
	GAMEPLAYOBJECTCOMPONENTS_API UFunction* Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh();
	ENGINE_API UClass* Z_Construct_UClass_UMeshComponent_NoRegister();
// End Cross Module References
	void UHoveringMotion::StaticRegisterNativesUHoveringMotion()
	{
		UClass* Class = UHoveringMotion::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetAnimating", &UHoveringMotion::execSetAnimating },
			{ "SetHoveringMesh", &UHoveringMotion::execSetHoveringMesh },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics
	{
		struct HoveringMotion_eventSetAnimating_Parms
		{
			bool bShouldAnimate;
		};
		static void NewProp_bShouldAnimate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShouldAnimate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics::NewProp_bShouldAnimate_SetBit(void* Obj)
	{
		((HoveringMotion_eventSetAnimating_Parms*)Obj)->bShouldAnimate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics::NewProp_bShouldAnimate = { "bShouldAnimate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(HoveringMotion_eventSetAnimating_Parms), &Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics::NewProp_bShouldAnimate_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics::NewProp_bShouldAnimate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics::Function_MetaDataParams[] = {
		{ "Category", "Hovering Motion" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHoveringMotion, nullptr, "SetAnimating", nullptr, nullptr, sizeof(HoveringMotion_eventSetAnimating_Parms), Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHoveringMotion_SetAnimating()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UHoveringMotion_SetAnimating_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics
	{
		struct HoveringMotion_eventSetHoveringMesh_Parms
		{
			UMeshComponent* meshComponentToHover;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_meshComponentToHover_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_meshComponentToHover;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::NewProp_meshComponentToHover_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::NewProp_meshComponentToHover = { "meshComponentToHover", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HoveringMotion_eventSetHoveringMesh_Parms, meshComponentToHover), Z_Construct_UClass_UMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::NewProp_meshComponentToHover_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::NewProp_meshComponentToHover_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::NewProp_meshComponentToHover,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::Function_MetaDataParams[] = {
		{ "Category", "Hovering Motion" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHoveringMotion, nullptr, "SetHoveringMesh", nullptr, nullptr, sizeof(HoveringMotion_eventSetHoveringMesh_Parms), Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UHoveringMotion_NoRegister()
	{
		return UHoveringMotion::StaticClass();
	}
	struct Z_Construct_UClass_UHoveringMotion_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HoverRepeatFrequency_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HoverRepeatFrequency;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HoverZMovementDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HoverZMovementDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HoverYMovementDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HoverYMovementDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HoverXMovementDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HoverXMovementDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHoverZAxis_MetaData[];
#endif
		static void NewProp_bHoverZAxis_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHoverZAxis;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHoverYAxis_MetaData[];
#endif
		static void NewProp_bHoverYAxis_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHoverYAxis;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHoverXAxis_MetaData[];
#endif
		static void NewProp_bHoverXAxis_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHoverXAxis;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHoverMovement_MetaData[];
#endif
		static void NewProp_bHoverMovement_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHoverMovement;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRandomizeInitialRotation_MetaData[];
#endif
		static void NewProp_bRandomizeInitialRotation_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRandomizeInitialRotation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ZAxisRotationSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ZAxisRotationSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_YAxisRotationSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_YAxisRotationSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_XAxisRotationSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_XAxisRotationSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRotateZAxis_MetaData[];
#endif
		static void NewProp_bRotateZAxis_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRotateZAxis;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRotateYAxis_MetaData[];
#endif
		static void NewProp_bRotateYAxis_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRotateYAxis;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRotateXAxis_MetaData[];
#endif
		static void NewProp_bRotateXAxis_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRotateXAxis;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRotate_MetaData[];
#endif
		static void NewProp_bRotate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRotate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsAnimating_MetaData[];
#endif
		static void NewProp_bIsAnimating_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsAnimating;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshToHover_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshToHover;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHoveringMotion_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_GameplayObjectComponents,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UHoveringMotion_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UHoveringMotion_SetAnimating, "SetAnimating" }, // 3645170353
		{ &Z_Construct_UFunction_UHoveringMotion_SetHoveringMesh, "SetHoveringMesh" }, // 4114913754
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "HoveringMotion.h" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverRepeatFrequency_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "EditCondition", "bHoverMovement" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverRepeatFrequency = { "HoverRepeatFrequency", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHoveringMotion, HoverRepeatFrequency), METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverRepeatFrequency_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverRepeatFrequency_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverZMovementDistance_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "EditCondition", "bHoverMovement" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverZMovementDistance = { "HoverZMovementDistance", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHoveringMotion, HoverZMovementDistance), METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverZMovementDistance_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverZMovementDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverYMovementDistance_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "EditCondition", "bHoverMovement" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverYMovementDistance = { "HoverYMovementDistance", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHoveringMotion, HoverYMovementDistance), METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverYMovementDistance_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverYMovementDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverXMovementDistance_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "EditCondition", "bHoverMovement" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverXMovementDistance = { "HoverXMovementDistance", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHoveringMotion, HoverXMovementDistance), METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverXMovementDistance_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverXMovementDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverZAxis_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "Comment", "//\x09If the mesh will rotate around z axis\n" },
		{ "EditCondition", "bHoverMovement" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
		{ "ToolTip", "If the mesh will rotate around z axis" },
	};
#endif
	void Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverZAxis_SetBit(void* Obj)
	{
		((UHoveringMotion*)Obj)->bHoverZAxis = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverZAxis = { "bHoverZAxis", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UHoveringMotion), &Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverZAxis_SetBit, METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverZAxis_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverZAxis_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverYAxis_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "Comment", "//\x09If the mesh will rotate around z axis\n" },
		{ "EditCondition", "bHoverMovement" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
		{ "ToolTip", "If the mesh will rotate around z axis" },
	};
#endif
	void Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverYAxis_SetBit(void* Obj)
	{
		((UHoveringMotion*)Obj)->bHoverYAxis = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverYAxis = { "bHoverYAxis", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UHoveringMotion), &Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverYAxis_SetBit, METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverYAxis_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverYAxis_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverXAxis_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "Comment", "//\x09If the mesh will rotate around z axis\n" },
		{ "EditCondition", "bHoverMovement" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
		{ "ToolTip", "If the mesh will rotate around z axis" },
	};
#endif
	void Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverXAxis_SetBit(void* Obj)
	{
		((UHoveringMotion*)Obj)->bHoverXAxis = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverXAxis = { "bHoverXAxis", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UHoveringMotion), &Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverXAxis_SetBit, METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverXAxis_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverXAxis_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverMovement_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "Comment", "//\x09If the mesh will hover\n" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
		{ "ToolTip", "If the mesh will hover" },
	};
#endif
	void Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverMovement_SetBit(void* Obj)
	{
		((UHoveringMotion*)Obj)->bHoverMovement = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverMovement = { "bHoverMovement", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UHoveringMotion), &Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverMovement_SetBit, METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverMovement_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverMovement_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRandomizeInitialRotation_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "Comment", "//\x09If the mesh will rotate around z axis\n" },
		{ "EditCondition", "bRotate" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
		{ "ToolTip", "If the mesh will rotate around z axis" },
	};
#endif
	void Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRandomizeInitialRotation_SetBit(void* Obj)
	{
		((UHoveringMotion*)Obj)->bRandomizeInitialRotation = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRandomizeInitialRotation = { "bRandomizeInitialRotation", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UHoveringMotion), &Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRandomizeInitialRotation_SetBit, METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRandomizeInitialRotation_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRandomizeInitialRotation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_ZAxisRotationSpeed_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "EditCondition", "bRotate" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_ZAxisRotationSpeed = { "ZAxisRotationSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHoveringMotion, ZAxisRotationSpeed), METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_ZAxisRotationSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_ZAxisRotationSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_YAxisRotationSpeed_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "EditCondition", "bRotate" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_YAxisRotationSpeed = { "YAxisRotationSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHoveringMotion, YAxisRotationSpeed), METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_YAxisRotationSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_YAxisRotationSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_XAxisRotationSpeed_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "EditCondition", "bRotate" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_XAxisRotationSpeed = { "XAxisRotationSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHoveringMotion, XAxisRotationSpeed), METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_XAxisRotationSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_XAxisRotationSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateZAxis_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "Comment", "//\x09If the mesh will rotate around z axis\n" },
		{ "EditCondition", "bRotate" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
		{ "ToolTip", "If the mesh will rotate around z axis" },
	};
#endif
	void Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateZAxis_SetBit(void* Obj)
	{
		((UHoveringMotion*)Obj)->bRotateZAxis = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateZAxis = { "bRotateZAxis", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UHoveringMotion), &Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateZAxis_SetBit, METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateZAxis_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateZAxis_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateYAxis_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "Comment", "//\x09If the mesh will rotate around y axis\n" },
		{ "EditCondition", "bRotate" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
		{ "ToolTip", "If the mesh will rotate around y axis" },
	};
#endif
	void Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateYAxis_SetBit(void* Obj)
	{
		((UHoveringMotion*)Obj)->bRotateYAxis = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateYAxis = { "bRotateYAxis", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UHoveringMotion), &Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateYAxis_SetBit, METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateYAxis_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateYAxis_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateXAxis_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "Comment", "//\x09If the mesh will rotate around x axis\n" },
		{ "EditCondition", "bRotate" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
		{ "ToolTip", "If the mesh will rotate around x axis" },
	};
#endif
	void Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateXAxis_SetBit(void* Obj)
	{
		((UHoveringMotion*)Obj)->bRotateXAxis = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateXAxis = { "bRotateXAxis", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UHoveringMotion), &Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateXAxis_SetBit, METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateXAxis_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateXAxis_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotate_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "Comment", "//\x09If the mesh will rotate\n" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
		{ "ToolTip", "If the mesh will rotate" },
	};
#endif
	void Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotate_SetBit(void* Obj)
	{
		((UHoveringMotion*)Obj)->bRotate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotate = { "bRotate", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UHoveringMotion), &Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotate_SetBit, METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bIsAnimating_MetaData[] = {
		{ "Category", "Hovering Motion" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
	};
#endif
	void Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bIsAnimating_SetBit(void* Obj)
	{
		((UHoveringMotion*)Obj)->bIsAnimating = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bIsAnimating = { "bIsAnimating", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UHoveringMotion), &Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bIsAnimating_SetBit, METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bIsAnimating_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bIsAnimating_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoveringMotion_Statics::NewProp_MeshToHover_MetaData[] = {
		{ "Comment", "//\x09The hovering mesh of the actor\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HoveringMotion.h" },
		{ "ToolTip", "The hovering mesh of the actor" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHoveringMotion_Statics::NewProp_MeshToHover = { "MeshToHover", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHoveringMotion, MeshToHover), Z_Construct_UClass_UMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_MeshToHover_MetaData, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::NewProp_MeshToHover_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHoveringMotion_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverRepeatFrequency,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverZMovementDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverYMovementDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_HoverXMovementDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverZAxis,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverYAxis,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverXAxis,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bHoverMovement,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRandomizeInitialRotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_ZAxisRotationSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_YAxisRotationSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_XAxisRotationSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateZAxis,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateYAxis,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotateXAxis,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bRotate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_bIsAnimating,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoveringMotion_Statics::NewProp_MeshToHover,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHoveringMotion_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHoveringMotion>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UHoveringMotion_Statics::ClassParams = {
		&UHoveringMotion::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UHoveringMotion_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UHoveringMotion_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UHoveringMotion_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UHoveringMotion()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UHoveringMotion_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UHoveringMotion, 4189454743);
	template<> GAMEPLAYOBJECTCOMPONENTS_API UClass* StaticClass<UHoveringMotion>()
	{
		return UHoveringMotion::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UHoveringMotion(Z_Construct_UClass_UHoveringMotion, &UHoveringMotion::StaticClass, TEXT("/Script/GameplayObjectComponents"), TEXT("UHoveringMotion"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHoveringMotion);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
