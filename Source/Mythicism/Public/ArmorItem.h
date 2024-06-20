// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "ArmorItem.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, BlueprintType, Blueprintable)
class MYTHICISM_API UArmorItem : public UItem
{
	GENERATED_BODY()

public:

	UArmorItem();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
		TSubclassOf<AActor> ArmorActor;

	virtual FString ToString() override;
	
};
