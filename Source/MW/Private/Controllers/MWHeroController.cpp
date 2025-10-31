// JIH


#include "Controllers/MWHeroController.h"

AMWHeroController::AMWHeroController()
{
    HeroTeamId = FGenericTeamId(0);
}

FGenericTeamId AMWHeroController::GetGenericTeamId() const
{
    return HeroTeamId;
}
