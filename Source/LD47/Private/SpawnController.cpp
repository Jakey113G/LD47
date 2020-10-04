// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnController.h"
#include "ObjectiveSpawnPoint.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ASpawnController::ASpawnController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_elapsedTime = 0.0f;
	SpawnTime = 15.0f;
	m_NextIndexToTry = 0;
}

// Called when the game starts or when spawned
void ASpawnController::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AObjectiveSpawnPoint::StaticClass(), FoundActors);
	for (int i = 0; i < FoundActors.Num(); ++i)
	{
		FoundActors.Swap(i, FMath::RandRange(i, FoundActors.Num() - 1));
	}
}

// Called every frame
void ASpawnController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	{
		m_elapsedTime += DeltaTime;

		if (m_elapsedTime > SpawnTime)
		{
			SpawnObjective();
			m_elapsedTime = SpawnTime - m_elapsedTime;
		}
	}
}

void ASpawnController::SpawnObjective()
{
	for (int i = m_NextIndexToTry; i < FoundActors.Num(); ++i)
	{
		//wrap around loop from this starting index
		int const indexToCheck = (m_NextIndexToTry + i) % FoundActors.Num();

		AObjectiveSpawnPoint * sp = Cast<AObjectiveSpawnPoint>(FoundActors[indexToCheck]);
		if (!sp->IsObjectiveSpawned())
		{
			int const maxInclusiveColour = static_cast<int>(EObjectiveColourEnum::EnumCount) - 1;
			EObjectiveColourEnum value = static_cast<EObjectiveColourEnum>(FMath::RandRange(0, maxInclusiveColour));
			sp->SetObjective(value);
			m_NextIndexToTry = indexToCheck + 1;
			return;
		}
	}
}


