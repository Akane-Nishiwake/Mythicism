// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

UItem::UItem() {
	
}


FString UItem::ToString() {


	FString output = "";

	output += ItemName.ToString() + ":\n";
	output += ItemDescription.ToString() + "\n";
	output += "(";
	output.AppendInt(ItemCost);
	output+=")\n";

	return output;
}