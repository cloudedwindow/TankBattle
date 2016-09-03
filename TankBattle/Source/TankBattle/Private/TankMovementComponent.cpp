// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}


void UTankMovementComponent::IntentMoveForward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO clamp throttle values 
}


void UTankMovementComponent::IntentTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
}


void UTankMovementComponent::IntentTurnLeft(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}


void UTankMovementComponent::IntentMoveBackward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);
}


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// no need to call Super as we're replacing the functionality
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntentMoveForward(ForwardThrow);

	auto RotationThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntentTurnRight(RotationThrow);
}
