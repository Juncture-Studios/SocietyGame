// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTags.h"
#include "UObject/Object.h"
#include "InfoNode.generated.h"

UCLASS(ClassGroup=(Custom), Blueprintable, EditInlineNew, BlueprintType, Abstract)
class INFONODES_API UInfoNode : public UObject
{
	GENERATED_BODY()

public:
	// "i.e. distance"
	//Intentionally not editable in editor as the editor uses paths.
	FGameplayTag Descriptor;
	
	virtual bool HasSameTypeAndValue(const UInfoNode* Node) const;

	UFUNCTION(BlueprintImplementableEvent)
	bool BP_HasSameTypeAndValue(const UInfoNode* Node) const;

	UInfoNode();
};