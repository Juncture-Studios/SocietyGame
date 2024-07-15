// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "GameplayTagContainer.h"
#include "FloatOutcomeDca.generated.h"

UENUM(BlueprintType)
enum class EFloatModifyMode : uint8
{
	Set,
	Sum,
	Multiply
};

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UFloatOutcomeDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FGameplayTag> Path;

	UPROPERTY(EditAnywhere)
	float Value;

	UPROPERTY(EditAnywhere)
	EFloatModifyMode Mode;

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
