// Fill out your copyright notice in the Description page of Project Settings.


#include "DummyActor.h"


// Sets default values
ADummyActor::ADummyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DummyObject = nullptr;
}

// Called when the game starts or when spawned
void ADummyActor::BeginPlay()
{
	Super::BeginPlay();
	DummyObject = NewObject<UDummyObject>(this, DummyObjectClass);
	AsyncTask(ENamedThreads::AnyHiPriThreadNormalTask, [this]()
	{
		/* Work on the TaskGraph */
		int Result;
		DummyObject->Addition(9, 10, Result);
		return Result;
		AsyncTask(ENamedThreads::GameThread, [this, Result]()
		{
			UE_LOG(LogTemp, Warning, TEXT("9+10=%d"), 21);
		});
	});
}

// Called every frame
void ADummyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
