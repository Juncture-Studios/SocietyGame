// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueContentCatalog.h"

UDialogueContentCatalog::UDialogueContentCatalog()
{
}

void UDialogueContentCatalog::AddContent()
{
	Content.AddDefaulted();
}

void UDialogueContentCatalog::RemoveContent(const int Index)
{
	Content.RemoveAt(Index);
}
