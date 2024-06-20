// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "Components/StaticMeshComponent.h"
#include "TrapSpell.generated.h"

UCLASS()
class MYTHICISM_API ATrapSpell : public ASpell
{
	GENERATED_BODY()

// Properties
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell Attributes")
	USceneComponent* root;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell Attributes")
	class UStaticMeshComponent* hitCollider;

// Behaviors
public:	
	// Sets default values for this actor's properties
	ATrapSpell();

	// Method to be subscribed to a hitBox's OnComponentBeginOverlap event.
	// This method calls DeliverCurse and OnSpellHit if the hit is a valid AMythicismCharacter,
	// and calls DestroySpell otherwise.
	UFUNCTION()
	void OnHitboxBeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};
