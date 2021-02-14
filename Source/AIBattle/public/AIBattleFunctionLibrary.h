// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "AIBattleFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class AIBATTLE_API UAIBattleFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	
public:
	
	UFUNCTION(BlueprintCallable, Category = "AIBattleFunctionLibrary")
    static TArray<UObject*>  LoadObjectLibrary(const FString& Path, TSubclassOf<UObject> ObjectClass);
     
};
 
 
