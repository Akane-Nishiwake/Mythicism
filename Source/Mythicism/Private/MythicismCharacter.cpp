// Fill out your copyright notice in the Description page of Project Settings.


#include "MythicismCharacter.h"
#include "Curse.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AMythicismCharacter::AMythicismCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	attributes = CreateDefaultSubobject<UCharacterAttributesComponent>(TEXT("Character Attributes"));
	
	weaponHand = CreateDefaultSubobject<UChildActorComponent>(TEXT("Weapon Hand"));
	weaponHand->SetupAttachment(GetMesh(), "weaponSocket"); //WARNING: This will cause problems if the socket name on UE4_Mannequin_Skeleton is changed OR if UE4_Mannequin_Skeleton is not used and there is no corresponding socket on the alternative skeleton used
	
	shieldHand = CreateDefaultSubobject<UChildActorComponent>(TEXT("Shield Hand"));
	shieldHand->SetupAttachment(GetMesh(), "shieldSocket"); //WARNING: This will cause problems if the socket name on UE4_Mannequin_Skeleton is changed OR if UE4_Mannequin_Skeleton is not used and there is no corresponding socket on the alternative skeleton used
}

// Called when the game starts or when spawned
void AMythicismCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMythicismCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMythicismCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// IDamageableInterface override for taking damage
void AMythicismCharacter::TakeDamage(float amount, TEnumAsByte<EDamageTypes> damageType, AActor* damager)
{
	if (attributes->godMode)
		return;
	
	// Disable incomoing weapon if blocking
	AWeapon* weapon = Cast<AWeapon>(damager);
	if (isBlocking && weapon)
		weapon->DisableDealingDamage();

	switch (damageType)
	{
		case EDamageTypes::HealthDamageType:
			// If not invincible
			if (!attributes->isInvincible)
			{
				amount -= attributes->attackDefense;
				attributes->health = FMath::Clamp<float>(attributes->health - amount, 0, attributes->maxHealth);
			}
			else
				return;
			break;

		case EDamageTypes::StaminaDamageType:
			attributes->stamina = FMath::Clamp<float>(attributes->stamina - amount, 0, attributes->maxStamina);
			break;

		case EDamageTypes::ManaDamageType:
			attributes->mana = FMath::Clamp<float>(attributes->mana - amount, 0, attributes->maxMana);
			break;
	}

	if (attributes->health == 0)
		Die();
	else
		OnTakeDamage(amount, damageType);
}

// IDamageableInterface override for healing
void AMythicismCharacter::Heal(float amount, TEnumAsByte<EDamageTypes> healType)
{
	switch (healType)
	{
		case EDamageTypes::HealthDamageType:
			attributes->health = FMath::Clamp<float>(attributes->health + amount, 0, attributes->maxHealth);
			break;
		case EDamageTypes::StaminaDamageType:
			attributes->stamina = FMath::Clamp<float>(attributes->stamina + amount, 0, attributes->maxStamina);
			break;
		case EDamageTypes::ManaDamageType:
			attributes->mana = FMath::Clamp<float>(attributes->mana + amount, 0, attributes->maxMana);
			break;
	}

	OnHeal(amount, healType);
}

// Returns a pointer to the currently equipped weapon (null if couldn't be found)
void AMythicismCharacter::Die()
{
	RemoveAllCurses();
	OnDie(); 
}

void AMythicismCharacter::RemoveAllCurses()
{
	TArray<AActor*> attachedActors;
	GetAttachedActors(attachedActors);
	for (auto& child : attachedActors)
	{
		ACurse* activeCurse = Cast<ACurse>(child);
		if (activeCurse)
			activeCurse->RemoveCurse();
	}
}


// Returns a pointer to the currently equipped weapon (null if couldn't be found)
const AWeapon* AMythicismCharacter::GetCurrentWeapon()
{
	return Cast<AWeapon>(weaponHand->GetChildActor());
}

// Sets the current weapon, removing the old one
void AMythicismCharacter::SetCurrentWeapon(TSubclassOf<AActor> weaponClass)
{
	if (weaponClass)
		OnArmed();
	else
		OnDisarmed();

	weaponHand->SetChildActorClass(weaponClass);
}
