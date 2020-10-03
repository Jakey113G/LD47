// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrackSwitch.generated.h"

class UTrackSwapComponent;

UCLASS()
class LD47_API ATrackSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrackSwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Navigation")
	UTrackSwapComponent* TrackSwapComponent;

	UFUNCTION(BlueprintCallable, Category = "Navigation")
	void SetIsSwitchActive(bool state);

	UPROPERTY(EditAnywhere, Category = "Navigation")
	bool IsSwitchActive;

	UFUNCTION(BlueprintCallable, Category = "Navigation")
	void OnActorEnteringSwitch(AActor* actor);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
