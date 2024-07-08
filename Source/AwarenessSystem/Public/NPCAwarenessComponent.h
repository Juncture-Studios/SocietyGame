// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTags.h"
#include "Components/ActorComponent.h"
#include "NPCAwarenessComponent.generated.h"

UCLASS(ClassGroup=(Custom), Blueprintable)
class UNPCInfoValue : public UObject
{
	GENERATED_BODY()

public:

	UNPCInfoValue() = default;
	
};

UCLASS(ClassGroup=(Custom), Blueprintable)
class UNPCInfoFloatValue : public UNPCInfoValue
{
	GENERATED_BODY()

public:
	UNPCInfoFloatValue();

	// "i.e. distance"
	UPROPERTY(EditAnywhere)
	FGameplayTag Descriptor;

	// "i.e. 5 units"
	UPROPERTY(EditAnywhere)
	float Value;
	
};

UCLASS(ClassGroup=(Custom), Blueprintable)
class UNPCInfo : public UObject
{
	GENERATED_BODY()

	// Landmark information about the memory (i.e. "near the sea")
	UPROPERTY()
	FGameplayTag Tag;

	
	// Discernable information regarding the landmark ("i.e. distance:5km, weather:windy, suspicious:false"
	UPROPERTY(EditAnywhere)
	TArray<UNPCInfoValue*> Values;
	
public:

	UNPCInfo();
	
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class AWARENESSSYSTEM_API UNPCAwarenessComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UNPCAwarenessComponent();
	
	UPROPERTY(EditAnywhere)
	TArray<UNPCInfo*> Context;

	UPROPERTY(EditAnywhere)
	TArray<UNPCInfo*> Memory;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
