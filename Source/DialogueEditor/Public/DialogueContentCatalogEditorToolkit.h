// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class UDialogueContentCatalog;

class DIALOGUEEDITOR_API FDialogueContentCatalogEditorToolkit : public FAssetEditorToolkit
{
public:
	void InitEditor(const TArray<UObject*>& InObjects);

	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

	virtual FName GetToolkitFName() const override { return "DialogueContentCatalogEditor"; }
	virtual FText GetBaseToolkitName() const override { return INVTEXT("Dialogue Content Catalog Editor"); }
	virtual FString GetWorldCentricTabPrefix() const override { return "Dialogue Content Catalog "; }
	virtual FLinearColor GetWorldCentricTabColorScale() const override { return {}; }

private:
	UDialogueContentCatalog* Catalog = nullptr;
};
