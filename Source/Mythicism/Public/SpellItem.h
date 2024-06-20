// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "QuickSpell.h"
#include "TrapSpell.h"
#include "SpellItem.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, BlueprintType, Blueprintable)
class MYTHICISM_API USpellItem : public UItem
{
	GENERATED_BODY()
public:

		USpellItem();
		////////////// DEPRECIATED ////////////// 
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
		TSubclassOf<AActor> SpellActor;
		///////////////////////////////////////// 

		virtual FString ToString() override;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
		TSubclassOf<AQuickSpell> QuickSpell;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
			TSubclassOf<ATrapSpell> TrapSpell;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item Data")
			float quickSpellCost;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item Data")
			float trapSpellCost;

	
};
