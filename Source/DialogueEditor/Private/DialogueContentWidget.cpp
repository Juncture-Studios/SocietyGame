// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueContentWidget.h"

#include "DialogueContentAttribute.h"
#include "DialogueContentAttributeSelector.h"
#include "DialogueContentCatalogWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SDialogueContentWidget::Construct(const FArguments& InArgs)
{
	ContentIndex = InArgs._ContentIndex;
	CatalogWidget = InArgs._CatalogWidget;

	//Load property module.
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs Args;
	Args.bHideSelectionTip = true;
	Args.bAllowSearch = false;
	Args.bShowSectionSelector = false;

	//Setup class selector widget.
	ClassSelectorPropertyWidget = PropertyModule.CreateDetailView(Args);
	ClassSelectorPropertyWidget->SetObject(GetMutableDefault<UDialogueContentAttributeSelector>());

	ChildSlot
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.FillWidth(0.2)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Bottom)
			[
				SNew(STextBlock)
				.Text(FText::FromString(FString("Content Name")))
			]
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Top)
			[
				SNew(SEditableTextBox)
				.OnTextCommitted(this, &SDialogueContentWidget::ChangeName)
				.Text(CatalogWidget->Catalog->Content[ContentIndex].Name)
			]
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Bottom)
			[
				ClassSelectorPropertyWidget.ToSharedRef()
			]
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Top)
			[
				SNew(SButton)
				.Text(FText::FromString(FString::Printf(TEXT("Add Selected Attribute"))))
				.HAlign(HAlign_Center)
				.OnClicked(this, &SDialogueContentWidget::AddAttribute)
			]
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(SButton)
				.Text(FText::FromString(FString::Printf(TEXT("Remove Content"))))
				.HAlign(HAlign_Center)
				.OnClicked(this, &SDialogueContentWidget::RemoveContent)
			]
		]
		+ SHorizontalBox::Slot()
		.FillWidth(0.8)
		[
			SAssignNew(AttributesBox, SScrollBox)
		]
	];

	AttributesBox->SetOrientation(Orient_Horizontal);

	RebuildAttributesBox();
}

FReply SDialogueContentWidget::RemoveContent()
{
	CatalogWidget->Catalog->Modify();
	CatalogWidget->Catalog->RemoveContent(ContentIndex);
	CatalogWidget->RebuildCatalogBox();
	return FReply::Handled();
}

void SDialogueContentWidget::ChangeName(const FText& NewName, ETextCommit::Type Type)
{
	CatalogWidget->Catalog->Modify();
	CatalogWidget->Catalog->Content[ContentIndex].Name = NewName;
}

void SDialogueContentWidget::RebuildAttributesBox()
{
	AttributesBox->ClearChildren();

	const TArray<UDialogueContentAttribute*>& Attributes = CatalogWidget->Catalog->Content[ContentIndex].Attributes;

	AttributePropertyWidgets.Empty();

	//Load property module.
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs Args;
	Args.bHideSelectionTip = true;
	Args.bAllowSearch = false;
	Args.bShowSectionSelector = false;

	for (int32 i = Attributes.Num() - 1; i >= 0; i--)
	{
		const uint32 WidgetIndex = AttributePropertyWidgets.Emplace(PropertyModule.CreateDetailView(Args));
		AttributePropertyWidgets[WidgetIndex]->SetObject(Attributes[i]);

		AttributesBox->AddSlot()
		[
			SNew(SBorder)
		];
		AttributesBox->AddSlot()
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.MaxHeight(360)
			.FillHeight(0.9)
			[
				AttributePropertyWidgets
				[
					WidgetIndex
				]
				.ToSharedRef()
			]
			+ SVerticalBox::Slot()
			.MaxHeight(40)
			.VAlign(VAlign_Bottom)
			.FillHeight(0.1)
			[
				SNew(SButton)
				.Text(FText::FromString(FString::Printf(TEXT("Remove Attribute"))))
				.HAlign(HAlign_Center)
				.OnClicked(this, &SDialogueContentWidget::RemoveAttribute, static_cast<uint32>(i))
			]
		];
	}
}

FReply SDialogueContentWidget::AddAttribute()
{
	const UClass* Class = GetDefault<UDialogueContentAttributeSelector>()->Attribute;
	if (!Class || Class == UDialogueContentAttribute::StaticClass()) return FReply::Handled();
	TArray<UDialogueContentAttribute*>& Attributes = CatalogWidget->Catalog->Content[ContentIndex].Attributes;
	CatalogWidget->Catalog->Modify();
	Attributes.Emplace(NewObject<UDialogueContentAttribute>(CatalogWidget->Catalog, Class));
	RebuildAttributesBox();
	return FReply::Handled();
}

FReply SDialogueContentWidget::RemoveAttribute(const uint32 Index)
{
	TArray<UDialogueContentAttribute*>& Attributes = CatalogWidget->Catalog->Content[ContentIndex].Attributes;
	CatalogWidget->Catalog->Modify();
	Attributes.RemoveAt(Index);
	RebuildAttributesBox();
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
