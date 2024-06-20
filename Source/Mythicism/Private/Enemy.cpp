// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//attributes = CreateDefaultSubobject<UCharacterAttributesComponent>(TEXT("Character Attributes")); //create attributes for enemy
	attributes->health = 600; //set enemy health
	favorAmount = 0.0f; //set enemy favor to zero by default
}
