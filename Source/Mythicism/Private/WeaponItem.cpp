// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponItem.h"

UWeaponItem::UWeaponItem() {

}

FString UWeaponItem::ToString() {

	FString output = "";
	output+= Super::ToString();

	return output;

}