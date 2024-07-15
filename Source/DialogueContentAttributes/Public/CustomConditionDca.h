// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "CustomConditionDca.generated.h"

enum class EDialogueConditionType : uint8;

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UCustomConditionDca : public UDialogueContentAttribute
{
	GENERATED_BODY()
	
	//Blueprint predicate object here.
	
	UPROPERTY(EditAnywhere)
	EDialogueConditionType ConditionType;

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
