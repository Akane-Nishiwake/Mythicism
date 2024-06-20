// Fill out your copyright notice in the Description page of Project Settings.

#include "MythicismPlayer.h"

// Sets default values
AMythicismPlayer::AMythicismPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Player"));

}


