// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::MoveBarrel(FVector AimDirection)
{
	FRotator CurrentRotation = GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();

	float ChangePich = AimRotation.Pitch - CurrentRotation.Pitch;

	float RelativeSpeed = FMath::Clamp<float>(ChangePich, -1, 1);
	float RotationTickChange = RelativeSpeed * MaxDegreePerSecond*GetWorld()->DeltaTimeSeconds;
	float NewRotationPich = RotationTickChange + RelativeRotation.Pitch;

	//Limitation of pich
	NewRotationPich = FMath::Clamp<float>(NewRotationPich, MinDegree, MaxDegree);

	SetRelativeRotation(FRotator(NewRotationPich, 0, 0));

}
