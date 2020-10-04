// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectiveData.generated.h"


UENUM(BlueprintType)
enum class EObjectiveColourEnum : uint8
{
	Red,
	Yellow,
	Blue,
	Green,

	EnumCount,
};

USTRUCT(BlueprintType)
struct FObjectiveState
{
	GENERATED_USTRUCT_BODY()
public:
	FObjectiveState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objective")
	bool bActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objective")
	EObjectiveColourEnum ObjectiveType;
};
