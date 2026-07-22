#include "tarzan_ghidra_types.hpp"

// Address: 0x00403130
// Label: TheBaboonChase::UpdateBreakableBranch
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::UpdateBreakableBranch(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  int *intCursor;
  int value3;
  int value4;
  int value5;
  int value6;
  uint value7;
  undefined1 localState2 [4];
  undefined1 localState [16];
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (((value != 0) && (*(int *)(value + 0xc) == 0)) &&
     (resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_PlayerEntitySceneObject,0x200,entity->sceneObjects,0x200,
                         localState2,localState), resultFlag != '\0')) {
    *(undefined4 *)(value + 0xc) = 1;
    g_PlayerFacingCurrentCollisionSurface = 1;
    g_JaneDamageReactionType = 3;
    QueuePlayerDamageEvent(entry,7);
    PlayAudioById(0x259,(int *)0,(undefined4 *)0);
    PlayForceFeedbackEffect_Stub(0,0x10,0x10);
    value2 = entity->sceneObjects;
    value2 = CEntities::SpawnEntityByTypeAtPosition
                      (((EntitySceneObject *)value2)->x + *(int *)(value + 0x14),((EntitySceneObject *)value2)->y
                       ,((EntitySceneObject *)value2)->z,0x14,0x11);
    if (value2 != 0) {
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x6c) = 0xffffff80;
    }
    value2 = entity->sceneObjects;
    intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                              (((EntitySceneObject *)value2)->x + *(int *)(value + 0x14),
                               ((EntitySceneObject *)value2)->y + 0x100,((EntitySceneObject *)value2)->z,0x178,
                               0x11);
    if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
      *(undefined4 *)(intCursor[0xe] + 0x10) = g_CurrentWorldSceneContext;
      *(undefined2 *)(intCursor[0xe] + 0xc) = 0x2005;
      value2 = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000);
      if (value2 != 0) {
        ((EntitySceneObject *)value2)->next = *(int *)(entity->sceneObjects + 0x18) + 0x200;
      }
    }
    value2 = 0;
    do {
      value5 = entity->sceneObjects;
      value7 = 0;
      value3 = RandomModulo(0x100,0x160,0x11);
      value6 = *(int *)(entity->sceneObjects + 0x1c);
      value4 = RandomModulo(0x100);
      value5 = CEntities::SpawnEntityByTypeAtPosition
                        (((EntitySceneObject *)value5)->x + *(int *)(value + 0x14),
                         ((EntitySceneObject *)value5)->y + 0x80,(value6 - value3) + value4);
      if (value2 == 0) {
        value7 = GetAngleFromXZVector12Bit
                           ((g_CameraFocusX >> 8) - *(int *)(entity->sceneObjects + 0x14),
                            (g_CameraFocusZ >> 8) - *(int *)(entity->sceneObjects + 0x1c));
      }
      if (value5 != 0) {
        *(undefined4 *)(*(int *)(value5 + 0x38) + 0x10) = g_CurrentWorldSceneContext;
        *(undefined2 *)(*(int *)(value5 + 0x38) + 0xc) = 0x2006;
        value6 = CEntities::FindEntityAttachmentByFlags(value5,0x20000000);
        if (value6 != 0) {
          if (value2 == 0) {
            *(int *)(value6 + 0x40) =
                 (short)(&g_SinCosTable12Bit)[value7 - 0x400 & 0xfff] * 0x32 >> 0xc;
            shortValue = (&g_SinCosTable12Bit)[value7 & 0xfff];
          }
          else {
            *(int *)(value6 + 0x40) =
                 (short)(&g_SinCosTable12Bit)[value2 * 0x200 - 0x200U & 0xfff] * 0x32 >> 0xc;
            shortValue = (&g_SinCosTable12Bit)[(value2 + 1U & 7) * 0x200];
          }
          *(int *)(value6 + 0x44) = shortValue * 0x32 >> 0xc;
          shortValue = RandomModulo(0x100);
          *(short *)(value6 + 0x54) = shortValue + 0x7f;
          shortValue = RandomModulo(0x100);
          *(short *)(value6 + 0x56) = shortValue + 0x80;
          *(short *)(*(int *)(value5 + 0x38) + 0xa2) = ((short)value2 + 1) * 0x200;
          *(undefined2 *)(*(int *)(value5 + 0x38) + 0xa0) = 0x400;
          *(undefined4 *)(value6 + 0x18) = 0x32;
          *(undefined4 *)(value6 + 0x10) = 0;
        }
      }
      value2 = value2 + 1;
    } while (value2 < 6);
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

