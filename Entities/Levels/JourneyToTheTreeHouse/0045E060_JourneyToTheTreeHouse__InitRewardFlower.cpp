#include "tarzan_ghidra_types.hpp"

// Address: 0x0045E060
// Label: JourneyToTheTreeHouse::InitRewardFlower
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitRewardFlower(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  byte flagByte;
  int value2;
  int value3;
  int value4;
  
  value3 = entity->sceneObjects;
  flagByte = *(byte *)(*(int *)(entity->descriptor + 0x10) + 4);
  *(byte *)(entry + 0x3d) = flagByte;
  value4 = flagByte - 6;
  value = value4 * 0x18;
  *(undefined2 *)(value3 + 0xa0) =
       *(undefined2 *)(&g_JourneyToTheTreeHouse_InitRewardFlower_Global_00505028 + value4 * 0x18);
  ((EntitySceneObject *)value3)->yaw = *(undefined2 *)(&DAT_0050502a + value);
  ((EntitySceneObject *)value3)->pitch = *(undefined2 *)(&DAT_0050502c + value);
  ((EntitySceneObject *)value3)->roll = 0;
  *(undefined2 *)(entry + 0x48) = 0;
  value4 = g_CurrentWorldSceneContext;
  if (*(int *)(&DAT_00505020 + value) != 0x8000) {
    value4 = g_WorldEntitySceneObjectArrayBase + *(int *)(&DAT_00505020 + value) * 0x68;
  }
  ((EntitySceneObject *)value3)->worldObject = value4;
  *(undefined2 *)(value3 + 0xc) = *(undefined2 *)(&DAT_00505024 + value);
  value4 = ResolveCollisionSurfaceIndexByCoordRef
                    (*(undefined4 *)(&g_JourneyToTheTreeHouseRewardFlowerConfigTable + value));
  value3 = g_CollisionSurfaceTable + 4;
  value2 = ResolveCollisionSurfaceIndexByCoordRef
                    (*(undefined4 *)(&g_JourneyToTheTreeHouseRewardFlowerConfigTable + value));
  value3 = *(int *)(value3 + value4 * 4) + 4 + value2 * 4 + g_CollisionSurfaceTable;
  if ((value3 == 0) || (value = value3 + 0x30 + *(int *)(&DAT_0050501c + value) * 0x1c, value == 0)) {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
  }
  else {
    *(uint *)(value + 0x14) = *(uint *)(value + 0x14) & 0xfffffeff;
    if (*(char *)(entry + 0x3d) != '\x06') {
      CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
      return;
    }
  }
  return;
}

