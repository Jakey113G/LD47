// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineMovementComponent.h"
#include "Components/SplineComponent.h"

// Sets default values for this component's properties
USplineMovementComponent::USplineMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;

	ActiveRoute = nullptr;
	m_DistanceMovedAlongSpline = 0.f;
}


// Called when the game starts
void USplineMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void USplineMovementComponent::MoveActorAlongSplineByDistance(USplineComponent* spline, float distance) const
{
	//Calculate new spline world positioning and apply to our actor
	FVector const wlocation = spline->GetWorldLocationAtDistanceAlongSpline(distance);
	FVector const fDirection = spline->GetDirectionAtDistanceAlongSpline(distance, ESplineCoordinateSpace::World);
	{
		FVector const newRight = FVector::CrossProduct(fDirection, -FVector::UpVector);
		FVector const newUp = FVector::CrossProduct(newRight, fDirection);
		FMatrix const rotMatrix = FMatrix(fDirection, newRight, newUp, FVector::ZeroVector);

		//set transform back on actor
		this->GetOwner()->SetActorLocationAndRotation(wlocation, rotMatrix.Rotator());
	}
}

void USplineMovementComponent::SwitchSplineRoute(USplineComponent* newRoute)
{
	if (ActiveRoute != newRoute)
	{
		ActiveRoute = newRoute;
		m_DistanceMovedAlongSpline = 0.f;

		if (ActiveRoute)
		{
			MoveActorAlongSplineByDistance(ActiveRoute, m_DistanceMovedAlongSpline);
		}
	}
}


// Called every frame
void USplineMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (ActiveRoute)
	{
		//add movement to existing travel distance along spline
		float const additionaMovement = MovementSpeed * DeltaTime;
		m_DistanceMovedAlongSpline += additionaMovement;

		//Loop if exceeded end
		if (ActiveRoute->IsClosedLoop() && m_DistanceMovedAlongSpline > ActiveRoute->GetSplineLength())
		{
			m_DistanceMovedAlongSpline = ActiveRoute->GetSplineLength() - m_DistanceMovedAlongSpline;
		}

		MoveActorAlongSplineByDistance(ActiveRoute, m_DistanceMovedAlongSpline);
	}
}

void USplineMovementComponent::InitializeComponent()
{
	Super::InitializeComponent();

	if (InitialConnectedTrack)
	{
		auto splineComponent = InitialConnectedTrack->FindComponentByClass<USplineComponent>();
		SwitchSplineRoute(splineComponent);
	}
}
