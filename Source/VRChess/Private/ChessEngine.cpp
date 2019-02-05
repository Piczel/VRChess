// Fill out your copyright notice in the Description page of Project Settings.

#include "ChessEngine.h"
#include "Misc/InteractiveProcess.h"


// Sets default values
AChessEngine::AChessEngine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FString tempPathToExecutable = FString("C:\\Users\\maker\\Documents\\Unreal Projects\\samuel.eckerrot\\VRChess\\External\\stockfish-10-win\\Windows\\stockfish_10_x64.exe");

	StockFishProcess = new FInteractiveProcess(tempPathToExecutable, FString(""), true);

}

AChessEngine::~AChessEngine()
{
	StockFishProcess->Stop();
	delete StockFishProcess;
}

// Called when the game starts or when spawned
void AChessEngine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChessEngine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChessEngine::StartEngine()
{
	
	StockFishProcess->Launch();

	StockFishProcess->OnOutput().BindUObject(this, &AChessEngine::HandleOutput);
	StockFishProcess->OnCanceled().BindUObject(this, &AChessEngine::ShowTerminatedMessage);

	StockFishProcess->SendWhenReady(FString("uci"));
}

void AChessEngine::HandleOutput(const FString &Message)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *Message);
	OnOutput(*Message);
}

void AChessEngine::ShowTerminatedMessage()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Process is terminated by an outsider"));
}

void AChessEngine::ShowCompletedMessage()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Process is completed"));
}

void AChessEngine::SendCommand(const FString Command)
{
	StockFishProcess->SendWhenReady(Command);
}

