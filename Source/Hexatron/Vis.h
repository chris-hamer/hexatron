// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Vis.generated.h"

UCLASS()
class HEXATRON_API AVis : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVis();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UArrowComponent* Arrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UStaticMeshComponent* Mesh;

	TArray<FString> lines;
	int CurrentLine;

};
