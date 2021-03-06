// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectiveData.h"
#include "ObjectiveCollect.generated.h"

class ATrack;
UCLASS()
class LD47_API AObjectiveCollect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectiveCollect();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objective")
	FObjectiveState ObjectiveToHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
