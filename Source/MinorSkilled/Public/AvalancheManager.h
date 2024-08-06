// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrowingSnowball.h"  // Include your Snowball class header
#include "AvalancheManager.generated.h"

UCLASS()
class MINORSKILLED_API AAvalancheManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAvalancheManager();

public:
    // Functions to start the avalanche
    UFUNCTION(BlueprintCallable, Category = "Avalanche")
    void TriggerAvalanche();

private:
    FVector StartLocation;
    FVector EndLocation;
    float Speed;

protected:
    // EditAnywhere allows you to manually assign snowballs in the editor
    UPROPERTY(EditAnywhere, Category = "Avalanche")
    TArray<AGrowingSnowball*> Snowballs;


    // Called when the game starts or when spawned
    UFUNCTION(BlueprintCallable, Category = "Avalanche")
    void GetAllSnowballs();
};
