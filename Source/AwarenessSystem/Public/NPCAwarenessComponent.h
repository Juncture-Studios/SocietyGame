﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InfoTreeNode.h"
#include "Components/ActorComponent.h"
#include "NPCAwarenessComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class AWARENESSSYSTEM_API UNPCAwarenessComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UNPCAwarenessComponent();
	
	UPROPERTY(EditAnywhere, Instanced)
	UInfoTreeNode* Context;

	UPROPERTY(EditAnywhere, Instanced)
	UInfoTreeNode* Memory;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
