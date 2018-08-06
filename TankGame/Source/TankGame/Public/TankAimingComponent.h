// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TankTurret.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM(BlueprintType)
enum class EFiringState:uint8
{
	//���״̬��ö������
	Reloading,
	Aiming,
	Locked
};

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

	//����
	UFUNCTION(BlueprintCallable,CateGory="GamePlay")
	void Fire();

	//�ڹ�
	UTankBarrel *Barrel = nullptr;
	//����
	UTankTurret *Turrent = nullptr;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float TankReloadTime = 3.0f;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float LaunchSpeed = 10000.0f;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileType;

	UPROPERTY(BlueprintReadOnly)
	//��ʼ�����״̬
	EFiringState FiringState = EFiringState::Aiming;

private:
	double LastFireTime = 0;
	
};
