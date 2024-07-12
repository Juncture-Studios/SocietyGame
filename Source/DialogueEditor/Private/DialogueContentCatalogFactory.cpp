// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueContentCatalogFactory.h"

#include "DialogueContentCatalog.h"

UDialogueContentCatalogFactory::UDialogueContentCatalogFactory()
{
	SupportedClass = UDialogueContentCatalog::StaticClass();
	bCreateNew = true;
}

UObject* UDialogueContentCatalogFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName,
	EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UDialogueContentCatalog>(InParent, InClass, InName, Flags, Context);
}
