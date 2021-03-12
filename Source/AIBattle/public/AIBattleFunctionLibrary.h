// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "AIBattleFunctionLibrary.generated.h"


class UBTNode;

/**
 * 
 */
UCLASS()
class AIBATTLE_API UAIBattleFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	
public:
	
	UFUNCTION(BlueprintCallable, Category = "AIBattleFunctionLibrary")
	static TArray<UObject*> LoadObjectLibrary(const FString& Path, TSubclassOf<UObject> ObjectClass);

	UFUNCTION(BlueprintPure, Category= "AI|BehaviorTree", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner", ShortToolTip="Return a vector or an actor location", ToolTip="Return a vector if the given KeySelector is of type vector or an actor location if is type of object"))
	static void GetBlackboardValueAsVectorLocation(UBTNode* NodeOwner, const FBlackboardKeySelector TargetKey, bool& bSucceeded, FVector& Location);

	UFUNCTION(BlueprintCallable, Category= "AI|BehaviorTree", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner", ShortToolTip="Set the actor or the actor location", ToolTip="Set to the value of the given KeySelector the given actor if it's type is object or the actor's location if is type of vector"))
    static void SetBlackboardValueAsActorOrVector(UBTNode* NodeOwner, const FBlackboardKeySelector TargetKey, AActor* Actor, bool& bSucceeded);
     
};
 
 
