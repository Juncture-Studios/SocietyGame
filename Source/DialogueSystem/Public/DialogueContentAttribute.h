// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DialogueContentAttribute.generated.h"

/*
 * NOTE: Only children of this class should be used.
 * Attributes can define whether a dialogue content is selected, fill in special characters in variations,
 * and perform other functionality for a dialogue content.
 */
UCLASS(EditInlineNew)
class DIALOGUESYSTEM_API UDialogueContentAttribute : public UObject
{
	GENERATED_BODY()
};
