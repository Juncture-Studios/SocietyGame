// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentCatalog.h"
#include "Widgets/SCompoundWidget.h"

/**
 * Widget for editing a UDialogueContentCatalog.
 */
class DIALOGUEEDITOR_API SDialogueContentCatalogWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SDialogueContentCatalogWidget)
		{}
		SLATE_ARGUMENT(UDialogueContentCatalog*, Catalog)
	SLATE_END_ARGS()

	UDialogueContentCatalog* Catalog;

	TSharedPtr<SScrollBox> CatalogBox;

	FString FilterPhrase;
	
	void Construct(const FArguments& InArgs);

	void RebuildCatalogBox();

	FReply AddContent();

	void Filter(const FText& Phrase, ETextCommit::Type Type);

	bool ContainsPhrase(const FDialogueContent& Content) const;
};
