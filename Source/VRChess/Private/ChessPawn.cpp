// Fill out your copyright notice in the Description page of Project Settings.

#include "ChessPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/EngineTypes.h"

// Sets default values
AChessPawn::AChessPawn()
{

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	MeshComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void AChessPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AChessPawn::PickUp(USceneComponent* AttachTo)
{
	MeshComp->SetMaterial(0, MaterialGrabbing);
	MeshComp->SetSimulatePhysics(false);
	
	GetRootComponent()->AttachToComponent(AttachTo, FAttachmentTransformRules::KeepWorldTransform);
}

void AChessPawn::Drop()
{
	MeshComp->SetMaterial(0, MaterialDefault);
	MeshComp->SetSimulatePhysics(true);

	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
}


