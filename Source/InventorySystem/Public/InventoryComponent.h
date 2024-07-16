// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UInventoryItem;

USTRUCT()
struct FInventoryGroup
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FGameplayTag InventoryGroupTag;

	UPROPERTY(EditAnywhere)
	uint16 NumSlots;

	UPROPERTY()
	TArray<UInventoryItem*> Items;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INVENTORYSYSTEM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY()
	TArray<FInventoryGroup> InventoryGroups;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
