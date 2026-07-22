#include "tarzan_ghidra_types.hpp"

// Address: 0x004666D0
// Label: TarzanToTheRescue::UpdateGorillaInTheCage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateGorillaInTheCage(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  short shortValue;
  int value;
  int *intCursor;
  int value2;
  int value3;
  int value4;
  short shortValue2;
  uint value5;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    switch(*(undefined4 *)(value + 0xc)) {
    case 0:
      *(short *)(entity->sceneObjects + 0xa4) =
           (short)((int)(short)(&g_SinCosTable12Bit)[*(int *)(value + 0x1c) - 0x400U & 0xfff] *
                   *(int *)(value + 0x14) >> 0xc);
      if (*(short *)(entity->sceneObjects + 0xa4) == 0) {
        PlayAudioById(0x388,(int *)0,(undefined4 *)0);
      }
      *(uint *)(value + 0x1c) = *(int *)(value + 0x18) + *(int *)(value + 0x1c) & 0xfff;
      if ((*(int *)(value + 0x20) == 0) && (g_TarzanToTheRescueTrackedKnifeEnemyGroupB0 == 0)) {
        *(undefined4 *)(value + 0xc) = 2;
        PlayAudioById(0x3b2,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      }
      if ((*(int *)(value + 0x20) == 1) && (g_TarzanToTheRescueScriptedPathPropFlagA != 0)) {
        *(undefined4 *)(value + 0xc) = 2;
        PlayAudioById(0x3b2,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      }
      if ((*(int *)(value + 0x20) == 2) && (g_TarzanToTheRescueScriptedPathPropFlagB != 0)) {
        *(undefined4 *)(value + 0xc) = 2;
        PlayAudioById(0x3b2,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      }
      break;
    case 1:
      value = *(int *)(entity->sceneObjects + 0x10c);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0x28);
      value2 = entity->sceneObjects;
      value3 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value2);
      ((EntitySceneObject *)value2)->y = ((EntitySceneObject *)value2)->y + value3;
      value2 = *(int *)(entity->sceneObjects + 0x110);
      if (*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value2 * 4) + 8 + value2 * 4 +
                  g_CollisionSurfaceTable) + -0x80 <= value) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
      break;
    case 2:
      *(int *)(entity->sceneObjects + 0x18) = *(int *)(entity->sceneObjects + 0x18) + 0x40;
      if ((*(int *)(value + 0x20) == 0) && (-600 < *(int *)(entity->sceneObjects + 0x18))) {
        *(undefined4 *)(value + 0xc) = 3;
        PlayAudioById(0x3b3,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
        PlayAudioById(0x3b5,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      }
      if ((*(int *)(value + 0x20) == 1) && (-900 < *(int *)(entity->sceneObjects + 0x18))) {
        *(undefined4 *)(value + 0xc) = 3;
        PlayAudioById(0x3b3,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
        PlayAudioById(0x3b5,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      }
      if ((*(int *)(value + 0x20) == 2) && (-900 < *(int *)(entity->sceneObjects + 0x18))) {
        *(undefined4 *)(value + 0xc) = 3;
        PlayAudioById(0x3b3,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
        PlayAudioById(0x3b4,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      }
      break;
    case 3:
      value2 = entity->sceneObjects;
      intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                (((EntitySceneObject *)value2)->x,((EntitySceneObject *)value2)->y + 0x4b0,
                                 ((EntitySceneObject *)value2)->z,0x178,0x11);
      if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
        *(undefined2 *)(intCursor[0xe] + 0xc) = 0x201a;
      }
      value2 = entity->sceneObjects;
      value2 = CEntities::SpawnEntityByTypeAtPosition
                        (((EntitySceneObject *)value2)->x,((EntitySceneObject *)value2)->y + 0x4b0,
                         ((EntitySceneObject *)value2)->z + -0x20,0x14,0x11);
      if (value2 != 0) {
        *(undefined4 *)(*(int *)(value2 + 0x38) + 0xb4) = 1;
        *(undefined4 *)(*(int *)(value2 + 0x38) + 0xa8) = 11000;
        *(undefined4 *)(*(int *)(value2 + 0x38) + 0xac) = 11000;
        *(undefined4 *)(*(int *)(value2 + 0x38) + 0xb0) = 11000;
      }
      shortValue2 = 0;
      value5 = 0x200;
      do {
        value2 = entity->sceneObjects;
        value2 = CEntities::SpawnEntityByTypeAtPosition
                          (((EntitySceneObject *)value2)->x,((EntitySceneObject *)value2)->y + 0x4b0,
                           ((EntitySceneObject *)value2)->z,0x160,0x11);
        if (value2 != 0) {
          *(undefined2 *)(*(int *)(value2 + 0x38) + 0xc) = 0x201b;
          value3 = CEntities::FindEntityAttachmentByFlags(value2,0x20000000);
          if (value3 != 0) {
            value4 = RandomModulo(0x1e);
            *(int *)(value3 + 0x40) =
                 (int)(short)(&g_SinCosTable12Bit)[value5 - 0x400 & 0xfff] * (value4 + 0x32) >> 0xc;
            *(int *)(value3 + 0x44) =
                 (int)(short)(&g_SinCosTable12Bit)[value5 & 0xfff] * (value4 + 0x32) >> 0xc;
            shortValue = RandomModulo(0x40);
            *(undefined2 *)(value3 + 0x56) = 0xff80;
            *(short *)(value3 + 0x54) = -0x60 - shortValue;
            *(short *)(*(int *)(value2 + 0x38) + 0xa2) = shortValue2 * 0x400 + 0x200;
            *(undefined2 *)(*(int *)(value2 + 0x38) + 0xa0) = 0x400;
            value2 = RandomModulo(0x14);
            *(int *)(value3 + 0x18) = value2 + 0x32;
            *(undefined4 *)(value3 + 0x10) = 0;
          }
        }
        value5 = value5 + 0x400;
        shortValue2 = shortValue2 + 1;
      } while ((int)value5 < 0x1200);
      *(undefined2 *)(entity->sceneObjects + 0xa4) = 0;
      if (*(int *)(value + 0x20) == 0) {
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x10),0);
      }
      if (*(int *)(value + 0x20) == 1) {
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x10),1);
      }
      if (*(int *)(value + 0x20) == 2) {
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x10),2);
      }
      *(undefined4 *)(value + 0xc) = 1;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

