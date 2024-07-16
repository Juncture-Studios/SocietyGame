// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "InventoryOutcomeDca.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UInventoryOutcomeDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
