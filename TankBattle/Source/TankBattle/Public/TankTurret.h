// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public: 
	// between -1 and 1
	void ChangeAzimuth(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxDegreesPerSecond = 25;
};
