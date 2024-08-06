// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Materials/MaterialInterface.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Flags.generated.h"

UCLASS()
class MINORSKILLED_API AFlags : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlags();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInterface* GreenMaterial; // Material to set when flags are triggered
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* LeftFlag;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RightFlag;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* TriggerVolume;

	UFUNCTION(BlueprintCallable)
	void InitializeComponents(
		UStaticMeshComponent* LeftFlagMesh,
		UStaticMeshComponent* RightFlagMesh,
		UBoxComponent* BoxCollision
	);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	UFUNCTION(BlueprintCallable)
	void OnPlayerPassThrough(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:	
	bool bIsTriggered;
};
