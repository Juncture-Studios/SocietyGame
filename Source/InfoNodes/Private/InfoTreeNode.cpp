// Fill out your copyright notice in the Description page of Project Settings.


#include "InfoTreeNode.h"

#include "Containers/Deque.h"

void UInfoTreeNode::AddChildrenRecursively(TArray<UInfoNode*>& OutResult) const
{
	for (const auto& ChildPair : Children)
	{
		UInfoNode* Child = ChildPair.Value;
		if (Child == nullptr)
		{
			return;
		}
		if (const UInfoTreeNode* ChildNode = Cast<UInfoTreeNode>(Child))
		{
			ChildNode->AddChildrenRecursively(OutResult);
		}
		else
		{
			OutResult.Emplace(Child);
		}
	}
}

UInfoNode* UInfoTreeNode::FindNodeRecursively(TDeque<FGameplayTag>& InTags, const bool InExact) const
{
	FGameplayTag Next;
	if (!InTags.TryPopFirst(Next) || !Children.Contains(Next))
	{
		return nullptr;
	}
	UInfoNode* Child = Children[Next];
	// Check exact or check using matches tag
	if ((InExact && Child->Descriptor != Next) || !Child->Descriptor.MatchesTag(Next))
	{
		return nullptr;
	}
	
	if (InTags.IsEmpty())
	{
		return Child;
	}
	if (const UInfoTreeNode* ChildTreeNode = Cast<UInfoTreeNode>(Child))
	{
		return ChildTreeNode->FindNodeRecursively(InTags, InExact);
	}
	// There are more tags than there are nodes to check
	return nullptr;
}


TArray<UInfoNode*> UInfoTreeNode::GetAllChildren() const
{
	TArray<UInfoNode*> Nodes;
	AddChildrenRecursively(Nodes);
	return Nodes;
}

UInfoNode* UInfoTreeNode::CreateAndAttachNode(const TSubclassOf<UInfoNode>& InSubclass)
{
	UInfoNode* NodeCopy = NewObject<UInfoNode>(this, InSubclass);

	if (Children.Contains(NodeCopy->Descriptor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempted to create a node with an existing tag: %s"),
		       *NodeCopy->Descriptor.ToString());
		return nullptr;
	}
	Children.Add(NodeCopy->Descriptor, NodeCopy);
	return NodeCopy;
}

UInfoNode* UInfoTreeNode::FindNode(const FGameplayTag InTag) const
{
	if (Children.Contains(InTag))
	{
		return Children[InTag];
	}
	return nullptr;
}

UInfoNode* UInfoTreeNode::FindNodeAt(const TArray<FGameplayTag>& InTags) const
{
	if (InTags.IsEmpty())
	{
		return nullptr;
	}
	TDeque<FGameplayTag> Tags;
	for (const auto& Elem : InTags)
	{
		Tags.PushLast(Elem);
	}
	return FindNodeRecursively(Tags, true);
}

bool UInfoTreeNode::ContainsNode(const FGameplayTag InTag, const bool InExact) const
{
	if (InExact)
	{
		return FindNode(InTag) != nullptr;
	}
	if (Descriptor.MatchesTag(InTag))
	{
		return true;
	}
	return false;
}

bool UInfoTreeNode::ContainsNodeAt(const TArray<FGameplayTag>& InTags, const bool InExact) const
{
	if (InTags.IsEmpty())
	{
		return false;
	}
	TDeque<FGameplayTag> Tags;
	for (const auto& Elem : InTags)
	{
		Tags.PushLast(Elem);
	}
	return FindNodeRecursively(Tags, InExact) != nullptr;
}

void UInfoTreeNode::RemoveNode(const FGameplayTag InTag)
{
	Children.Remove(InTag);
}

void UInfoTreeNode::Clear()
{
	Children.Empty();
}
