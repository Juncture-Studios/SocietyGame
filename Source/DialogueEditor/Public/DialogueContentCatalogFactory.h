﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "DialogueContentCatalogFactory.generated.h"

UCLASS()
class DIALOGUEEDITOR_API UDialogueContentCatalogFactory : public UFactory
{
	GENERATED_BODY()
public:
	UDialogueContentCatalogFactory();
	UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
