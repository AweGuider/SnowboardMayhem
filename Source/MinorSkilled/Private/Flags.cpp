// Fill out your copyright notice in the Description page of Project Settings.


#include "Flags.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Snowboarder.h"
#include "HighScoreManager.h"

// Sets default values
AFlags::AFlags()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Initialize components and set up collision
    //LeftFlag = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftFlag"));
    //RightFlag = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightFlag"));
    //TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));

    //RootComponent = LeftFlag;
    //RightFlag->SetupAttachment(RootComponent);
    //TriggerVolume->SetupAttachment(RootComponent);

    //TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &AFlags::OnPlayerPassThrough);
}

// Called when the game starts or when spawned
void AFlags::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AFlags::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AFlags::InitializeComponents(UStaticMeshComponent* LeftFlagMesh, UStaticMeshComponent* RightFlagMesh, UBoxComponent* BoxCollision)
{
    LeftFlag = LeftFlagMesh;
    RightFlag = RightFlagMesh;
    TriggerVolume = BoxCollision;

}

void AFlags::OnPlayerPassThrough(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    //if (GEngine)
    //    GEngine->AddOnScreenDebugMessage(-1, 15.0f, 
    //        FColor::Yellow, 
    //        FString::Printf(TEXT("Got in OnPlayerPassThrough %f"), GetWorld()->TimeSeconds));
    if (OtherActor && OtherActor->IsA(ASnowboarder::StaticClass()) && !bIsTriggered)
    {
        //if (GEngine)
        //    GEngine->AddOnScreenDebugMessage(-1, 15.0f,
        //        FColor::Yellow,
        //        FString::Printf(TEXT("Correct Actor %f"), GetWorld()->TimeSeconds));

        // Change flags to green
        //LeftFlag->SetMaterial(0, GreenMaterial);
        //RightFlag->SetMaterial(0, GreenMaterial);

        // Increase score
        //UHighScoreManager* ScoreManager = Cast<UHighScoreManager>(UGameplayStatics::GetActorOfClass(GetWorld(), UHighScoreManager::StaticClass()));
        //if (ScoreManager)
        //{
        //    if (GEngine)
        //        GEngine->AddOnScreenDebugMessage(-1, 15.0f,
        //            FColor::Yellow,
        //            FString::Printf(TEXT("Reached Score Manager %f"), GetWorld()->TimeSeconds));

        //    ScoreManager->UpdateHighScore(1);
        //}

        UHighScoreManager* ScoreManager = UHighScoreManager::GetInstance();
        ScoreManager->UpdateHighScore(1);

        bIsTriggered = true;
    }
}

