// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class COVEditor : ModuleRules
{
	public COVEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"COVEditorRuntime",
                "UMG"
				// ... add other public dependencies that you statically link with here ...
			}
		);
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...
				"Core",
				"CoreUObject",
				"InputCore",
				"Slate",
				"Engine",
				"AssetTools",
				"UnrealEd", // for FAssetEditorManager
				"KismetWidgets",
				"KismetCompiler",
				"BlueprintGraph",
				"GraphEditor",
				"Kismet",  // for FWorkflowCentricApplication
				"PropertyEditor",
				"EditorStyle",
				"Slate",
				"SlateCore",
				"Sequencer",
				"DetailCustomizations",
				"Settings",
				"RenderCore"
			}
		);
			}
}
