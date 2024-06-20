// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MythicismCharacter.h"
#include "Enemy.generated.h" // Keep as last include

UCLASS()
class MYTHICISM_API AEnemy : public AMythicismCharacter
{
	GENERATED_BODY()

// Properties
protected:

// Behaviors
public:
	// Sets default values for this character's properties
	AEnemy();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Favor")
		float favorAmount;
protected:

};
