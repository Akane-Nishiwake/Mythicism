// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DamageTypes.generated.h"

UENUM(BlueprintType)
enum EDamageTypes
{
	HealthDamageType	UMETA(DisplayName = "Health"),
	StaminaDamageType	UMETA(DisplayName = "Stamina"),
	ManaDamageType		UMETA(DisplayName = "Mana"),
};

//To use as an property:
// UPROPERTY(BlueprintReadWrite, Category="SomeCategory")
// TEnumAsByte<EDamageTypes> damageType;