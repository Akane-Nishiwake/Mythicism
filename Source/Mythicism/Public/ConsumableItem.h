// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Consumable.h"
#include "ConsumableItem.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, BlueprintType, Blueprintable)
class MYTHICISM_API UConsumableItem : public UItem
{
	GENERATED_BODY()

public:
	UConsumableItem();


	UPROPERTY(EditInstanceOnly, Instanced, BlueprintReadOnly, BlueprintType, Category = "Consumable")
		UConsumable* ConsumableData;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Consumable")
		int32 Count;

		// Only used for mana and health potions
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Consumable")
		int32 MaxCount;

		virtual FString ToString() override;
	
};
