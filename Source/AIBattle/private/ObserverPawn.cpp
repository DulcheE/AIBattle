// Fill out your copyright notice in the Description page of Project Settings.


#include "ObserverPawn.h"


#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AObserverPawn::AObserverPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	
	this->SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	this->SpringArm->SetupAttachment(this->RootComponent);

	this->SpringArm->SetRelativeLocation(FVector(0, 0, 1000));
	this->SpringArm->SetRelativeRotation(FRotator(-90, 0, 180));


	this->Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	this->Camera->SetupAttachment(this->SpringArm);
}


 void AObserverPawn::OnConstruction(const FTransform& Transform)
 {
	 this->SpringArm->TargetArmLength = this->Height;
 }



void AObserverPawn::GetActorEyesViewPoint(FVector& OutLocation, FRotator& OutRotation) const
{
	OutLocation = this->Camera->GetComponentLocation();
	OutRotation = this->Camera->GetComponentRotation() - this->Camera->GetRelativeRotation();
}


void AObserverPawn::SetHeight(float NewHeight)
{
	this->Height = FMath::Clamp<float>(NewHeight, 1000, 7000);

	this->SpringArm->TargetArmLength = Height;
}




// Called when the game starts or when spawned
void AObserverPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObserverPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AObserverPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

