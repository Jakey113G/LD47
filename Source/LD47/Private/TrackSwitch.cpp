// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackSwitch.h"
#include "TrackSwapComponent.h"

// Sets default values
ATrackSwitch::ATrackSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TrackSwapComponent = CreateDefaultSubobject<UTrackSwapComponent>(TEXT("TrackSwapComponent"));
}

// Called when the game starts or when spawned
void ATrackSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrackSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATrackSwitch::OnActorEnteringSwitch(AActor* actor)
{
	TrackSwapComponent->ApplySwap(actor, IsSwitchActive);
}

