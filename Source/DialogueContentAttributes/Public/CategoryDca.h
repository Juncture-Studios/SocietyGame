// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "GameplayTagContainer.h"
#include "CategoryDca.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UCategoryDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FGameplayTag Category;

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
