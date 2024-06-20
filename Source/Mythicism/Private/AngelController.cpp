// Fill out your copyright notice in the Description page of Project Settings.


/*#include "AngelController.h"

AAngelController::AAngelController()
{
	bbc = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));
	btc = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree Component"));
}

void AAngelController::BeginPlay()
{
	Super::BeginPlay();

	if (angel->sphereVision)
	{
		angel->sphereVision->OnComponentBeginOverlap.AddDynamic(this, &AAngelController::OnSphereBeginOverlap);
		angel->sphereVision->OnComponentEndOverlap.AddDynamic(this, &AAngelController::OnSphereEndOverlap);
	}

	bbc->SetValueAsBool("HealthIs75", true);
	bbc->SetValueAsBool("HealthIs10", true);
	bbc->SetValueAsBool("HealthIs0", true);
}

void AAngelController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	angel = Cast<AAngel>(InPawn);

	if (angel && angel->behaviorTree)
	{
		bbc->InitializeBlackboard(*angel->behaviorTree->BlackboardAsset);

		TargetKeyID = bbc->GetKeyID("Target");

		btc->StartTree(*angel->behaviorTree);
	}
}

void AAngelController::SetTarget(UObject* newTarg)
{
	bbc->SetValueAsObject("Target", newTarg);
}

AActor* AAngelController::GetTarget() const
{
	return dynamic_cast<AActor*>(bbc->GetValueAsObject("Target"));
}

void AAngelController::ClearTarget()
{
	bbc->ClearValue("Target");
}

void AAngelController::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Begin Overlap"));

	if (OtherActor != angel && OtherActor->GetActorLabel() == "BP_MythicismPlayer")
	{
		SetTarget(OtherActor);
	}
}

void AAngelController::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("End Overlap"));

	if (OtherActor == GetTarget())
	{
		ClearTarget();
	}
}
*/