// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Curse.h"
#include "Spell.generated.h"

UCLASS()
class MYTHICISM_API ASpell : public AActor
{
	GENERATED_BODY()


// Properties
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell Attributes")
	AMythicismCharacter* spellCaster;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell Attributes")
	TSubclassOf<ACurse> curseClass;

// Behaviors
public:	
	// Sets default values for this actor's properties
	ASpell();

protected:
	// Blueprint event called when the spell has made contact with an AMythicisimCharacter.
	// This can be used for things like dealing an initial damage before delivering a curse
	UFUNCTION(BlueprintImplementableEvent)
	void OnSpellHit(AMythicismCharacter* curseReceiver);

	// Delvers curse to a target
	void DeliverCurse(AMythicismCharacter* curseReceiver);
};
