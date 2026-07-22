#include "tarzan_ghidra_types.hpp"

// Address: 0x00476180
// Label: KerchakChase::InitChargingAnimal
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::InitChargingAnimal(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  short *value3;
  int value;
  int value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x10,0x10000000);
  if (value != 0) {
    *(undefined4 *)(entity->sceneObjects + 0x10) = g_CurrentWorldSceneContext;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200b;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 2;
    *(undefined4 *)(value + 0xc) = 0;
    value = entity->sceneObjects;
    value2 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value);
    ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + value2;
    intCursor = (int *)(entity->sceneObjects + 0x18);
    *intCursor = *intCursor + -0x19c;
    CEntities::MoveEntityForwardAndSnapFacingYaw(entry,0x40);
    value3 = (short *)(entity->sceneObjects + 0xa0);
    *value3 = *value3 + -0x40;
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  }
  return;
}

