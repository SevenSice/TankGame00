// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom),meta=(BlueprintSpawnableComponent))
class TANKGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegreePerSecond = 20.0f;

	//最大仰角
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegree = 40.0f;
	//最小仰角（俯视角）
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MinDegree = -5.0f;
		
	void MoveBarrel(FVector AimDirection);
	
};
