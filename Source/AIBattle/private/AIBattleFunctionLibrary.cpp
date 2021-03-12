// Fill out your copyright notice in the Description page of Project Settings.


#include "AIBattleFunctionLibrary.h"
#include "Engine.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"


TArray<UObject*> UAIBattleFunctionLibrary::LoadObjectLibrary(const FString& Path,  TSubclassOf<UObject> ObjectClass)
{
	TArray<UObject*> Assets;

	UObjectLibrary* ObjectLibrary = UObjectLibrary::CreateLibrary(ObjectClass, false, GIsEditor);
	if (ObjectLibrary != nullptr)
	{
 		ObjectLibrary->AddToRoot();
 		const FString NewPath = TEXT("/Game") / Path;
 		int32 NumOfAssetDatas = ObjectLibrary->LoadAssetDataFromPath(NewPath);
 		TArray<FAssetData> AssetDatas;
 		ObjectLibrary->GetAssetDataList(AssetDatas);

	 
 		UObject* Asset;

 		for (int32 i = 0; i < AssetDatas.Num(); ++i)
 		{
 			FAssetData& AssetData = AssetDatas[i];
 			Asset = AssetData.GetAsset();
 			if (Asset)
 			{
 				Assets.Add(AssetData.GetAsset());
 			}
 		}
	}

	
	return Assets;
}


void UAIBattleFunctionLibrary::GetBlackboardValueAsVectorLocation(UBTNode* NodeOwner, const FBlackboardKeySelector TargetKey, bool& bSucceeded, FVector& Location)
{
	bSucceeded = false;

	if (TargetKey.SelectedKeyType == UBlackboardKeyType_Object::StaticClass())
	{
		if (AActor* TargetActor = UBTFunctionLibrary::GetBlackboardValueAsActor(NodeOwner, TargetKey))
		{
			Location = TargetActor->GetActorLocation();
			bSucceeded = true;
		}
	}
	else if (TargetKey.SelectedKeyType == UBlackboardKeyType_Vector::StaticClass())
	{
		Location = UBTFunctionLibrary::GetBlackboardValueAsVector(NodeOwner, TargetKey);
		bSucceeded = true;
	}
}


void UAIBattleFunctionLibrary::SetBlackboardValueAsActorOrVector(UBTNode* NodeOwner, const FBlackboardKeySelector TargetKey, AActor* Actor, bool& bSucceeded)
{
	bSucceeded = false;

	if (TargetKey.SelectedKeyType == UBlackboardKeyType_Object::StaticClass())
	{
		UBTFunctionLibrary::SetBlackboardValueAsObject(NodeOwner, TargetKey, Actor);
		bSucceeded = true;
	}
	else if (TargetKey.SelectedKeyType == UBlackboardKeyType_Vector::StaticClass() && !!Actor)
	{
		UBTFunctionLibrary::SetBlackboardValueAsVector(NodeOwner, TargetKey, Actor->GetActorLocation());
		bSucceeded = true;
	}
}
