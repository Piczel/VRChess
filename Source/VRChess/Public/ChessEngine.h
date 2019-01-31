// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessEngine.generated.h"

class FInteractiveProcess;

UENUM(BlueprintType)
enum class EChessEngineState : uint8
{
	E_STARTING				UMETA(DisplayName = "Starting"),
	E_WAITING_FOR_POSITION	UMETA(DisplayName = "Waiting for position"),
	E_WAITING_FOR_COMMAND	UMETA(DisplayName = "Waiting for command"),
	E_CALCULATING_MOVE		UMETA(DisplayName = "Calculating move")
};

UCLASS()
class VRCHESS_API AChessEngine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChessEngine();
	~AChessEngine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FInteractiveProcess* StockFishProcess;

	void HandleOutput(const FString &Message);
	void ShowTerminatedMessage();
	void ShowCompletedMessage();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SendCommand(const FString Command);

	UFUNCTION(BlueprintCallable)
	void StartEngine();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOutput(const FString &Message);
};
