#include "tarzan_ghidra_types.hpp"

// Address: 0x0040C130
// Label: CampsiteCommotion::InitBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitBox(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value2 = entity->sceneObjects;
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) ^ 3;
  if (value2 != 0) {
    ((EntitySceneObject *)value2)->worldObject = g_CurrentWorldSceneContext;
    ((EntitySceneObject *)value2)->roll = 1;
    if (entity->descriptor != 0) {
      value = *(int *)(entity->descriptor + 0x10);
      *(undefined2 *)(value2 + 0xc) =
           *(undefined2 *)(&g_CampsiteCommotionBoxModelTable + *(int *)(value + 4) * 2);
      if ((((EntitySceneObject *)value2)->pad108 == 1) && (*(int *)(g_PlayerEntitySceneObject + 0x108) == 1)) {
        ComputeEntitySceneObjectCollisionMoveDelta(0,0,value2);
        ((EntitySceneObject *)value2)->yaw = *(ushort *)(value2 + 0x132) ^ 0x800;
      }
      value2 = CEntities::CreateEntityAttachment(entry,0x18,0x10000004);
      if (value2 != 0) {
        *(undefined2 *)(value2 + 0xc) = 0;
        *(undefined2 *)(value2 + 0xe) = 0;
        ((EntitySceneObject *)value2)->worldObject = 3;
        *(undefined2 *)(value2 + 0x12) = *(undefined2 *)(value + 8);
        ((EntitySceneObject *)value2)->x = *(undefined2 *)(value + 0xc);
        *(undefined2 *)(value2 + 0x16) = *(undefined2 *)(value + 0x10);
      }
    }
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  }
  return;
}

