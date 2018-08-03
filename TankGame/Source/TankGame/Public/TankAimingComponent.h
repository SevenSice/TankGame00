// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TankTurret.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKGAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable,CateGory="Setup")
	void Initialise(UTankBarrel *BarrelToSet, UTankTurret *TurretToSet);

	void AimAt(FVector HitLocation);

	//ÅÚ¹Ü
	UTankBarrel *Barrel = nullptr;
	//ÅÚËþ
	UTankTurret *Turrent = nullptr;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float LaunchSpeed = 100000.0f;

	
};
