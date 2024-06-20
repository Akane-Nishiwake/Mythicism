// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractableBase.h"
#include "Item.h"
#include "Engine/World.h"
#include "UObject/UObjectGlobals.h"
#include "ItemPickup.generated.h"

UCLASS()
class MYTHICISM_API AItemPickup : public AInteractableBase
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AItemPickup();


	UPROPERTY(EditInstanceOnly, Instanced, BlueprintReadOnly, BlueprintType, Category = "Item")
	UItem* ItemData;

	UFUNCTION(BlueprintCallable, Category = "Interactive")
	virtual bool InteractFunction() override;

	UFUNCTION(BlueprintCallable, Category = "Item")
	UItem* GetItemData();
	UFUNCTION(BlueprintCallable, Category = "Item")
	void SetItemData(UItem* item);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
