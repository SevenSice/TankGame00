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

void ATankPlayerController::Tick(float DeltaTime)
{
	//move to aim Location
	AnimToTarget();
}

ATank * ATankPlayerController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AnimToTarget()
{
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation : %s"), *HitLocation.ToString());
	}	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation)
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	FVector WorldLocation;
	FVector WorldDirection;// LookDirection

	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection))
	{   
		//使用射线找撞击点
		GetLookVectorHitLocation(WorldDirection, OutHitLocation);

		return true;
	}

	return false;
}

//寻找射线撞击的点
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & OutHitLocation)
{
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + LookDirection * LineTraceRange;
	FHitResult HitResult;

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	)) {
		OutHitLocation = HitResult.Location;	
		return true;
	}
	OutHitLocation = FVector(0.0f);
	return false;
}

