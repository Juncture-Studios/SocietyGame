// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "GameplayTagContainer.h"
#include "BoolOutcomeDca.generated.h"

UENUM(BlueprintType)
enum class EBoolModifyMode : uint8
{
	Set,
	Invert
};

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UBoolOutcomeDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FGameplayTag> Path;

	//If true will fill in the entire path if it is not valid and the mode is set.
	UPROPERTY(EditAnywhere)
	bool bCreateIfNotExist;

	UPROPERTY(EditAnywhere)
	bool bValue;

	UPROPERTY(EditAnywhere)
	EBoolModifyMode Mode;

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
