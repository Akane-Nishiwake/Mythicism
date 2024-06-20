// Fill out your copyright notice in the Description page of Project Settings.


#include "TrapSpell.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ATrapSpell::ATrapSpell()
{
	// Create components
	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	root->SetupAttachment(RootComponent);
	root->SetRelativeLocation(FVector(0, 0, 0));
	
	hitCollider = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hit Collider"));
	hitCollider->SetupAttachment(root);
	hitCollider->SetCollisionProfileName(TEXT("PlayerTrapSpell"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Game/Geometry/StarterContent/Shape_Cylinder.Shape_Cylinder"));
	if (CylinderAsset.Succeeded())
	{
		hitCollider->SetStaticMesh(CylinderAsset.Object);
		hitCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}

	// Subscribe OnHitboxBeginOverlap method to hitbox's overlap event
	hitCollider->OnComponentBeginOverlap.AddDynamic(this, &ATrapSpell::OnHitboxBeginOverlap);
}


// Method to be subscribed to a hitBox's OnComponentBeginOverlap event.
// This method calls DeliverCurse and OnSpellHit if the hit is a valid AMythicismCharacter.
void ATrapSpell::OnHitboxBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	// Hit Character
	AMythicismCharacter* curseReceiver = Cast<AMythicismCharacter>(OtherActor);
	if (curseReceiver && !curseReceiver->attributes->isInvincible)
	{
		OnSpellHit(curseReceiver);
		DeliverCurse(curseReceiver);
	}
}

