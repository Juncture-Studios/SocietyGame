// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "GameplayTagContainer.h"
#include "NpcInfoConditionDca.generated.h"

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

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
