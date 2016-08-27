// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAITank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController currently possessing: %s"), *(AIControlledTank->GetName()));
	}

	auto PlayerPawn = GetPlayerTank();
	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cannot locate player tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank currently possessing: %s"), *(PlayerPawn->GetName()));
	}
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		//TODO move towards player
		GetAITank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire if ready
	}
}


ATank* ATankAIController::GetAITank() const
{
	auto AITank = GetPawn();
	if (!AITank) { return nullptr; }
	return Cast<ATank>(AITank);
}


ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
