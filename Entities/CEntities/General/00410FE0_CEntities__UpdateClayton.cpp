#include "tarzan_ghidra_types.hpp"

// Address: 0x00410FE0
// Label: CEntities::UpdateClayton
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateClayton(int entityAddress)

{
  Entity *entity = (Entity *)entityAddress;
  int sceneObjectAddress;
  
  g_ClaytonEntity = entityAddress;
  sceneObjectAddress = entity->sceneObjects;
  switch(g_ClaytonBattleBehaviorState) {
  case 0:
    CEntities::UpdateClaytonMainCombat(entityAddress,sceneObjectAddress);
    return;
  case 2:
  case 8:
    CEntities::UpdateClaytonPostHitRecovery(entityAddress,sceneObjectAddress);
    break;
  case 6:
    CEntities::UpdateClaytonPhaseTwoCombat(entityAddress,sceneObjectAddress);
    return;
  }
  return;
}

