// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessPawn.generated.h"

class UStaticMeshComponent;
class UMaterialInstance;
class USceneComponent;

UCLASS()
class VRCHESS_API AChessPawn : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AChessPawn();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInstance* MaterialDefault;

	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInstance* MaterialGrabbing;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	

public:	

	UPROPERTY(EditAnywhere, Category = "Chess")
	bool isGrabbed;

	UPROPERTY(EditAnywhere, Category = "Chess")
	bool isStatic = true;

	UFUNCTION(BlueprintCallable)
	void PickUp(USceneComponent* AttachTo);

	UFUNCTION(BlueprintCallable)
	void Drop();

};
