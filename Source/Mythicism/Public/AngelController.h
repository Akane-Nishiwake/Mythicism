// Fill out your copyright notice in the Description page of Project Settings.

//#pragma once
//
//#include "CoreMinimal.h"
//#include "AIController.h"
//#include "Angel.h"
//#include "BehaviorTree/BlackboardComponent.h"
//#include "BehaviorTree/BehaviorTreeComponent.h"
//#include "BehaviorTree/BehaviorTree.h"
//#include "Kismet/GameplayStatics.h"
//
//#include "AngelController.generated.h"
//
//UCLASS()
//class MYTHICISM_API AAngelController : public AAIController
//{
//	GENERATED_BODY()
//	
//protected:
//	virtual void BeginPlay() override;
//
//public:
//	AAngelController();
//
//	virtual void OnPossess(APawn* InPawn) override;
//
//	UPROPERTY()
//		AAngel* angel;
//
//	UPROPERTY(transient)
//		class UBlackboardComponent* bbc;
//
//	UPROPERTY(transient)
//		class UBehaviorTreeComponent* btc;
//
//	/*Key Ids*/
//
//	uint8 TargetKeyID;
//
//	/*Functions*/
//	void SetTarget(UObject* newTarg);
//
//	UFUNCTION(BlueprintCallable, Category = "Target")
//	AActor* GetTarget() const;
//
//	void ClearTarget();
//
//	UFUNCTION()
//		void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
//			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
//
//	UFUNCTION()
//		void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
//
//};
