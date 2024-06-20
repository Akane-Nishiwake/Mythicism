// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterAttributesComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYTHICISM_API UCharacterAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterAttributesComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes")
	bool isInvincible;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes")
	float health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes")
	float maxHealth;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes")
	float baseHealth;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes")
	float stamina;	
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes")
	float maxStamina;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes")
	float baseStamina;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes")
	float mana;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes")
	float maxMana;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes")
	float baseMana;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes");
	float attackPower;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes");
	float baseAttackPower;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes");
	float attackDefense;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes");
	float baseAttackDefense;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes");
	float magicDefense;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes");
	float burnDefense;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes");
	float equipLoad;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Attributes");
	bool godMode;
};
