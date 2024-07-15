// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "PriorityDca.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UPriorityDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 Priority;

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
