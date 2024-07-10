// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTags.h"
#include "UObject/Object.h"
#include "NPCInfo.generated.h"

UCLASS(ClassGroup=(Custom), Blueprintable, EditInlineNew)
class UNPCInfoValue : public UObject
{
	GENERATED_BODY()

public:
	// "i.e. distance"
	UPROPERTY(EditAnywhere)
	FGameplayTag Descriptor;

	UNPCInfoValue();
};

/**
 * 
 */
UCLASS(ClassGroup=(Custom), Blueprintable, EditInlineNew)
class UNPCInfo : public UObject
{
	GENERATED_BODY()

	// Landmark information about the memory (i.e. "near the sea")
	UPROPERTY(EditAnywhere)
	FGameplayTag Tag;


	// Discernable information regarding the landmark ("i.e. distance:5km, weather:windy, suspicious:false"
	UPROPERTY(EditAnywhere, Instanced)
	TArray<UNPCInfoValue*> Values;

public:
	UNPCInfo();
};
