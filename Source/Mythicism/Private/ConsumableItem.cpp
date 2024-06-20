// Fill out your copyright notice in the Description page of Project Settings.


#include "ConsumableItem.h"

UConsumableItem::UConsumableItem() {

}

FString UConsumableItem::ToString() {

	FString output = "";
	output += Super::ToString();

	return output;

}