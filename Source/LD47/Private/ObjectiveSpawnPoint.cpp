// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveSpawnPoint.h"

// Sets default values
AObjectiveSpawnPoint::AObjectiveSpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObjectiveSpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObjectiveSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AObjectiveSpawnPoint::IsObjectiveSpawned()
{
	return SpawnData.bActive;
}

void AObjectiveSpawnPoint::SetObjective(EObjectiveColourEnum value)
{
	SpawnData.bActive = true;
	SpawnData.ObjectiveType = value;

	OnObjectiveSet.Broadcast();
}

