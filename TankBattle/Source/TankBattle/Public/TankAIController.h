// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class TANKBATTLE_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	void virtual Tick(float DeltaSeconds) override;

private:
	// how close can the AI Tank get
	float AcceptanceRadius = 3000;
};
