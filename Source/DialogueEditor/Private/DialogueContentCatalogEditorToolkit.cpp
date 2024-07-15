// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueContentCatalogEditorToolkit.h"

#include "DialogueContentCatalog.h"
#include "DialogueContentCatalogWidget.h"

void FDialogueContentCatalogEditorToolkit::InitEditor(const TArray<UObject*>& InObjects)
{
	Catalog = Cast<UDialogueContentCatalog>(InObjects[0]);

	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("DialogueContentCatalogEditorLayout")
	->AddArea
	(
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
		->Split
		(
			FTabManager::NewStack()
			->AddTab("DialogueContentCatalogTab", ETabState::OpenedTab)
		)
	);
	FAssetEditorToolkit::InitAssetEditor(EToolkitMode::Standalone, {}, "DialogueContentCatalogEditor", Layout, true, true, InObjects);
}

void FDialogueContentCatalogEditorToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(INVTEXT("Dialogue Content Catalog Editor"));

	InTabManager->RegisterTabSpawner("DialogueContentCatalogTab", FOnSpawnTab::CreateLambda([=, this](const FSpawnTabArgs&)
	{
		return SNew(SDockTab)
			[
				SNew(SDialogueContentCatalogWidget)
				.Catalog(Catalog)
			];
	}))
	.SetDisplayName(INVTEXT("DCC Editor"))
	.SetGroup(WorkspaceMenuCategory.ToSharedRef());
}

void FDialogueContentCatalogEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner("DialogueContentCatalogTab");
}
