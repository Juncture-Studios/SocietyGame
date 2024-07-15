// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueContentCatalogWidget.h"

#include "DialogueContentAttribute.h"
#include "DialogueContentWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SDialogueContentCatalogWidget::Construct(const FArguments& InArgs)
{
	Catalog = InArgs._Catalog;

	ChildSlot
	[
		SAssignNew(CatalogBox, SScrollBox)
	];

	CatalogBox->SetOrientation(Orient_Vertical);

	RebuildCatalogBox();
}

void SDialogueContentCatalogWidget::RebuildCatalogBox()
{
	CatalogBox->ClearChildren();

	CatalogBox->AddSlot()
	[
		SNew(STextBlock)
		.Text(FText::FromString(FString("Filter")))
	];

	CatalogBox->AddSlot()
	[
		SNew(SEditableTextBox)
		.OnTextCommitted(this, &SDialogueContentCatalogWidget::Filter)
		.Text(FText::FromString(FilterPhrase))
	];

	CatalogBox->AddSlot()
	[
		SNew(SBorder)
	];

	CatalogBox->AddSlot()
	[
		SNew(SButton)
		.Text(FText::FromString(FString::Printf(TEXT("Add Content"))))
		.HAlign(HAlign_Center)
		.OnClicked(this, &SDialogueContentCatalogWidget::AddContent)
	];

	for (int32 i = Catalog->Content.Num() - 1; i >= 0; i--)
	{
		if (!ContainsPhrase(Catalog->Content[i])) continue;

		CatalogBox->AddSlot()
		[
			SNew(SBorder)
		];
		CatalogBox->AddSlot()
		[
			SNew(SBox)
			.HeightOverride(400)
			[
				SNew(SDialogueContentWidget)
				.ContentIndex(i)
				.CatalogWidget(this)
			]
		];
	}
}

FReply SDialogueContentCatalogWidget::AddContent()
{
	Catalog->Modify();
	Catalog->AddContent();
	RebuildCatalogBox();
	return FReply::Handled();
}

void SDialogueContentCatalogWidget::Filter(const FText& Phrase, ETextCommit::Type Type)
{
	FilterPhrase = Phrase.ToString();
	RebuildCatalogBox();
}

bool SDialogueContentCatalogWidget::ContainsPhrase(const FDialogueContent& Content) const
{
	if (FilterPhrase.IsEmpty()) return true;

	if (Content.Name.ToString().Contains(FilterPhrase)) return true;

	for (const auto& Attribute : Content.Attributes)
	{
		if (Attribute->ContainsPhrase(FilterPhrase)) return true;
	}

	return false;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
