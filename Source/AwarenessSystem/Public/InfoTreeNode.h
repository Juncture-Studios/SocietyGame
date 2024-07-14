// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InfoNode.h"
#include "Containers/Deque.h"
#include "UObject/Object.h"
#include "InfoTreeNode.generated.h"

/**
 * 
 */
UCLASS()
class AWARENESSSYSTEM_API UInfoTreeNode : public UInfoNode
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<FGameplayTag, UInfoNode*> Children;

	void AddChildrenRecursively(TArray<UInfoNode*>& OutResult) const;

	UInfoNode* FindNodeRecursively(TDeque<FGameplayTag>& InTags, const bool InExact) const;

public:
	
	UFUNCTION(BlueprintCallable)
	TArray<UInfoNode*> GetAllChildren() const;

	UFUNCTION(BlueprintCallable)
	UInfoNode* CreateAndAttachNode(const TSubclassOf<UInfoNode>& InSubclass);

	UFUNCTION(BlueprintCallable)
	UInfoNode* FindNode(const FGameplayTag InTag) const;

	UFUNCTION(BlueprintCallable)
	UInfoNode* FindNodeAt(const TArray<FGameplayTag>& InTags) const;

	UFUNCTION(BlueprintCallable)
	bool ContainsNode(const FGameplayTag InTag, const bool InExact) const;

	UFUNCTION(BlueprintCallable)
	bool ContainsNodeAt(const TArray<FGameplayTag>& InTags, const bool InExact) const;

	UFUNCTION(BlueprintCallable)
	void RemoveNode(const FGameplayTag InTag);

	UFUNCTION(BlueprintCallable)
	void Clear();
};
