// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectiveData.h"

#include "ObjectiveSpawnPoint.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnObjectiveSetDelegate);

class ATrack;
UCLASS()
class LD47_API AObjectiveSpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectiveSpawnPoint();

	UPROPERTY(EditAnywhere, Category = "Navigation")
	ATrack* AssociatedTrack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objective")
	FObjectiveState SpawnData;

	bool IsObjectiveSpawned();
	void SetObjective(EObjectiveColourEnum value);

	UPROPERTY(BlueprintAssignable, Category = "Objective")
	FOnObjectiveSetDelegate OnObjectiveSet;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
