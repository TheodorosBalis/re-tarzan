#include "tarzan_ghidra_types.hpp"

// Address: 0x00428CF0
// Label: ElephantHairDare::InitElephantWaterSplashColumn
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::InitElephantWaterSplashColumn(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value2;
  int value;
  
  value = CEntities::CreateEntityAttachment(entry,0x18,0x10000000);
  if (value != 0) {
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    value2 = (byte *)(entity->sceneObjects + 0xf);
    *value2 = *value2 | 0xc;
    *(undefined4 *)(entity->sceneObjects + 0x30) = 0x1000;
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1450;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200e;
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
    *(undefined4 *)(entity->sceneObjects + 0xa8) = 0xfff;
    *(undefined4 *)(entity->sceneObjects + 0xac) = 0;
    *(undefined4 *)(entity->sceneObjects + 0xb0) = 0xfff;
    *(undefined4 *)(value + 0xc) = 0;
    ((EntitySceneObject *)value)->worldObject = 0;
    value = entity->sceneObjects;
    CEntities::SpawnEntityByTypeAtPosition
              (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
               ((EntitySceneObject *)value)->z,0x85,0x11);
    value = entity->sceneObjects;
    value = CEntities::SpawnEntityByTypeAtPosition
                      (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                       ((EntitySceneObject *)value)->z,0x85,0x11);
    if (value != 0) {
      *(undefined2 *)(value + 0x48) = 1;
    }
  }
  return;
}

