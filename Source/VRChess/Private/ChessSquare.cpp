// Fill out your copyright notice in the Description page of Project Settings.

#include "ChessSquare.h"

// Sets default values
AChessSquare::AChessSquare()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChessSquare::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChessSquare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

