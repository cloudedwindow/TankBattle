// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "TankTurret.h"


void UTankTurret::ChangeAzimuth(float RelativeSpeed)
{
	//move the turret the right amount 
	auto Speed = FMath::Clamp<float>(RelativeSpeed, MinRelativeSpeed, MaxRelativeSpeed);

	auto AzimuthChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewAzimuth = RelativeRotation.Yaw + AzimuthChange;

	SetRelativeRotation(FRotator(0, NewAzimuth, 0));
}

