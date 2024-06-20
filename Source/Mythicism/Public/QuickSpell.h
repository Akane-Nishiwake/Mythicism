// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "Shield.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "QuickSpell.generated.h"

UCLASS()
class MYTHICISM_API AQuickSpell : public ASpell
{
	GENERATED_BODY()
	
// Properties
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell Attributes")
	class USphereComponent* hitCollider;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell Attributes")
	UProjectileMovementComponent* projectileMovement;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell Attributes")
	float projectileSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell Attributes")
	bool destroyOnHit;

// Behaviors
public:	
	// Sets default values for this actor's properties
	AQuickSpell();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSpellHitShield(AShield* curseReceiver);

	// Method to be subscribed to hitCollider's OnComponentHit event.
	// This method calls DeliverCurse and OnSpellHit if the hit is a valid AMythicismCharacter,
	// and calls DestroySpell otherwise.
	UFUNCTION()
	void OnHitboxHit(UPrimitiveComponent* HitComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit);

	UFUNCTION(BlueprintCallable)
	void FireSpell(FVector direction);
};
