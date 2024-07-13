// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DummyObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AWARENESSSYSTEM_API UDummyObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void Addition(const int InA, const int InB, int& OutC) const;

	UFUNCTION(BlueprintCallable)
	void Sleep(const int InSeconds) const;
};
