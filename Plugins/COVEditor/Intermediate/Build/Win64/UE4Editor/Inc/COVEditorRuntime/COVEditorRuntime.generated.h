// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UUserWidget;
class APlayerController;
#ifdef COVEDITORRUNTIME_COVEditorRuntime_generated_h
#error "COVEditorRuntime.generated.h already included, missing '#pragma once' in COVEditorRuntime.h"
#endif
#define COVEDITORRUNTIME_COVEditorRuntime_generated_h

#define COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCreate) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(UClass,Z_Param_WidgetType); \
		P_GET_OBJECT(APlayerController,Z_Param_OwningPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UUserWidget**)Z_Param__Result=UCOVEditorRuntimeLibrary::Create(Z_Param_WorldContextObject,Z_Param_WidgetType,Z_Param_OwningPlayer); \
		P_NATIVE_END; \
	}


#define COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCreate) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(UClass,Z_Param_WidgetType); \
		P_GET_OBJECT(APlayerController,Z_Param_OwningPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UUserWidget**)Z_Param__Result=UCOVEditorRuntimeLibrary::Create(Z_Param_WorldContextObject,Z_Param_WidgetType,Z_Param_OwningPlayer); \
		P_NATIVE_END; \
	}


#define COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCOVEditorRuntimeLibrary(); \
	friend struct Z_Construct_UClass_UCOVEditorRuntimeLibrary_Statics; \
public: \
	DECLARE_CLASS(UCOVEditorRuntimeLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/COVEditorRuntime"), NO_API) \
	DECLARE_SERIALIZER(UCOVEditorRuntimeLibrary)


#define COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_INCLASS \
private: \
	static void StaticRegisterNativesUCOVEditorRuntimeLibrary(); \
	friend struct Z_Construct_UClass_UCOVEditorRuntimeLibrary_Statics; \
public: \
	DECLARE_CLASS(UCOVEditorRuntimeLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/COVEditorRuntime"), NO_API) \
	DECLARE_SERIALIZER(UCOVEditorRuntimeLibrary)


#define COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCOVEditorRuntimeLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCOVEditorRuntimeLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCOVEditorRuntimeLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCOVEditorRuntimeLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCOVEditorRuntimeLibrary(UCOVEditorRuntimeLibrary&&); \
	NO_API UCOVEditorRuntimeLibrary(const UCOVEditorRuntimeLibrary&); \
public:


#define COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCOVEditorRuntimeLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCOVEditorRuntimeLibrary(UCOVEditorRuntimeLibrary&&); \
	NO_API UCOVEditorRuntimeLibrary(const UCOVEditorRuntimeLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCOVEditorRuntimeLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCOVEditorRuntimeLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCOVEditorRuntimeLibrary)


#define COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_PRIVATE_PROPERTY_OFFSET
#define COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_21_PROLOG
#define COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_PRIVATE_PROPERTY_OFFSET \
	COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_RPC_WRAPPERS \
	COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_INCLASS \
	COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_PRIVATE_PROPERTY_OFFSET \
	COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_INCLASS_NO_PURE_DECLS \
	COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COVEDITORRUNTIME_API UClass* StaticClass<class UCOVEditorRuntimeLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID COV_4_23_Plugins_COVEditor_Source_COVEditorRuntime_Public_COVEditorRuntime_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
