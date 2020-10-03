// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TrackSwapComponent.generated.h"

class ATrack;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LD47_API UTrackSwapComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTrackSwapComponent();

	UPROPERTY(EditAnywhere, Category = "Navigation")
	ATrack* TrackDefault;

	UPROPERTY(EditAnywhere, Category = "Navigation")
    ATrack* TrackOther;

	void ApplySwap(AActor* actor, bool useOtherTrack);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
