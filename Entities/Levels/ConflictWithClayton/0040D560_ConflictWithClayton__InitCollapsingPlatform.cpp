#include "tarzan_ghidra_types.hpp"

// Address: 0x0040D560
// Label: ConflictWithClayton::InitCollapsingPlatform
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ConflictWithClayton::InitCollapsingPlatform(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  byte flagByte;
  int value2;
  int value3;
  int value4;
  uint value5;
  
  value2 = entity->sceneObjects;
  flagByte = *(byte *)(*(int *)(entity->descriptor + 0x10) + 4);
  *(undefined2 *)(entry + 0x4a) = 0;
  *(byte *)(entry + 0x3d) = flagByte;
  value5 = (uint)flagByte;
  ((EntitySceneObject *)value2)->roll = 0;
  value = value5 * 0x24;
  ((EntitySceneObject *)value2)->yaw =
       *(undefined2 *)(&g_ConflictCollapsingPlatformConfigFacingAngle + value5 * 0x24);
  *(undefined2 *)(entry + 0x48) = 0;
  value3 = g_CurrentWorldSceneContext;
  if ((&PTR_ConflictWithClayton__InitializeBattle_004c0e60)[value5 * 9] != (undefined *)0x8000) {
    value3 = g_WorldEntitySceneObjectArrayBase +
            (int)(&PTR_ConflictWithClayton__InitializeBattle_004c0e60)[value5 * 9] * 0x68;
  }
  ((EntitySceneObject *)value2)->worldObject = value3;
  *(undefined2 *)(value2 + 0xc) = *(undefined2 *)(&DAT_004c0e64 + value);
  *(undefined2 *)(entry + 0x4a) = *(undefined2 *)(&DAT_004c0e66 + value);
  value3 = ResolveCollisionSurfaceIndexByCoordRef
                    (*(undefined4 *)(&g_ConflictWithClaytonCollapsingPlatformConfigTable + value));
  value2 = g_CollisionSurfaceTable + 4;
  value4 = ResolveCollisionSurfaceIndexByCoordRef
                    (*(undefined4 *)(&g_ConflictWithClaytonCollapsingPlatformConfigTable + value));
  value2 = *(int *)(value2 + value3 * 4) + value4 * 4 + g_CollisionSurfaceTable + 0x34 +
          *(int *)(&DAT_004c0e50 + value) * 0x1c;
  if (value2 == 0) {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    return;
  }
  *(int *)(value2 + 4) = -*(int *)(&DAT_004c0e54 + value);
  ((EntitySceneObject *)value2)->x = ((EntitySceneObject *)value2)->x & 0xfffffeff | 0x80;
  CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
  return;
}

