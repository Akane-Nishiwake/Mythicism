// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellItem.h"

USpellItem::USpellItem() {

}

FString USpellItem::ToString() {

	FString output = "";
	output += Super::ToString();

	return output;

}