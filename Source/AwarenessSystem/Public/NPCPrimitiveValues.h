// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPCInfo.h"
#include "UObject/Object.h"
#include "NPCPrimitiveValues.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), Blueprintable, EditInlineNew)
class UNPCInfoFloatValue : public UNPCInfoValue
{
	GENERATED_BODY()

public:
	UNPCInfoFloatValue();

	// "i.e. 5 units"
	UPROPERTY(EditAnywhere)
	float Value;
	
};
