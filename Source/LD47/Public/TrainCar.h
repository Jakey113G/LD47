// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ObjectiveData.h"
#include "TrainCar.generated.h"

class USplineMovementComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRefreshTrainStateDelegate);

UCLASS()
class LD47_API ATrainCar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrainCar();

	UPROPERTY(EditAnywhere, Category = "Train")
	USplineMovementComponent* SplineMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Train")
	FObjectiveState ObjectiveState;

	UFUNCTION(BlueprintCallable, Category = "Train")
	void SetCarryObjective(EObjectiveColourEnum objective);

	UFUNCTION(BlueprintCallable, Category = "Train")
	void ClearObjective();


	UPROPERTY(BlueprintAssignable, Category = "Objective")
	FOnRefreshTrainStateDelegate OnRefreshTrainState;

protected:
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
