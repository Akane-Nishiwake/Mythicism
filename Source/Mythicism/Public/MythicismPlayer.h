// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MythicismCharacter.h"
#include "MythicismPlayer.generated.h"

UCLASS()
class MYTHICISM_API AMythicismPlayer : public AMythicismCharacter
{
	GENERATED_BODY()

// Properties
public:


// Behaviors
public:	
	// Sets default values for this character's properties
	AMythicismPlayer();
	
protected:

	UPROPERTY(BlueprintReadWrite, Category = "Currency")
		int playerCurrency;
	 
};
