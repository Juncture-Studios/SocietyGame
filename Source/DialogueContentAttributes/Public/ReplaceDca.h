// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "ReplaceDca.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UReplaceDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	//Make pairs of string returning blueprint objects and string characters.
	
	virtual bool ContainsPhrase(const FString Phrase) const override;
};
