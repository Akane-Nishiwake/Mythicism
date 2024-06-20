// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemPickup.h"
#include "UObject/UObjectGlobals.h"
// Sets default values
AItemPickup::AItemPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//(FName SubobjectFName, UClass* ReturnType, UClass* ClassToCreateByDefault, bool bIsRequired, bool bAbstract, bool bIsTransient)
	ItemData = CreateDefaultSubobject<UItem>(FName("DEFAULT"));


	//ItemData->ItemName = FText::FromString("DEFAULT");

		
		/*UObject * Outer = (UObject*)GetTransientPackage(),
		UClass * Class = T::StaticClass()*/
}


bool AItemPickup::InteractFunction() {
	
	if (!Super::InteractFunction())
		return false;

	
	//ConditionalBeginDestroy();
	return true;

}

UItem* AItemPickup::GetItemData()
{
	return ItemData;
}
void AItemPickup::SetItemData(UItem* item)
{
	ItemData = item;
}

void AItemPickup::BeginPlay()  {
	Super::BeginPlay();


}