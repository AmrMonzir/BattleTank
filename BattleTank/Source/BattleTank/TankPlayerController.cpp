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
void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	//Aim at crosshair
	AimTowardsCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Ticking"));
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {

	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out Parameter
	if (GetSightRayHitLocation(HitLocation)) { // Has "side-effect", is going to line trace
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
			//if it hits the landscape
				//tell controlled tank to aim at this point
	}
}

// Get World Location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const {
	
	HitLocation = FVector(1.0);
	return true;
}