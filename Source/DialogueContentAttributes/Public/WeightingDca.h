// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "WeightingDca.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UWeightingDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	//Blueprint weighting function object here.

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
