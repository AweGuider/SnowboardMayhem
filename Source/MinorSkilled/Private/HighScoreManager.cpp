// Fill out your copyright notice in the Description page of Project Settings.


#include "HighScoreManager.h"

UHighScoreManager* UHighScoreManager::GetInstance()
{
    if (!Instance)
    {
        Instance = NewObject<UHighScoreManager>();
        Instance->AddToRoot();  // Prevent garbage collection
        Instance->Initialize();
    }
    return Instance;
}

UHighScoreManager::UHighScoreManager()
{
    //HighScore = 0;  // Default high score
    //Initialize();
}

void UHighScoreManager::Initialize()
{
    // Load high score from a save file or initialize to a default value
    RandomHighScore();  // Example random initialization
}

void UHighScoreManager::RandomHighScore()
{
    HighScore = FMath::Rand() % 1000;  // Example random initialization

}

void UHighScoreManager::SetHighScore(int32 NewScore)
{
    if (NewScore > HighScore)
    {
        HighScore = NewScore;
        // Optionally save the new high score here
    }
}

void UHighScoreManager::ResetHighScore()
{

    HighScore = 0;
}


void UHighScoreManager::UpdateHighScore(int32 ScoreChange)
{
    if (ScoreChange > 0)
    {
        HighScore += ScoreChange;
        // Optionally save the new high score here
    }
}
