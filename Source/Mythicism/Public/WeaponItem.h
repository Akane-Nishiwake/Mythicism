// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.h"
#include "WeaponItem.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, BlueprintType, Blueprintable)
class MYTHICISM_API UWeaponItem : public UItem
{

	GENERATED_BODY()

public:

	UWeaponItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
	TSubclassOf<AActor> WeaponActor;

	virtual FString ToString() override;

	
};
