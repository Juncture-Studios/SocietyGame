// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "GameplayTagContainer.h"
#include "IntConditionDca.generated.h"

enum class EDialogueNumericalComparator : uint8;
enum class EDialogueConditionType : uint8;
/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UIntConditionDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FGameplayTag> Path;
	
	UPROPERTY(EditAnywhere)
	int32 Value;

	//True if given value is <comparator> path value.
	UPROPERTY(EditAnywhere)
	EDialogueNumericalComparator Comparator;

	UPROPERTY(EditAnywhere)
	EDialogueConditionType ConditionType;

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
