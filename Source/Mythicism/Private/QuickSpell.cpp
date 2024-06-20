// Fill out your copyright notice in the Description page of Project Settings.

#include "QuickSpell.h"
#include "DamageableInterface.h"

// Sets default values
AQuickSpell::AQuickSpell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize hitCollider
	hitCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Hit Collider"));
	hitCollider->SetRelativeLocation(FVector(0, 0, 0));
	RootComponent = hitCollider;
	//hitCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	hitCollider->OnComponentHit.AddDynamic(this, &AQuickSpell::OnHitboxHit);
	
	// Initialize projectileMovement
	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	projectileMovement->UpdatedComponent = hitCollider;
	projectileMovement->bRotationFollowsVelocity = true;
	projectileMovement->ProjectileGravityScale = 0.0f;
	projectileMovement->Velocity = FVector(0, 0, 0);
}


void AQuickSpell::FireSpell(FVector direction)
{
	//hitCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	projectileMovement->ProjectileGravityScale = 0.0f;
	projectileMovement->Velocity = direction * projectileSpeed;
}

// Method to be subscribed to hitCollider's OnComponentHit event.
// This method calls DeliverCurse and OnSpellHit if the hit is a valid AMythicismCharacter,
// then Destroys the projectile.
void AQuickSpell::OnHitboxHit(UPrimitiveComponent* HitComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	FVector NormalImpulse,
	const FHitResult& Hit)
{
	if(destroyOnHit)
		hitCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Hit character
	AMythicismCharacter* curseReceiver = Cast<AMythicismCharacter>(OtherActor);
	if (curseReceiver && !curseReceiver->attributes->isInvincible)
	{
		OnSpellHit(curseReceiver);
		DeliverCurse(curseReceiver);
	}

	// Hit shield
	AShield* hitShield = Cast<AShield>(OtherActor);
	if (hitShield)
		OnSpellHitShield(hitShield);
	
	if (destroyOnHit)
		Destroy();
}