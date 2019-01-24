// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessBoard.generated.h"

class AChessSquare;

UCLASS(Blueprintable)
class VRCHESS_API AChessBoard : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AChessBoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, Category = "Assets")
	UMaterialInstance* MaterialSquareWhite;
	UPROPERTY(EditAnywhere, Category = "Assets")
	UMaterialInstance* MaterialSquareBlack;

	UPROPERTY(EditDefaultsOnly, Category = "Chess")
	float SQUARE_PHYSICAL_SIZE = 6;

	AChessSquare* ChessSquares[64];


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
