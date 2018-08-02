// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "Engine/World.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//获取控制的坦克
	ATank * GetControlledTank();
	//获取玩家控制的坦克

	//炮管转向目标
	void AnimToTarget();

	//
	bool GetSightRayHitLocation(FVector &OutHitLocation);
	//获取看到的朝向
	bool GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation);
private:
	//十字标的坐标
	float CrosshairXLocation = 0.5f;
	float CrosshairYLocation = 0.3f;

	UPROPERTY(EditAnyWhere)
		float LineTraceRange = 100000.0f;
};
