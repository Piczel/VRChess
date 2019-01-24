// Fill out your copyright notice in the Description page of Project Settings.

#include "ChessBoard.h"
#include "ChessSquare.h"
#include "Materials/MaterialInstance.h"

// Sets default values
AChessBoard::AChessBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

}

// Called when the game starts or when spawned
void AChessBoard::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < 64; i++)
	{
		int x = i % 8;
		int y = (i / 8) % 8;

		const FVector Scale = GetActorScale();

		// Calculate its local transformation
		FVector SquareLocation =
			FVector(
				SQUARE_PHYSICAL_SIZE * x * Scale.X,
				SQUARE_PHYSICAL_SIZE * y * Scale.Y,
				0
			);

		// Transform it to the location of the chess board
		SquareLocation += GetActorLocation();

		// Spawn square
		AChessSquare* Square = GetWorld()->SpawnActor<AChessSquare>(SquareLocation, GetActorRotation());

		// Assign its material
		if (i % 2) {
			Square->UseMaterial(MaterialSquareBlack);
		}
		else {
			Square->UseMaterial(MaterialSquareWhite);
		}

		// Store in array
		ChessSquares[i] = Square;
	}
}

// Called every frame
void AChessBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


