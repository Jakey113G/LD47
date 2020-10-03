// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackSwapComponent.h"
#include "SplineMovementComponent.h"
#include "Components/SplineComponent.h"
#include "Track.h"

// Sets default values for this component's properties
UTrackSwapComponent::UTrackSwapComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTrackSwapComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTrackSwapComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTrackSwapComponent::ApplySwap(AActor* actor, bool useOtherTrack)
{
	//Apply switch (movement logic will internally handle if the switch happens)
	auto splineMovement = actor->FindComponentByClass<USplineMovementComponent>();
	if (splineMovement)
	{
		ATrack* track = useOtherTrack ? TrackOther : TrackDefault;
		if (track)
		{
			auto splineComponent = track->FindComponentByClass<USplineComponent>();
			splineMovement->SwitchSplineRoute(splineComponent);
		}
	}
}
