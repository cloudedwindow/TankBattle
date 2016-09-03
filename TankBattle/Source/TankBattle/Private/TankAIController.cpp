// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "Tank.h"
#include "TankAIController.h"
// Depends on movement component via pathfinding dependencies

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank))
	{
		// move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// aim at player
		AITank->AimAt(PlayerTank->GetActorLocation());

		AITank->Fire();
	}
}
