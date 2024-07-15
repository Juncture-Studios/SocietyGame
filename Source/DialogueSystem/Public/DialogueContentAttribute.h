// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DialogueContentAttribute.generated.h"

/*
 * NOTE: Only children of this class should be used.
 * Attributes can define whether a dialogue content is selected, fill in special characters in variations,
 * and perform other functionality for a dialogue content.
 * ContainsPhrase must be overriden to check if the attribute data contains the string for editor filter functionality.
 */
UCLASS(EditInlineNew, Abstract)
class DIALOGUESYSTEM_API UDialogueContentAttribute : public UObject
{
	GENERATED_BODY()

public:
	virtual bool ContainsPhrase(const FString Phrase) const;
};
