// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DialogueContentAttributeSelector.generated.h"

class UDialogueContentAttribute;

UCLASS()
class DIALOGUEEDITOR_API UDialogueContentAttributeSelector : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UDialogueContentAttribute> Attribute;
};
