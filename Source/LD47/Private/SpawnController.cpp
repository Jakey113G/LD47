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
	SpawnTime = 18.0f;
}

// Called when the game starts or when spawned
void ASpawnController::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AObjectiveSpawnPoint::StaticClass(), FoundActors);
	//int arraySize = FoundActors.Num();
	//for (int32 i = 0; i <= arraySize; ++i)
	//{
	//	int32 Index = FMath::RandRange(i, arraySize);
	//	if (i != Index)
	//	{
	//		FoundActors.Swap(i, Index);
	//	}
	//}
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
	for (int i = 0; i < FoundActors.Num(); ++i)
	{
		AObjectiveSpawnPoint * sp = Cast<AObjectiveSpawnPoint>(FoundActors[i]);
		if (!sp->IsObjectiveSpawned())
		{
			EObjectiveColourEnum value = static_cast<EObjectiveColourEnum>(FMath::RandRange(0, (int)EObjectiveColourEnum::EnumCount));
			sp->SetObjective(value);
			return;
		}
	}
}


