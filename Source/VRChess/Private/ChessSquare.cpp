// Fill out your copyright notice in the Description page of Project Settings.

#include "ChessSquare.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "ChessPawn.h"

// Sets default values
AChessSquare::AChessSquare()
{
 	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionResponseToAllChannels(ECR_Block);
	RootComponent = MeshComp;

}

void AChessSquare::UseMaterial(UMaterialInstance* Material)
{
	MeshComp->SetMaterial(0, Material);
}

void AChessSquare::HandlePawnOverlap(AChessPawn* Pawn)
{

	// Snapping
	Pawn->SetActorLocation(GetActorLocation());
	Pawn->SetActorRotation(GetActorRotation());
	
}
