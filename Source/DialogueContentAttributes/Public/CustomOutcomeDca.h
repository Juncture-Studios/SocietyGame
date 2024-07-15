// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "CustomOutcomeDca.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UCustomOutcomeDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	//Blueprint outcome function object here.

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
