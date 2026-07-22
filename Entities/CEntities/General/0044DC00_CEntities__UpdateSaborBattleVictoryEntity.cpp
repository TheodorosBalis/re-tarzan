#include "tarzan_ghidra_types.hpp"

// Address: 0x0044DC00
// Label: CEntities::UpdateSaborBattleVictoryEntity
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateSaborBattleVictoryEntity(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort value;
  int entry2;
  char resultFlag;
  
  entry2 = entity->sceneObjects;
  resultFlag = IsWorldPositionOutsideOuterActivationBounds(&((EntitySceneObject *)entry2)->x);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  if (((g_PlayerActionState == 0x3f) && (value = *g_PlayerEntitySceneObjectData, 0x4b8 < value)) &&
     (value < 0x4d1)) {
    *(ushort *)(entry2 + 0xc) = value - 0x333;
  }
  return;
}

