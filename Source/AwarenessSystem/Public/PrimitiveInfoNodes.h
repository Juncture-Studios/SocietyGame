// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InfoNode.h"
#include "UObject/Object.h"
#include "PrimitiveInfoNodes.generated.h"


/**
 * 
 */
UCLASS()
class UFloatInfoNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UFloatInfoNode();

	// "i.e. 5 units"
	UPROPERTY(EditAnywhere)
	float Value;
};

UCLASS()
class UFloatArrayNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UFloatArrayNode();

	UPROPERTY()
	TArray<float> Value;
};

/**
 * 
 */
UCLASS()
class UIntInfoNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UIntInfoNode();

	UPROPERTY(EditAnywhere)
	int32 Value;
};

UCLASS()
class UIntArrayNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UIntArrayNode();

	UPROPERTY()
	TArray<int32> Value;
};

/**
 * 
 */
UCLASS()
class UBoolNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UBoolNode();

	UPROPERTY(EditAnywhere)
	bool Value;
};

UCLASS()
class UBoolArrayNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UBoolArrayNode();

	UPROPERTY()
	TArray<bool> Value;
};

/**
 * 
 */
UCLASS()
class UStringNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UStringNode();

	UPROPERTY(EditAnywhere)
	FString Value;
};

UCLASS()
class UStringArrayNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UStringArrayNode();

	UPROPERTY()
	TArray<FString> Value;
};
