// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// between -1 and 1
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 10; 
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegrees = 50;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees = 0;
};
