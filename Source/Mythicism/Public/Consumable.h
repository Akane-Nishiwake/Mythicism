// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Consumable.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EConsumableType : uint8 {
	 HealthPotion       UMETA(DisplayName = "HealthPotion"),
	 ManaPotion         UMETA(DisplayName = "ManaPotion"),
	 InstantFavor       UMETA(DisplayName = "InstantFavor"),
	 StaminaBoost       UMETA(DisplayName = "StaminaBoost"),
	 FavorGainBoost     UMETA(DisplayName = "FavorGainBoost"),
	 SpeedBoost         UMETA(DisplayName = "SpeedBoost"),
	 DefenseBoost       UMETA(DisplayName = "DefenseBoost"),
 };

UCLASS(EditInlineNew, DefaultToInstanced, BlueprintType, Blueprintable)
class MYTHICISM_API UConsumable : public UObject
{
	GENERATED_BODY()

public:

	UConsumable();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EConsumableType ConsumableType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 amount;

	
};
