// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class UDialogueContentAttributeSelector;
class SDialogueContentCatalogWidget;
/**
 * Widget for editing an FDialogueContent.
 */
class DIALOGUEEDITOR_API SDialogueContentWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SDialogueContentWidget)
		{}
		SLATE_ARGUMENT(int, ContentIndex);
		SLATE_ARGUMENT(SDialogueContentCatalogWidget*, CatalogWidget);
	SLATE_END_ARGS()
	
	int ContentIndex;

	SDialogueContentCatalogWidget* CatalogWidget;

	TSharedPtr<SScrollBox> AttributesBox;

	TSharedPtr<IDetailsView> ClassSelectorPropertyWidget;

	TArray<TSharedPtr<IDetailsView>> AttributePropertyWidgets;
	
	void Construct(const FArguments& InArgs);

	FReply RemoveContent();

	void ChangeName(const FText& NewName, ETextCommit::Type Type);

	void RebuildAttributesBox();

	FReply AddAttribute();

	FReply RemoveAttribute(const uint32 Index);
};
