// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
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