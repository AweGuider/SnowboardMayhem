// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Snowboarder.generated.h"

UCLASS()
class MINORSKILLED_API ASnowboarder : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASnowboarder();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Snowboard")
		void CalculateVelocity(FVector CurrentVelocity);

	UFUNCTION(BlueprintCallable, Category = "Utils")
		void ProcessLineTrace(bool bHit, FVector HitNormal);

	UFUNCTION(BlueprintCallable, Category = "Snowboard")
		void AlignSnowboardWithSlope(float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent)
		void DrawDebugArrowInDirection(
			FVector DirectionVector,
			FLinearColor ArrowColor,
			bool Enabled
		);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

#pragma region Debug
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		bool ShowDebug;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		FVector DebugArrowsOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		FLinearColor SidewaysInputColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		bool DebugSlopeNormal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		FLinearColor SlopeNormalColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		bool DebugGravityForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		FLinearColor GravityForceColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		bool DebugSlopeProjection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		FLinearColor SlopeProjectionColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		bool DebugSnowboardForward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		FLinearColor SnowboardForwardColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		bool DebugSnowboardForwardProjection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		FLinearColor SnowboardForwardProjectionColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		bool DebugVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		FLinearColor VelocityColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		bool DebugSideways;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		FLinearColor SidewaysVectorColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		bool DebugFriction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		FLinearColor FrictionForceColor;

#pragma endregion

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Custom")
		float GravityConstant;

	UPROPERTY(BlueprintReadWrite, Category = "Physics")
		FVector GravityForce;

	UPROPERTY(BlueprintReadWrite, Transient, Category = "Physics")
		FVector FrictionForce;

	UPROPERTY(BlueprintReadWrite, Transient, Category = "Physics")
		FVector NewVelocity;

	UPROPERTY(BlueprintReadWrite, Transient, Category = "Physics")
		FVector SnowboardForwardVector;

	UPROPERTY(BlueprintReadWrite, Transient, Category = "Physics")
		FVector OutHitNormal;

private:

	// BlueprintReadOnly
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom", meta = (AllowPrivateAccess = "true"))
		bool FreeCameraEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics", meta = (AllowPrivateAccess = "true"))
		float TurningSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics", meta = (AllowPrivateAccess = "true"))
		bool IsGrounded;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics", meta = (AllowPrivateAccess = "true"))
		float SnowboardRotationInterpSpeed;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics", meta = (AllowPrivateAccess = "true"))
		float GravityForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics", meta = (AllowPrivateAccess = "true"))
		float JumpHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics", meta = (AllowPrivateAccess = "true"))
		float FrictionCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics", meta = (AllowPrivateAccess = "true"))
		float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics", meta = (AllowPrivateAccess = "true"))
		float LineTraceLength;

	// BlueprintReadWrite

#pragma region Unused


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unused", meta = (AllowPrivateAccess = "true"))
		bool PhysicsEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unused", meta = (AllowPrivateAccess = "true"))
		bool CanMove;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Unused", meta = (AllowPrivateAccess = "true"))
		bool DisableSnowboard;
#pragma endregion
};

