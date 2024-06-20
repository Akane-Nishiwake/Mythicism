// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"




// Sets default values for this component's properties
UInventory::UInventory()
{
	WeaponCapacity = 24;

	for (auto& item : DefaultWeapons) {
		Weapons.Add(item);
	}

	PrimaryComponentTick.bCanEverTick = true;

}

UInventory::~UInventory()
{
	Weapons.Empty();
}

//WEAPON /////////////////////////////////////////////////////
bool UInventory::AddWeapon(class UWeaponItem* weapon) {


	Weapons.Add(weapon);
	//OnWeaponsUpdated.Broadcast();
	return true;

}
bool UInventory::RemoveWeapon(class UWeaponItem* weapon) {


	Weapons.Remove(weapon);
	//OnWeaponsUpdated.Broadcast();
	return true;

}
bool UInventory::WeaponExists(class UItem* weapon) {
	return Weapons.Contains((UWeaponItem*)weapon);
}

//Spell /////////////////////////////////////////////////////
bool UInventory::AddSpell(class USpellItem* Spell) {


	Spells.Add(Spell);
	//OnSpellsUpdated.Broadcast();
	return true;

}
bool UInventory::RemoveSpell(class USpellItem* Spell) {


	Spells.Remove(Spell);
	//OnSpellsUpdated.Broadcast();
	return true;

}
bool UInventory::SpellExists(class UItem* Spell) {
	return Spells.Contains((USpellItem*)Spell);
}

//Armor /////////////////////////////////////////////////////
bool UInventory::AddArmor(class UArmorItem* Armor) {


	Armors.Add(Armor);
	//OnArmorsUpdated.Broadcast();
	return true;

}
bool UInventory::RemoveArmor(class UArmorItem* Armor) {


	Armors.Remove(Armor);
	//OnArmorsUpdated.Broadcast();
	return true;

}
bool UInventory::ArmorExists(class UItem* Armor) {
	return Armors.Contains((UArmorItem*)Armor);
}

// Consumable /////////////////////////////////////////////////////
bool UInventory::AddConsumable(class UConsumableItem* Consumable) {


	Consumables.Add(Consumable);
	//OnConsumablesUpdated.Broadcast();
	return true;

}
bool UInventory::RemoveConsumable(class UConsumableItem* Consumable)
{
	//Consumables.Remove(Consumable);
	for (auto& Elem : Consumables)
	{
		if(
			Elem->ItemName.EqualTo(Consumable->ItemName) && 
			Elem->ConsumableData->amount == Consumable->ConsumableData->amount)
		{
			Consumables.Remove(Elem);
		}
	}

	//OnConsumablesUpdated.Broadcast();
	return true;

}
bool UInventory::ConsumableExists(class UItem* Consumable) {
	return Consumables.Contains((UConsumableItem*)Consumable);
}

//Key /////////////////////////////////////////////////////
bool UInventory::AddKey(class UKeyItem* Key) {


	Keys.Add(Key);
	//OnKeysUpdated.Broadcast();
	return true;

}
bool UInventory::RemoveKey(class UKeyItem* Key) {


	Keys.Remove(Key);
	//OnKeysUpdated.Broadcast();
	return true;

}
bool UInventory::KeyExists(class UItem* Key) {
	return Keys.Contains((UKeyItem*)Key);
}

bool UInventory::KeyCodeExists(FText _keyCode) {

	for(auto& key:Keys){
		if (key->keyCode.EqualToCaseIgnored(_keyCode))
			return true;
	}
	return false;
}

//GENERIC ITEM /////////////////////////////////////////////////////
bool UInventory::AddItem(class UItem* Item) {
	Items.Add(Item);

		//OnItemsUpdated.Broadcast();
	return false;
}
bool UInventory::RemoveItem(class UItem* Item) {
	Items.Remove(Item);

		//OnItemsUpdated.Broadcast();
		return true;

	return false;
}
bool UInventory::ItemExists(class UItem* Item) {
	return Items.Contains((UItem*)Item);
}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

