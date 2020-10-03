// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrainCar.generated.h"

class USplineMovementComponent;

UCLASS()
class LD47_API ATrainCar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrainCar();

	UPROPERTY(EditAnywhere, Category = "Train")
	USplineMovementComponent* SplineMovementComponent;

	UPROPERTY(EditAnywhere, Category = "Train")
	AActor* TrackHead;

	UPROPERTY(EditAnywhere, Category = "Train")
	AActor* TrackTail;

	UFUNCTION(BlueprintCallable, Category = "Train")
	void JoinToFrontCar(AActor* train);

	UFUNCTION(BlueprintCallable, Category = "Train")
	void DetachFromFront();


protected:
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
