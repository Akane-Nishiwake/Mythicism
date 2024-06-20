
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Class.h"
#include "Components/ActorComponent.h"
//#include "GameFramework/Actor.h"
//#include "InventoryComponent.generated.h"


//UENUM(BlueprintType)
/*enum ITEM_TYPE{
	Weapon    UMETA(DisplayName = "Weapon"),
	Spell      UMETA(DisplayName = "Spell"),
	Key   UMETA(DisplayName = "Key"),
};*/
/*USTRUCT(BlueprintType)
struct MYTHICISM_API FItemBase
{

	GENERATED_BODY()
		//Variables
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
		FString name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
		FString description;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
		FString image;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
		//TEnumAsByte<ITEM_TYPE> type;
};
USTRUCT(BlueprintType)
struct MYTHICISM_API FItemSpell : public FItemBase
{

	GENERATED_BODY()
		//Variables
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell")
		AActor* quickPrototype;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell")
		float quickMana;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell")
		float quickStamina;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell")
		AActor* trapPrototype;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell")
		float trapMana;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell")
		float trapStamina;
};



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYTHICISM_API UInventoryComponent : public UActorComponent {
public:
	GENERATED_BODY()

		//Constructor
		UInventoryComponent();
	//Functions

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void AddSpell(FItemSpell spell);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void AddItem(FItemBase item);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void DeleteItem(FItemBase item);
	//Variables
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		TSet<FItemBase> items;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell")
		FItemSpell currentSpell;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};*/


