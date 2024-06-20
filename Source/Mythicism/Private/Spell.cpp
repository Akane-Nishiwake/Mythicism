// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"
#include "Engine/World.h"

// Sets default values
ASpell::ASpell()
{
}

void ASpell::DeliverCurse(AMythicismCharacter* curseReceiver)
{
	if (!curseReceiver || !spellCaster || !curseClass)
		return;

	// Check if curse is already active
	TArray<AActor*> attachedActor;
	curseReceiver->GetAttachedActors(attachedActor);
	for (auto& child : attachedActor)
	{
		if (child->IsA(curseClass))
		{
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Purple, TEXT("Noticed double curse and removed it"));
			
			Cast<ACurse>(child)->RemoveCurse();
			break;
		}
	}

	// Add curse
	ACurse* activeCurse = GetWorld()->SpawnActor<ACurse>(curseClass, FVector(), FRotator());
	if (activeCurse && spellCaster)
	{
		activeCurse->AttachToActor(curseReceiver, { EAttachmentRule::KeepRelative, false });
		activeCurse->curseReceiver = curseReceiver;
		activeCurse->curseDeliverer = spellCaster;
		activeCurse->BeginCurse();
	}
}










/*


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



















// Fill out your copyright notice in the Description page of Project Settings.


#include "Curse.h"

// Sets default values
ACurse::ACurse()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACurse::BeginPlay()
{
	Super::BeginPlay();
}


void ACurse::BeginCurse()
{
	if (!curseReceiver)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Purple, TEXT("Could not begin curse: curseReceiver = nullptr"));
		return;
	}

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Purple, TEXT("Curse added"));

	curseStartTime = GetWorld()->GetTimeSeconds();
	Curse();
}

// Called every frame
void ACurse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

*/