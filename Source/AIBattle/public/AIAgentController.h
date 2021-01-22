#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIAgentController.generated.h"

UCLASS()
class AIBATTLE_API AAIAgentController : public AAIController
{
	GENERATED_BODY()

	
public:
	
	AAIAgentController();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE uint8 GetTeam() const { return this->GetGenericTeamId().GetId(); }

	UFUNCTION(BlueprintCallable)
	void SetTeam(bool bIsTeam1);

	
	// Override this function 
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
};
