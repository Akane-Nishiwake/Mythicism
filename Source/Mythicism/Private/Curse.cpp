// Fill out your copyright notice in the Description page of Project Settings.


#include "Curse.h"

// Sets default values
ACurse::ACurse()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACurse::BeginPlay()
{
	Super::BeginPlay();
}


void ACurse::BeginCurse()
{
	if (!curseReceiver)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Purple, TEXT("Could not begin curse: curseReceiver = nullptr"));
		return;
	}

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Purple, TEXT("Curse added"));

	curseStartTime = GetWorld()->GetTimeSeconds();
	Curse();
}

// Called every frame
void ACurse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}