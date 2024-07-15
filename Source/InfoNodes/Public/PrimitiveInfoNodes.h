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
class INFONODES_API UFloatInfoNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UFloatInfoNode();

	// "i.e. 5 units"
	UPROPERTY(EditAnywhere)
	float Value;
};

UCLASS()
class INFONODES_API UFloatArrayNode : public UInfoNode
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
class INFONODES_API UIntInfoNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UIntInfoNode();

	UPROPERTY(EditAnywhere)
	int32 Value;
};

UCLASS()
class INFONODES_API UIntArrayNode : public UInfoNode
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
class INFONODES_API UBoolNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UBoolNode();

	UPROPERTY(EditAnywhere)
	bool Value;
};

UCLASS()
class INFONODES_API UBoolArrayNode : public UInfoNode
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
class INFONODES_API UStringNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UStringNode();

	UPROPERTY(EditAnywhere)
	FString Value;
};

UCLASS()
class INFONODES_API UStringArrayNode : public UInfoNode
{
	GENERATED_BODY()

public:
	UStringArrayNode();

	UPROPERTY()
	TArray<FString> Value;
};
