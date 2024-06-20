// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "KeyItem.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, BlueprintType, Blueprintable)
class MYTHICISM_API UKeyItem : public UItem
{
	GENERATED_BODY()
public:

	UKeyItem();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	FText keyCode;

	virtual FString ToString() override;
	
};
