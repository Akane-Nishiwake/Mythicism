// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MythicismCharacter.h"
#include "Curse.generated.h"

UCLASS()
class MYTHICISM_API ACurse : public AActor
{
	GENERATED_BODY()

		// Properties
public:
	// Pointer to the AMythicismCharacter we are attached to. This value is guarenteed to be valid.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Curse Attributes")
		AMythicismCharacter* curseReceiver;

	// Pointer to the AMythicismCharacter that caused this curse. This value is not guarenteed and needs to be set manually. 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Curse Attributes")
		AMythicismCharacter* curseDeliverer;

	// The game time, in seconds, when Curse event was called
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Curse Attributes")
		float curseStartTime;

	// Behaviors
public:
	// Sets default values for this actor's properties
	ACurse();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void BeginCurse();

	// Method for carrying out curse. Gets called in BeginPlay
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Curse();

	// Method for when the curse has ended
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void RemoveCurse();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
