// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	
	if (ControlledTank==nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ERROR: Controlled IS NULL"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlled IS %s"),*ControlledTank->GetName());
	}
}

ATank * ATankPlayerController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

