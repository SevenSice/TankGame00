// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Barrel == nullptr || Turrent == nullptr)
	{
		return;
	}
	if ((FPlatformTime::Seconds()-LastFireTime)<TankReloadTime)
	{
		FiringState = EFiringState::Reloading;
		return;
	}
	//判断炮管旋转角度是否大于3度，是就为Aiming，否则为Locked
	if (FMath::Abs(Turrent->GetChangeYaw())>3)
	{
		FiringState = EFiringState::Aiming;
	}else
	{
		FiringState = EFiringState::Locked;
	}
}

void UTankAimingComponent::Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	Barrel = BarrelToSet;
	Turrent = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (Barrel==nullptr||Turrent==nullptr)
	{
		return;
	}
	//开火角度
	FVector FireVector;
	FVector FireStartLocation = Barrel->GetSocketLocation(FName("FireLocation"));

	bool bHaveSolution = false;
	bHaveSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		FireVector,
		FireStartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace

	);
	if (bHaveSolution)
	{
		//通知炮塔合炮管转向。
		//UE_LOG(LogTemp, Warning, TEXT("Fire Vector : %s"),*FireVector.GetSafeNormal().ToString());
		Turrent->MoveTurret(FireVector.GetSafeNormal());
		Barrel->MoveBarrel(FireVector.GetSafeNormal());
	}
}

void UTankAimingComponent::Fire()
{
	bool isReload = (FPlatformTime::Seconds() - LastFireTime) > TankReloadTime;
	//UE_LOG(LogTemp, Warning, TEXT("Fire!"));
	if (Turrent==nullptr||ProjectileType==nullptr||!isReload){return;}

	AProjectile *Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileType,
		Barrel->GetSocketLocation(FName("FireLocation")),
		Barrel->GetSocketRotation(FName("FireLocation"))
		);
	Projectile->LanchProjectile(LaunchSpeed);
	LastFireTime = FPlatformTime::Seconds();
}

