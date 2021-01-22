#include "AIAgentController.h"

AAIAgentController::AAIAgentController() { }


void AAIAgentController::SetTeam(bool bIsTeam1)
{
	this->SetGenericTeamId(FGenericTeamId(bIsTeam1 ? 1 : 2));
}


ETeamAttitude::Type AAIAgentController::GetTeamAttitudeTowards(const AActor& Other) const
{
	UE_LOG(LogTemp, Warning, TEXT("[%s] GetTeamAttitudeTowards %s"), *this->GetName(), *Other.GetName());
	if (const AAIController* OtherController = Cast<AAIController>(Cast<APawn>(&Other)->GetController())) {
		ETeamAttitude::Type Attitude = Super::GetTeamAttitudeTowards(*OtherController);
		UE_LOG(LogTemp, Warning, TEXT("[%s] attitude %d"), *this->GetName(), Attitude);
		return Attitude;
	}

	return ETeamAttitude::Neutral;
}