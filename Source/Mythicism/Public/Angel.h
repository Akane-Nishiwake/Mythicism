// Fill out your copyright notice in the Description page of Project Settings.

//#pragma once
//
//#include "CoreMinimal.h"
//#include "GameFramework/Character.h"
//#include "AIController.h"
//#include "Components/PrimitiveComponent.h"
//#include "Components/SphereComponent.h"
//#include "Tasks/AITask.h"
//#include "Components/ChildActorComponent.h"
//#include "GameFramework/Controller.h"
//#include "BehaviorTree/BlackboardComponent.h"
//#include "BehaviorTree/BehaviorTreeComponent.h"
//#include "BehaviorTree/BehaviorTree.h"
//#include "Kismet/KismetMathLibrary.h"
//#include "MythicismCharacter.h"
//
//#include "Angel.generated.h"
//
//UCLASS()
//class MYTHICISM_API AAngel : public AMythicismCharacter
//{
//	GENERATED_BODY()
//
//public:
//	// Sets default values for this character's properties
//	AAngel();
//
//protected:
//	virtual void Tick(float DeltaTime) override;
//	
//public:	
//	/** sphere component */
//	UPROPERTY(EditAnywhere, Category = "Sphere Component")
//		USphereComponent* sphereVision;
//
//	UPROPERTY(EditAnywhere, Category = "Black Board")
//		class UBehaviorTree* behaviorTree;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Range")
//		float closeRange;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Range")
//		float longRange;
//
//	// AI Healing Functions
//	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Heal")
//		void HealTo100();
//	void HealTo100_Implementation();
//
//	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Heal")
//		void HealTo30();
//	void HealTo30_Implementation();
//
//	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Heal")
//		void HealTo10();
//	void HealTo10_Implementation();
//};
