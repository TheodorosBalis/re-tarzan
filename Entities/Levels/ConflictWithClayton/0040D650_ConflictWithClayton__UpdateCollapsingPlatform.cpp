#include "tarzan_ghidra_types.hpp"

// Address: 0x0040D650
// Label: ConflictWithClayton::UpdateCollapsingPlatform
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ConflictWithClayton::UpdateCollapsingPlatform(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  int value;
  undefined4 *dataCursor;
  short shortValue;
  char resultFlag;
  uint value5;
  int value2;
  int value3;
  int value4;
  
  value5 = (uint)*(byte *)(entry + 0x3d);
  value4 = entity->sceneObjects;
  value = value5 * 0x24;
  dataCursor = (undefined4 *)(&g_ConflictWithClaytonCollapsingPlatformConfigTable + value);
  if (*(short *)(entry + 0x48) == 1) {
    shortValue = *(short *)(entry + 0x4a);
    if (shortValue == 0) {
      *(undefined2 *)(entry + 0x48) = 2;
      PlayAudioById(0xd6,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
      value2 = ResolveCollisionSurfaceIndexByCoordRef(*dataCursor);
      value4 = g_CollisionSurfaceTable + 4;
      value3 = ResolveCollisionSurfaceIndexByCoordRef(*dataCursor);
      value4 = *(int *)(value4 + value2 * 4) + 4 + value3 * 4 + g_CollisionSurfaceTable;
      *(uint *)(value4 + *(int *)(&DAT_004c0e50 + value) * 0x1c + 0x44) =
           *(uint *)(value4 + 0x44 + *(int *)(&DAT_004c0e50 + value) * 0x1c) & 0xffffff7f | 0x100;
      *(undefined2 *)(entry + 0x4a) = 8;
      goto LAB_0040d7c1;
    }
  }
  else {
    if (*(short *)(entry + 0x48) == 2) {
      *(short *)(value4 + 0xa0) = *(short *)(value4 + 0xa0) + *(short *)(&DAT_004c0e6a + value);
      ((EntitySceneObject *)value4)->pitch = ((EntitySceneObject *)value4)->pitch + *(short *)(&DAT_004c0e6c + value);
      *(short *)(entry + 0x4a) = *(short *)(entry + 0x4a) + 6;
      ((EntitySceneObject *)value4)->y = ((EntitySceneObject *)value4)->y + (uint)*(ushort *)(entry + 0x4a);
      goto LAB_0040d7c1;
    }
    if ((*(byte *)(entry + 0x42) & 0x80) == 0) goto LAB_0040d7c1;
    shortValue = *(short *)(entry + 0x4a);
    if (shortValue == 0) {
      *(undefined2 *)(entry + 0x48) = 1;
      PlayAudioById(0xd5,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
      *(short *)(value4 + 0xa0) = *(short *)(value4 + 0xa0) + *(short *)(&DAT_004c0e6a + value);
      ((EntitySceneObject *)value4)->pitch = ((EntitySceneObject *)value4)->pitch + *(short *)(&DAT_004c0e6c + value);
      *(undefined **)(&((EntitySceneObject *)value4)->y) =
           (&PTR_ConflictWithClayton__InitializeBattle_004c0e5c)[value5 * 9] + ((EntitySceneObject *)value4)->y
      ;
      *(undefined2 *)(entry + 0x4a) = *(undefined2 *)(&DAT_004c0e68 + value);
      value2 = ResolveCollisionSurfaceIndexByCoordRef(*dataCursor);
      value4 = g_CollisionSurfaceTable + 4;
      value3 = ResolveCollisionSurfaceIndexByCoordRef(*dataCursor);
      intCursor = (int *)(g_CollisionSurfaceTable + value3 * 4 + *(int *)(value4 + value2 * 4) +
                       *(int *)(&DAT_004c0e50 + value) * 0x1c + 0x38);
      *intCursor = (int)((&PTR_ConflictWithClayton__ActivateDescriptorNearPlayerHeight_004c0e58)
                      [value5 * 9] + *intCursor);
      CEntities::UnlinkEntityFromProcessingList(entry);
      goto LAB_0040d7c1;
    }
  }
  *(short *)(entry + 0x4a) = shortValue + -1;
LAB_0040d7c1:
  if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\r') {
    resultFlag = IsEntityOutsideOuterActivationBounds(entry);
    if (resultFlag != '\0') {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
  }
  else {
    resultFlag = IsEntityOutsideOuterActivationBounds(entry);
    if (resultFlag != '\0') {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
  }
  return;
}

