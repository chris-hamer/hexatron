// Fill out your copyright notice in the Description page of Project Settings.

#include "Hexatron.h"
#include "Vis.h"


// Sets default values
AVis::AVis()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	RootComponent = Arrow;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Arrow);
}

// Called when the game starts or when spawned
void AVis::BeginPlay()
{
	Super::BeginPlay();

	if (!FFileHelper::LoadANSITextFileToStrings(TEXT("U:\\Hexatron\\data.txt"), NULL, lines)) {
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "FAIL");
		return;
	}
	for (int i = 1; i < lines.Num(); i++) {
		//GEngine->AddOnScreenDebugMessage(-1, 333333333, FColor::Cyan, lines[i]);
	}
	CurrentLine = 1;
}

// Called every frame
void AVis::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//GEngine->AddOnScreenDebugMessage(-1, 333333333, FColor::Cyan, FString::SanitizeFloat(CurrentLine));
	TArray<FString> Data;
	lines[CurrentLine].ParseIntoArrayWS(Data);

	if (!Data.Num()) {
		return;
	}

	float pitch = FCString::Atof(Data[2].GetCharArray().GetData());
	float yaw = FCString::Atof(Data[3].GetCharArray().GetData());
	float roll = FCString::Atof(Data[1].GetCharArray().GetData());
	Mesh->SetWorldRotation(FRotator(pitch, yaw, roll));
	CurrentLine++;
	CurrentLine %= lines.Num()-1;
	if (CurrentLine == 0) CurrentLine++;
}

