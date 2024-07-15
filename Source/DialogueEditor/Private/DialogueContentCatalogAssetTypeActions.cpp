// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueContentCatalogAssetTypeActions.h"

#include "DialogueContentCatalog.h"
#include "DialogueContentCatalogEditorToolkit.h"

UClass* FDialogueContentCatalogAssetTypeActions::GetSupportedClass() const
{
	return UDialogueContentCatalog::StaticClass();
}

FText FDialogueContentCatalogAssetTypeActions::GetName() const
{
	return INVTEXT("Dialogue Content Catalog");
}

FColor FDialogueContentCatalogAssetTypeActions::GetTypeColor() const
{
	return FColor::Cyan;
}

uint32 FDialogueContentCatalogAssetTypeActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

void FDialogueContentCatalogAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects,
	TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	MakeShared<FDialogueContentCatalogEditorToolkit>()->InitEditor(InObjects);
}
