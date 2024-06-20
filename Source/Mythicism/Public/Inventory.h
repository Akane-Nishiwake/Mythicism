// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponItem.h"
#include "SpellItem.h"
#include "ConsumableItem.h"
#include "KeyItem.h"
#include "ArmorItem.h"
#include "ItemPickup.h"

#include "Inventory.generated.h"

/*DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWeaponsUpdated)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnArmorssUpdated)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnKeysUpdated)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSpellsUpdated)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnConsumablesUpdated)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemsUpdated)*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYTHICISM_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventory();
	~UInventory();


	//Weapon Functions
	UFUNCTION(BlueprintCallable)
	bool AddWeapon( class UWeaponItem* weapon);
	UFUNCTION(BlueprintCallable)
	bool RemoveWeapon(class UWeaponItem* weapon);
	UFUNCTION(BlueprintCallable)
	bool WeaponExists(class UItem* weapon);

	//Spell Functions
	UFUNCTION(BlueprintCallable)
		bool AddSpell(class USpellItem* Spell);
	UFUNCTION(BlueprintCallable)
		bool RemoveSpell(class USpellItem* Spell);
	UFUNCTION(BlueprintCallable)
		bool SpellExists(class UItem* Spell);

	//Armor Functions
	UFUNCTION(BlueprintCallable)
		bool AddArmor(class UArmorItem* Armor);
	UFUNCTION(BlueprintCallable)
		bool RemoveArmor(class UArmorItem* Armor);
	UFUNCTION(BlueprintCallable)
		bool ArmorExists(class UItem* Armor);

	//Consumable Functions
	UFUNCTION(BlueprintCallable)
		bool AddConsumable(class UConsumableItem* Consumable);
	UFUNCTION(BlueprintCallable)
		bool RemoveConsumable(class UConsumableItem* Consumable);
	UFUNCTION(BlueprintCallable)
		bool ConsumableExists(class UItem* Consumable);

	//Key Functions
	UFUNCTION(BlueprintCallable)
		bool AddKey(class UKeyItem* Key);
	UFUNCTION(BlueprintCallable)
		bool RemoveKey(class UKeyItem* Key);
	UFUNCTION(BlueprintCallable)
		bool KeyExists(class UItem* Key);
	UFUNCTION(BlueprintCallable)
		bool KeyCodeExists(FText _keyCode);

	//Generic Item Functions
	UFUNCTION(BlueprintCallable)
		bool AddItem(class UItem* Item);
	UFUNCTION(BlueprintCallable)
		bool RemoveItem(class UItem* Item);
	UFUNCTION(BlueprintCallable)
		bool ItemExists(class UItem* Item);


	//Weapon Data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSet<UWeaponItem*> DefaultWeapons;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TSet<UWeaponItem*> Weapons;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
	int32 WeaponCapacity;

	//Spell Data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TSet<USpellItem*> DefaultSpells;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
		TSet<USpellItem*> Spells;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
		int32 SpellCapacity;


	//Armor Data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TSet<UArmorItem*> DefaultArmors;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
		TSet<UArmorItem*> Armors;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
		int32 ArmorCapacity;


	//Consumable Data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TSet<UConsumableItem*> DefaultConsumables;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
		TSet<UConsumableItem*> Consumables;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
		int32 ConsumableCapacity;


	//Key Data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TSet<UKeyItem*> DefaultKeys;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
		TSet<UKeyItem*> Keys;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
		int32 KeyCapacity;


	//Generic Item Data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSet<UItem*> DefaultItems;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TSet<UItem*> Items;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
	int32 ItemCapacity;

	//for drop function
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemPickup")
	FVector SpawnOffset;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};
