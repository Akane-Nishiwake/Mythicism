// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DamageableInterface.h"
#include "CharacterAttributesComponent.h"
#include "Weapon.h"
#include "MythicismCharacter.generated.h"

UCLASS()
class MYTHICISM_API AMythicismCharacter : public ACharacter, public IDamageableInterface
{
	GENERATED_BODY()

// Properties
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Combat")
	bool isBlocking;

	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	bool isArmed = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mythicism Character")
	UCharacterAttributesComponent* attributes;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mythicism Character")
	UChildActorComponent* weaponHand;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mythicism Character")
	UChildActorComponent* shieldHand;

// Behaviors
public:	
	// Sets default values for this character's properties
	AMythicismCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// IDamageableInterface override for taking damage
	UFUNCTION(BlueprintCallable)
	virtual void TakeDamage(float amount, TEnumAsByte<EDamageTypes> damageType, AActor* damager = nullptr) override;

	// IDamageableInterface override for healing
	UFUNCTION(BlueprintCallable)
	virtual void Heal(float amount, TEnumAsByte<EDamageTypes> healType) override;

	// Returns a pointer to the currently equipped weapon (null if couldn't be found)
	UFUNCTION(BlueprintPure)
	const AWeapon* GetCurrentWeapon();

	// Sets the current weapon, removing the old one
	UFUNCTION(BlueprintCallable)
	void SetCurrentWeapon(TSubclassOf<AActor> weaponClass);

	// Removes any active curses on this character
	UFUNCTION(BlueprintCallable)
	void RemoveAllCurses();

	// Blueprint event called when a weapon is added to the player's hand
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnArmed();

	// Blueprin event called when a weapon is removed from the player's hand
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDisarmed();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Blueprint event called by at the end of TakeDamage death doesn't occur.
	// Intended for any effects/sounds/etc, while TakeDamage is intended
	// for the actual calculation and altering of player stats. 
	UFUNCTION(BlueprintImplementableEvent, Category = "Damageable")
	void OnTakeDamage(float amount, const TEnumAsByte<EDamageTypes>& damageType);

	// Blueprint event called by at the end of Heal.
	// Intended for any effects/sounds/etc
	//  while Heal is intended for the actual calculation and altering of player stats. 
	UFUNCTION(BlueprintImplementableEvent, Category = "Damageable")
	void OnHeal(float amount, const TEnumAsByte<EDamageTypes>& healType);

	// Called by TakeDamage when health reaches 0
	void Die();

	// Blueprint event called at the end of Die
	UFUNCTION(BlueprintImplementableEvent)
	void OnDie();

	// Blueprint event for staggering
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnStagger();
};
