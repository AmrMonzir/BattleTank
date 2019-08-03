// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"
#include "GameFramework/Controller.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller BeginPlay"));
	if (GetControlledTank() != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Got a possessed tank %s"), *GetControlledTank()->GetName());
	}
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}