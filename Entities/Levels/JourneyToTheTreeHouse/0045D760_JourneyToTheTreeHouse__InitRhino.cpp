#include "tarzan_ghidra_types.hpp"

// Address: 0x0045D760
// Label: JourneyToTheTreeHouse::InitRhino
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitRhino(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 4;
  if ((*(byte *)(entry + 0x43) & 0x80) == 0) {
    LoadEncodedResourceId(0x100f);
    LoadEncodedResourceId(0x1010);
    value = entity->sceneObjects;
    if (value != 0) {
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3878;
      ((EntitySceneObject *)value)->roll = 1;
      *(undefined2 *)(value + 0x140) = 0x100;
      *(undefined1 *)(value + 0x75) = 0xff;
      CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
      CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_00504f08);
      *(undefined2 *)(entry + 0x48) = 0;
      *(undefined2 *)(entry + 0x4a) = 0;
      *(undefined4 *)(entry + 0x50) =
           *(undefined4 *)
            (*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value)->surfacePathIndex * 4) + 8 +
             ((EntitySceneObject *)value)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
    }
  }
  else {
    value = CEntities::CountEntitiesOfTypeInList(g_LevelEnemyEntityListHead,0x12d);
    if (value < 2) {
      UnloadEncodedResourceId(0x100f);
      return;
    }
  }
  return;
}

