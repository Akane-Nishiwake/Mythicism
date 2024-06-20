// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmorItem.h"

UArmorItem::UArmorItem() {

}

FString UArmorItem::ToString() {

	FString output = "";
	output += Super::ToString();

	return output;

}