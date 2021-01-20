// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "ObserverPawn.generated.h"

UCLASS()
class AIBATTLE_API AObserverPawn : public APawn
{
	GENERATED_BODY()

	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	class USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	class UCameraComponent* Camera = nullptr;

	
	UPROPERTY(EditAnywhere, BlueprintGetter="GetHeight", BlueprintSetter="SetHeight", Category="Observer")
	float Height = 7000.f;
	

public:
	
	// Sets default values for this pawn's properties
	AObserverPawn();
	
	virtual void OnConstruction(const FTransform& Transform) override;

	
	virtual void GetActorEyesViewPoint(FVector& OutLocation, FRotator& OutRotation) const override;

	UFUNCTION(BlueprintGetter)
	FORCEINLINE float GetHeight() const { return  this->Height; }

	UFUNCTION(BlueprintSetter)
	void SetHeight(float NewHeight);

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
