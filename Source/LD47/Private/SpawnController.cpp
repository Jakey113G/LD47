// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnController.h"
#include "ObjectiveSpawnPoint.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ASpawnController::ASpawnController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnController::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AObjectiveSpawnPoint::StaticClass(), FoundActors);
}

// Called every frame
void ASpawnController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

