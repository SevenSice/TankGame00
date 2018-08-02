// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank *ControlledTank = GetControlledTank();
	ATank *PlayerTank = GetPlayerTank();

	if (ControlledTank==nullptr||PlayerTank==nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("ERROR:ControlledTank IS Null"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ControlledTank IS : %s ,PlayerTank IS : %s"),*ControlledTank->GetName(), *PlayerTank->GetName());
	}
}




ATank* ATankAIController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank()
{
	ATank *PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank==nullptr)
	{
		return nullptr;
	}
	return PlayerTank;
}

