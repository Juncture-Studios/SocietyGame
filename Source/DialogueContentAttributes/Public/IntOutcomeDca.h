// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "GameplayTagContainer.h"
#include "IntOutcomeDca.generated.h"

UENUM(BlueprintType)
enum class EIntModifyMode : uint8
{
	Set,
	Sum,
	Multiply
};

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UIntOutcomeDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FGameplayTag> Path;

	UPROPERTY(EditAnywhere)
	int32 Value;

	UPROPERTY(EditAnywhere)
	EIntModifyMode Mode;

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
