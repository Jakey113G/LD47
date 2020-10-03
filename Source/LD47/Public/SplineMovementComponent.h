// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SplineMovementComponent.generated.h"

class USplineComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LD47_API USplineMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USplineMovementComponent();

	UFUNCTION(BlueprintCallable, Category = "Navigation")
    void SwitchSplineRoute(USplineComponent* newRoute);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = "Navigation")
    float MovementSpeed;

private:
	void MoveActorAlongSplineByDistance(USplineComponent* spline, float distance) const;

	USplineComponent* m_ActiveRoute;

	float m_DistanceMovedAlongSpline;
};
