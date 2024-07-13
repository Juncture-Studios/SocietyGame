// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DummyObject.h"
#include "GameFramework/Actor.h"
#include "DummyActor.generated.h"

UCLASS()
class AWARENESSSYSTEM_API ADummyActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ADummyActor();

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDummyObject> DummyObjectClass;

	UPROPERTY()
	UDummyObject* DummyObject;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
