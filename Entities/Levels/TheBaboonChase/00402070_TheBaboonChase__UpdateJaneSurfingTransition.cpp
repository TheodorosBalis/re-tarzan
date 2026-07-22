#include "tarzan_ghidra_types.hpp"

// Address: 0x00402070
// Label: TheBaboonChase::UpdateJaneSurfingTransition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::UpdateJaneSurfingTransition(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = ((EntitySceneObject *)value)->next;
    if (value2 != 0) {
      *(undefined2 *)(value2 + 0xa2) = ((EntitySceneObject *)value)->yaw;
      GetSceneAttachmentWorldPositionByIndex(value,(int *)value2 + 0x14,7);
    }
    if ((*(short *)(entry + 0x48) == 2) && (((EntitySceneObject *)value)->surfacePathIndex != -1)) {
      CEntities::MoveEntitySceneObjectAndSnapFacingAngles(entry,0xa0);
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58);
      if ((((EntitySceneObject *)value)->surface != 0) && ((*(byte *)(((EntitySceneObject *)value)->surface + 0x14) & 1) != 0))
      {
        g_PlayerSequenceFlags = 0;
        g_CameraOverrideTargetPtr = 0;
        *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
        *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
        *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
        *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
        *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
        *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
        g_PlayerCurrentCollisionMode =
             CPlayerHero::ApplyPlacementDescriptorToEntitySceneObject(g_PlayerEntitySceneObject,(int)&DAT_004bc670);
        value2 = g_PlayerEntitySceneObjectData;
        value = g_PlayerEntitySceneObject;
        g_PlayerMoveHeadingAngle = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2);
        *(undefined4 *)(g_PlayerEntitySceneObject + 0x48) =
             *(undefined4 *)(g_PlayerEntitySceneObjectData + 8);
        *(undefined4 *)(value + 0x4c) = *(undefined4 *)(value2 + 0xc);
        *(undefined4 *)(value + 0x50) = *(undefined4 *)(value2 + 0x10);
        CPlayerHero::EnterTarzanSurfingWithJaneMode();
        CCamera::Update(1);
        CEntities::ReleaseEntityToFreeList((byte *)entry);
      }
    }
  }
  return;
}

