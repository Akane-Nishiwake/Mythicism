// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableBase.h"

// Sets default values
AInteractableBase::AInteractableBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	playerInRange = false;
	used = false;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	root->SetupAttachment(RootComponent);
	root->SetRelativeLocation(FVector(0, 0, 0));


	radius = CreateDefaultSubobject<USphereComponent>(FName("SphereComponent"));
	radius->SetupAttachment(root);

	radius->OnComponentBeginOverlap.AddDynamic(this, &AInteractableBase::BeginOverlap);
	radius->OnComponentEndOverlap.AddDynamic(this, &AInteractableBase::EndOverlap);
}

// Called when the game starts or when spawned
void AInteractableBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInteractableBase::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult) {

	if (OtherActor->ActorHasTag(FName("Player"))) {
		playerInRange = true;
		if(prompt)
			prompt->SetVisibility(ESlateVisibility::HitTestInvisible);
	}

}

void AInteractableBase::EndOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex) {

	if (OtherActor->ActorHasTag(FName("Player"))) {
		playerInRange = false;
		if (prompt)
			prompt->SetVisibility(ESlateVisibility::Collapsed);
	}

}

// Called every frame
void AInteractableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AInteractableBase::InteractFunction() {

	if (!playerInRange)
		return false;
	used = true;
	return true;
}


