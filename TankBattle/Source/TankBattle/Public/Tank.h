// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class TANKBATTLE_API ATank : public APawn
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected: 
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000; 

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 1;

	double LastFireTime = 0;
};
