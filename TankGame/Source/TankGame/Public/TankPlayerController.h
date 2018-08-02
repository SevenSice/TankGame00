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

	//��ȡ���Ƶ�̹��
	ATank * GetControlledTank();
	//��ȡ��ҿ��Ƶ�̹��

	//�ڹ�ת��Ŀ��
	void AnimToTarget();

	//
	bool GetSightRayHitLocation(FVector &OutHitLocation);
	//��ȡ�����ĳ���
	bool GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation);
private:
	//ʮ�ֱ������
	float CrosshairXLocation = 0.5f;
	float CrosshairYLocation = 0.3f;

	UPROPERTY(EditAnyWhere)
		float LineTraceRange = 100000.0f;
};
