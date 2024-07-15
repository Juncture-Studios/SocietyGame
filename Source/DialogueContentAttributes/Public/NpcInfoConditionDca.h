// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "GameplayTagContainer.h"
#include "NpcInfoConditionDca.generated.h"

class UInfoNode;
enum class EDialogueConditionType : uint8;

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UNpcInfoConditionDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FGameplayTag> Path;

	UPROPERTY(EditAnywhere)
	EDialogueConditionType ConditionType;

	//Only checks for path validity if false.
	UPROPERTY(EditAnywhere)
	bool bCheckValue;

	//If bCheckValue is true, the node specified must be the same type and have the same value
	//for the condition to be true.
	UPROPERTY(EditAnywhere, Instanced)
	UInfoNode* ComparedValue;

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
