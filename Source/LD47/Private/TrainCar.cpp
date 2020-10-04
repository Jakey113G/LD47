// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainCar.h"
#include "SplineMovementComponent.h"
#include "Components/SplineComponent.h"

// Sets default values
ATrainCar::ATrainCar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SplineMovementComponent = CreateDefaultSubobject<USplineMovementComponent>(TEXT("SplineMovementComponent"));
}

// Called when the game starts or when spawned
void ATrainCar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrainCar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrainCar::SetCarryObjective(EObjectiveColourEnum objective)
{
	ObjectiveState.bActive = true;
	ObjectiveState.ObjectiveType = objective;
	OnRefreshTrainState.Broadcast();
}

