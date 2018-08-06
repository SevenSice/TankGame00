// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::MoveTurret(FVector AimDirection)
{
	FRotator CurrentRotation = GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();
	//跟随指示点转动
	 ChangeYaw = AimRotation.Yaw - CurrentRotation.Yaw;
	if (ChangeYaw>180)
	{
		ChangeYaw = ChangeYaw - 360;
	}
	else if(ChangeYaw < -180)
	{
		ChangeYaw = ChangeYaw + 360;
	}

	float ReletiveSpeed = FMath::Clamp<float>(ChangeYaw, -1, 1);
	//每帧旋转的角度
	float RotationTickChange = ReletiveSpeed * MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	float NewRotationYaw = RotationTickChange + RelativeRotation.Yaw;

	SetRelativeRotation(FRotator(0, NewRotationYaw, 0));
}

float UTankTurret::GetChangeYaw()
{
	return this->ChangeYaw;
}
