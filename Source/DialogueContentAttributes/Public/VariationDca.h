// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueContentAttribute.h"
#include "GameplayTagContainer.h"
#include "VariationDca.generated.h"

USTRUCT(BlueprintType)
struct FVariation
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FText Text;

	//Character must have at least one of these.
	UPROPERTY(EditAnywhere)
	TArray<FGameplayTag> VariationTags;

	UPROPERTY(EditAnywhere)
	int32 Priority;

	UPROPERTY(EditAnywhere)
	float Weighting;
};

/**
 * 
 */
UCLASS()
class DIALOGUECONTENTATTRIBUTES_API UVariationDca : public UDialogueContentAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FVariation> Variations;

	virtual bool ContainsPhrase(const FString Phrase) const override;
};
