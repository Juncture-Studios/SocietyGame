// Fill out your copyright notice in the Description page of Project Settings.


#include "DummyObject.h"
void UDummyObject::Sleep(const int InSeconds) const
{
	FPlatformProcess::Sleep(InSeconds);
}
