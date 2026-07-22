#include "tarzan_ghidra_types.hpp"

// Address: 0x004302C0
// Label: CEntities::RefreshAnimalFacingAndCollisionAfterTurn
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::RefreshAnimalFacingAndCollisionAfterTurn(undefined4 entry,undefined4 sceneObject)

{
  CEntities::MoveEntitySceneObjectAndSnapFacingAngles(entry,0);
  CEntities::CheckEntitySceneObjectCollisionDelta(sceneObject);
  return;
}

