// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DialogueContentCatalog.generated.h"

class UDialogueContentAttribute;

/*
 * Conceptual content that is expressed by a character. The actual text is specified in a UDialogueVariation.
 */
USTRUCT()
struct FDialogueContent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FText Name;

	UPROPERTY(EditAnywhere, Instanced)
	TArray<UDialogueContentAttribute*> Attributes;
};

/**
 * Catalog of dialogue content that can be selected by an NPC, along their attributes. Attributes can define whether a
 * content is selected, fill in special characters in variations, and perform other functionality for the dialogue
 * content.
 */
UCLASS()
class DIALOGUESYSTEM_API UDialogueContentCatalog : public UObject
{
	GENERATED_BODY()

public:
	UDialogueContentCatalog();

	UPROPERTY(EditAnywhere)
	TArray<FDialogueContent> Content;

	UFUNCTION()
	void AddContent();

	UFUNCTION()
	void RemoveContent(const int Index);
};
