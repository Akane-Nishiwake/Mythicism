// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageableInterface.h"
#include "Components/BoxComponent.h"
#include "MythicismCharacter.h"
#include "Shield.generated.h"

UCLASS()
class MYTHICISM_API AShield : public AActor, public IDamageableInterface
{
	GENERATED_BODY()
	
// Properties
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	USceneComponent* root;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	UBoxComponent* hitCollider;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	UStaticMeshComponent* mesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Shield")
	float blockEfficiency;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Shield")
	AMythicismCharacter* shieldOwner;

// Behaviors
public:	
	// Sets default values for this actor's properties
	AShield();

	// IDamageableInterface override for taking damage
	UFUNCTION(BlueprintCallable)
	virtual void TakeDamage(float amount, TEnumAsByte<EDamageTypes> damageType, AActor* damager = nullptr) override;

	// Event called when take damage occurs. Intended for adding splinter particles/sounds/effects related to shield getting hit
	UFUNCTION(BlueprintImplementableEvent)
	void OnShieldHit();

	// IDamageableInterface override for healing
	UFUNCTION(BlueprintCallable)
	virtual void Heal(float amount, TEnumAsByte<EDamageTypes> healType) override;

	// Enable blocking
	UFUNCTION(BlueprintCallable)
	void EnableBlocking(AMythicismCharacter* _shieldOwner);

	// Disable blocking
	UFUNCTION(BlueprintCallable)
	void DisableBlocking();
};
