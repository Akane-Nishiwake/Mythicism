// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WeaponAnimationSets.generated.h"

UENUM(BlueprintType)
enum EWeaponAnimationSets 
{
	SwordAnimationSet_Light		UMETA(DisplayName = "Sword (Light)"),
	SwordAnimationSet_Heavy		UMETA(DisplayName = "Sword (Heavy)"),
	HammerAnimationSet_Light	UMETA(DisplayName = "Hammer (Light)"),
	HammerAnimationSet_Heavy	UMETA(DisplayName = "Hammer (Heavy)"),
	AxeAnimationSet_Light	UMETA(DisplayName = "Axe (Light)"),
	AxeAnimationSet_Heavy	UMETA(DisplayName = "Axe (Heavy)"),
	SickleAnimationSet_Light	UMETA(DisplayName = "Sickle (Light)"),
	SickleAnimationSet_Heavy	UMETA(DisplayName = "Sickle (Heavy)"),
};

//To use as an property:
// UPROPERTY(BlueprintReadWrite, Category="SomeCategory")
// TEnumAsByte<EWeaponAnimationSets> animationSet;