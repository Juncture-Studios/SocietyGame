// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTags.h"
#include "UObject/Object.h"
#include "InfoNode.generated.h"

UCLASS(ClassGroup=(Custom), Blueprintable, EditInlineNew, BlueprintType)
class UInfoNode : public UObject
{
	GENERATED_BODY()

public:
	// "i.e. distance"
	UPROPERTY(EditAnywhere)
	FGameplayTag Descriptor;

	UInfoNode();
};