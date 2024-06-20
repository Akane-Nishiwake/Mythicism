// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
/*inputcore, UMG, Slate, SlateCore,*/
#include "InputCore.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "Components/SphereComponent.h"
#include "InteractableBase.generated.h"

UCLASS()
class MYTHICISM_API AInteractableBase : public AActor
{
	
		
public:	
	// Sets default values for this actor's properties
	GENERATED_BODY()
	AInteractableBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	USphereComponent* radius;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interactable")
	USceneComponent* root;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	UUserWidget* prompt;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Interactable")
	bool playerInRange;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Interactable")
	bool used;


	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	UFUNCTION()
		void EndOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	virtual bool InteractFunction();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
