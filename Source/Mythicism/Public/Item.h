// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Texture2D.h"
#include "Blueprint/UserWidget.h"
#include "Item.generated.h"

/**
 * 
 */

UCLASS(Abstract, BlueprintType, EditInlineNew, DefaultToInstanced)
class MYTHICISM_API UItem : public UObject
{


	GENERATED_BODY()

public:
		UItem();

		UFUNCTION(BlueprintCallable)
		virtual FString ToString();

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
		FText ItemName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data", meta = (MultiLine= true))
		FText ItemDescription;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
		int32 ItemCost;

		//0 = Weapon, 1 = Spell
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
		int32 ItemType;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
		UTexture2D* Picture;

};
