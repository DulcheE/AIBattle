#include "AIAgentController.h"

AAIAgentController::AAIAgentController() { }


void AAIAgentController::SetTeam(bool bIsTeam1)
{
	this->SetGenericTeamId(FGenericTeamId(bIsTeam1 ? 1 : 2));
}


ETeamAttitude::Type AAIAgentController::GetTeamAttitudeTowards(const AActor& Other) const
{
	if (const AAIController* OtherController = Cast<AAIController>(Cast<APawn>(&Other)->GetController())) {
		return Super::GetTeamAttitudeTowards(*OtherController);
	}

	return ETeamAttitude::Neutral;
}