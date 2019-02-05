// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessPawn.generated.h"

class UStaticMeshComponent;
class UMaterialInstance;
class USceneComponent;

UENUM(BlueprintType)
enum class EPawnType : uint8
{
	E_Pawn		UMETA(DisplayName = "Pawn"),
	E_Rook		UMETA(DisplayName = "Rook"),
	E_Knight	UMETA(DisplayName = "Knight"),
	E_Bishop	UMETA(DisplayName = "Bishop"),
	E_Queen		UMETA(DisplayName = "Queen"),
	E_King		UMETA(DisplayName = "King")
};

UENUM(BlueprintType)
enum class EPawnColor : uint8
{
	E_White		UMETA(DisplayName = "White"),
	E_Black		UMETA(DisplayName = "Black")
};

UCLASS()
class VRCHESS_API AChessPawn : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AChessPawn();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInstance* MaterialDefault;

	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInstance* MaterialGrabbing;

	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	bool isGrabbed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	bool isStatic = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	EPawnType PawnType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	EPawnColor PawnColor;
	
	UFUNCTION(BlueprintCallable)
	void PawnPickUp(USceneComponent* AttachTo);
	 
	UFUNCTION(BlueprintCallable)
	void PawnDrop();

};
