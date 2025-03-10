﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "GameplayTagContainer.h"
#include "TagOutcomeDca.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UTagOutcomeDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FGameplayTag> Path;

	//If true will fill in the entire path if it is not valid.
	UPROPERTY(EditAnywhere)
	bool bCreateIfNotExist;

	UPROPERTY(EditAnywhere)
	FGameplayTag Value;

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
