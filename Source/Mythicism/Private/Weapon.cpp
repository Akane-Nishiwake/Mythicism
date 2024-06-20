// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include "DamageableInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AWeapon::AWeapon()
{
	// Create components
	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	root->SetupAttachment(RootComponent);
	root->SetRelativeLocation(FVector(0, 0, 0));
	
	hitCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Hit Collider"));
	hitCollider->SetupAttachment(root);
	hitCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetupAttachment(root);

	// Subscribe OnHitboxBeginOverlap method to hitbox's overlap event
	hitCollider->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::OnHitboxBeginOverlap);
}

// NOTE: 
// In order for this to work for some reason you have to add an "OnComponentBeginOverlap (hitBox)"
// to the event graph of the blueprint that uses this base class. I have absolutely no idea why...
//
void AWeapon::OnHitboxBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	IDamageableInterface* damageable = Cast<IDamageableInterface>(OtherActor);
	if (damageable)
	{
		PlayImpactSound();
		damageable->TakeDamage(attackDamage, EDamageTypes::HealthDamageType, this);
		OnWeaponHit(OtherActor);
	}
}

void AWeapon::EnableDealingDamage(float attackStrength)
{
	attackDamage = maxAttackDamage * attackStrength;
	if (hitCollider)
		hitCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	else
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, TEXT("No hit box"));
}

void AWeapon::DisableDealingDamage()
{
	if (hitCollider)
		hitCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

float AWeapon::upgradeDamage(float baseAtk, float atkPower)
{
	return baseAtk + atkPower;
}

void AWeapon::PlayLightSwingSound(int index)
{
	if (index < 0 || index > lightSwingSounds.Num())
		index = FMath::RandRange(0, lightSwingSounds.Num() - 1);

	if(lightSwingSounds.Num() > 0 && lightSwingSounds[index])
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), lightSwingSounds[index], GetActorLocation());
}

void AWeapon::PlayHeavySwingSound(int index)
{
	if (index < 0 || index > heavySwingSounds.Num())
		index = FMath::RandRange(0, heavySwingSounds.Num() - 1);

	if (heavySwingSounds.Num() > 0 && heavySwingSounds[index])
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), heavySwingSounds[index], GetActorLocation());
}

void AWeapon::PlayImpactSound(int index)
{
	if (index < 0 || index > impactSounds.Num())
		index = FMath::RandRange(0, impactSounds.Num() - 1);

	if (impactSounds.Num() > 0 && impactSounds[index])
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), impactSounds[index], GetActorLocation());
}

