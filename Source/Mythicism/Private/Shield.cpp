// Fill out your copyright notice in the Description page of Project Settings.

#include "Shield.h"
#include "Weapon.h"


// Sets default values
AShield::AShield()
{
	// Create components
	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	root->SetupAttachment(RootComponent);
	root->SetRelativeLocation(FVector(0, 0, 0));

	hitCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Hit Collider"));
	hitCollider->SetupAttachment(root);
	hitCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	mesh->SetupAttachment(root);
}

// IDamageableInterface override for taking damage
void AShield::TakeDamage(float amount, TEnumAsByte<EDamageTypes> damageType, AActor* damager)
{
	if (!shieldOwner)
		return;

	// Play effects/sounds
	OnShieldHit();

	// Disable weapon
	AWeapon* weapon = Cast<AWeapon>(damager);
	if (weapon)
		weapon->DisableDealingDamage();
	
	// Calculate damage amounts
	float healthAmount = amount * (1 - blockEfficiency);
	float staminaAmount = amount * blockEfficiency;
		
	// Take stamina damage
	shieldOwner->TakeDamage(staminaAmount, EDamageTypes::StaminaDamageType);

	// Take health damage
	if(staminaAmount > shieldOwner->attributes->stamina)
		shieldOwner->TakeDamage(healthAmount + (staminaAmount - shieldOwner->attributes->stamina), EDamageTypes::HealthDamageType);
	else
		shieldOwner->TakeDamage(healthAmount, EDamageTypes::HealthDamageType);
}


// IDamageableInterface override for healing
void AShield::Heal(float amount, TEnumAsByte<EDamageTypes> healType)
{

}


void AShield::EnableBlocking(AMythicismCharacter* _shieldOwner)
{
	shieldOwner = _shieldOwner;
	
	if (hitCollider)
		hitCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	else
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, TEXT("No hit box"));
}

void AShield::DisableBlocking()
{
	if (hitCollider)
		hitCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
