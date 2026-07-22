#include "tarzan_ghidra_types.hpp"

// Address: 0x0044E0F0
// Label: SaborAttacks::AdvanceSaborEncounterMovement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool SaborAttacks::AdvanceSaborEncounterMovement(int arg1,int arg2)

{
  Entity *entity = (Entity *)arg1;
  int count;
  int count2;
  
  count = entity->sceneObjects;
  count2 = ((EntitySceneObject *)count)->surfaceIndex;
  if (*(char *)(count + 0x75) == '\0') {
    count2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)count)->surfacePathIndex * 4) + 8 +
                     ((EntitySceneObject *)count)->surfacePathIndex * 4 + g_CollisionSurfaceTable) - count2;
  }
  if (count2 < 0x81) {
    arg2 = -arg2;
  }
  CEntities::MoveEntitySceneObjectAndEaseFacingAngles(arg1,arg2);
  CEntities::CheckEntitySceneObjectCollisionDelta(count);
  return count2 < 0x81;
}

