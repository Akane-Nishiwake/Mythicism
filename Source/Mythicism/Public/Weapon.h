// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "WeaponAnimationSets.h"
#include "Sound/SoundBase.h"
#include "Weapon.generated.h"

UCLASS()
class MYTHICISM_API AWeapon : public AActor
{
	GENERATED_BODY()
	
// Properties
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	USceneComponent* root;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	class UCapsuleComponent* hitCollider;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Attributes")
	UStaticMeshComponent* mesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	TArray<USoundBase*> lightSwingSounds;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	TArray<USoundBase*> heavySwingSounds;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	TArray<USoundBase*> impactSounds;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	USoundBase* slamSound;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	float maxAttackDamage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	float attackDamage;
	
	/////////// DEPRECIATED ///////////
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	float usageCost;
	///////////////////////////////////

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	float lightAttackStaminaCost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	float heavyAttackStaminaCost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	float weight;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	int maxLightCombo;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	int maxHeavyCombo;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	TEnumAsByte<EWeaponAnimationSets> lightAttackAnimSet;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	TEnumAsByte<EWeaponAnimationSets> heavyAttackAnimSet;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	int TypeID;


	//////////////////////////DEPRECIATED////////////////////////////////////
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	UAnimMontage* attack1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	UAnimMontage* attack2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Attributes")
	UAnimMontage* attack3;
	//////////////////////////////////////////////////////////////////////////


// Behaviors
public:	
	// Sets default values for this actor's properties
	AWeapon();
	
	// Method that subscribes to hitBox's OnComponentBeginOverlap event
	UFUNCTION()
	void OnHitboxBeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent, Category = "Weapon")
	void OnWeaponHit(AActor* hitReceiver);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void EnableDealingDamage(float attackStrength = 1.0f); //attackStrength is the percentage of maxAttackDamage to use for this attack

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void DisableDealingDamage();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	float upgradeDamage(float baseAtk, float atkPower);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void PlayLightSwingSound(int index = -1);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void PlayHeavySwingSound(int index = -1);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void PlayImpactSound(int index = -1);
};
