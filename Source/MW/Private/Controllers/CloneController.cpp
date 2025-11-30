// JIH


#include "Controllers/CloneController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "MWDebugHelper.h"

ACloneController::ACloneController()
{
	AISenseConfig_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("CloneSenseConfig_Sight"));
	AISenseConfig_Sight->DetectionByAffiliation.bDetectEnemies = true;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectFriendlies = false;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectNeutrals = false;
	AISenseConfig_Sight->SightRadius = 250.f;
	AISenseConfig_Sight->LoseSightRadius = 250.f;
	AISenseConfig_Sight->PeripheralVisionAngleDegrees = 360.f;

	ClonePerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("ClonePerceptionComponent"));
	ClonePerceptionComponent->ConfigureSense(*AISenseConfig_Sight);
	ClonePerceptionComponent->SetDominantSense(UAISenseConfig_Sight::StaticClass());
	ClonePerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &ThisClass::OnEnemyPerceptionUpdated);

	SetGenericTeamId(FGenericTeamId(2));
}

ETeamAttitude::Type ACloneController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const APawn* PawnToCheck = Cast<const APawn>(&Other);

	const IGenericTeamAgentInterface* OtherTeamAgent = Cast<const IGenericTeamAgentInterface>(PawnToCheck->GetController());

	if (OtherTeamAgent && OtherTeamAgent->GetGenericTeamId() % 2 != GetGenericTeamId() % 2)
	{
		return ETeamAttitude::Hostile;
	}

	return ETeamAttitude::Friendly;
}

void ACloneController::OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{

	Debug::Print(TEXT("Enemy Perception Updated"));

	if (UBlackboardComponent* BlackboardComponent = GetBlackboardComponent())
	{
		AActor* TargetActor = Cast<AActor>(BlackboardComponent->GetValueAsObject(FName("TargetActor")));

		if (Stimulus.WasSuccessfullySensed())
		{
			if (!TargetActor && Actor)
			{
				BlackboardComponent->SetValueAsObject(FName("TargetActor"), Actor);
			}
		}
		else
		{
			if (TargetActor == Actor)
			{
				BlackboardComponent->SetValueAsObject(FName("TargetActor"), nullptr);
			}
		}
	}
}
