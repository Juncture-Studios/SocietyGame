﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "VariationDca.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UVariationDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	//Variations here.

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
