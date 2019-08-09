// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	if (GetControlledTank()) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank controller possessing: %s\n"), *GetControlledTank()->GetName())
	}else
		UE_LOG(LogTemp, Warning, TEXT("AI Tank controller failed to possess"))
	if (GetPlayerTank()) {
		UE_LOG(LogTemp, Warning, TEXT("AITank: %s found Player Controller: %s\n"), *GetControlledTank()->GetName(), *GetPlayerTank()->GetName())
	}else
		UE_LOG(LogTemp, Warning, TEXT("AITank Can't find player tank"))
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (GetControlledTank() && GetPlayerTank()) {
		//Move towards the player

		//Aim at the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire if ready
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank)
		return nullptr;
	else
	return Cast<ATank>(PlayerTank);
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}