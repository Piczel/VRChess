// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessSquare.generated.h"

class UStaticMeshComponent;
class AChessPawn;
class UMaterialInstance;

UCLASS()
class VRCHESS_API AChessSquare : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChessSquare();

protected:


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComp;

public:	

	UFUNCTION(BlueprintImplementableEvent, Category = "Chess")
	void OnChessPawnMoved(AChessPawn* MovedPawn);
	
	UFUNCTION(BlueprintCallable)
	void UseMaterial(UMaterialInstance* Material);

	UFUNCTION(BlueprintCallable)
	void Snap3D(AChessPawn* Pawn);
};
