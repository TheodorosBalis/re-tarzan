#include "tarzan_ghidra_types.hpp"

// Address: 0x004580B0
// Label: Stampede::UpdatePalmTree
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Stampede::UpdatePalmTree(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int *intCursor2;
  int *intCursor;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    value4 = *(int *)(value2 + 0x10);
    switch(*(undefined4 *)(value2 + 0xc)) {
    case 5:
      if (*(int *)(value2 + 700) == 0) {
        shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
        if (shortValue == 3) {
          *(undefined4 *)(value2 + 700) = 1;
        }
        if (*(short *)(entity->sceneObjects + 0xc) == 0x1b) {
          *(undefined4 *)(value2 + 0x2c0) = 1;
        }
      }
      else {
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2055;
      }
      if (*(int *)(value2 + 0x2c0) != 0) {
        intCursor = (int *)(value2 + 0x34);
        intCursor2 = (int *)(value2 + 0x290);
        value2 = value2 + 0x4c;
        value4 = 6;
        do {
          value5 = *intCursor;
          if (value5 != 0) {
            value3 = *(int *)(g_PlayerEntitySceneObject + 0x1c) - *(int *)(value5 + 0x1c);
            value5 = *(int *)(g_PlayerEntitySceneObject + 0x14) - *(int *)(value5 + 0x14);
            if (value3 * value3 + value5 * value5 < 0x4000) {
              QueuePlayerDamageEvent(entry,1);
              *(ushort *)(*intCursor + 0xe) = *(ushort *)(*intCursor + 0xe) & 0x7fff;
            }
            if (intCursor2[-1] < 5) {
              value5 = CEntities::AdvanceBounceMotionAndReturnImpact(*intCursor,value2);
              if (value5 != 0) {
                *intCursor2 = *intCursor2 >> 1;
                intCursor2[-1] = intCursor2[-1] + 1;
              }
              *(short *)(*intCursor + 0xa2) = *(short *)(*intCursor + 0xa2) + (short)*intCursor2;
              *(short *)(*intCursor + 0xa4) = *(short *)(*intCursor + 0xa4) + (short)*intCursor2;
              *(short *)(*intCursor + 0xa0) = *(short *)(*intCursor + 0xa0) + (short)*intCursor2;
            }
          }
          intCursor = intCursor + 1;
          value2 = value2 + 0x60;
          intCursor2 = intCursor2 + 2;
          value4 = value4 + -1;
        } while (value4 != 0);
      }
      break;
    case 7:
      if (g_StampedeElephantsEntity != 0) {
        value5 = *(int *)(g_StampedeElephantsEntity + 0x38);
        value3 = *(int *)(value5 + 0x14) - *(int *)(entity->sceneObjects + 0x14);
        value6 = *(int *)(value5 + 0x1c) - *(int *)(entity->sceneObjects + 0x1c);
        if (value6 * value6 + value3 * value3 < 0x3170400) {
          value5 = *(int *)(value5 + 0x18);
          value = *(int *)(entity->sceneObjects + 0x18);
          *(undefined4 *)(value2 + 0x14) = 0x20;
          value5 = (value5 - value) + -0x300;
          *(int *)(value2 + 0x20) = (int)(value3 + -0x80 + (value3 + -0x80 >> 0x1f & 0x1fU)) >> 5;
          *(undefined4 *)(value2 + 0x18) = 0;
          *(int *)(value2 + 0x28) = (int)(value6 + (value6 >> 0x1f & 0x1fU)) >> 5;
          *(undefined4 *)(value2 + 0x1c) = 8;
          *(int *)(value2 + 0x24) = (int)(value5 + (value5 >> 0x1f & 0x1fU)) >> 5;
          *(undefined4 *)(value2 + 0x2c) =
               *(undefined4 *)(*(int *)(g_StampedeElephantsEntity + 0x38) + 0x18);
          value5 = *(int *)(g_StampedeElephantsEntity + 0x38);
          *(undefined4 *)(value4 + 0x14) = *(undefined4 *)(value5 + 0x14);
          *(undefined4 *)(value4 + 0x18) = *(undefined4 *)(value5 + 0x18);
          *(undefined4 *)(value4 + 0x1c) = *(undefined4 *)(value5 + 0x1c);
          value5 = g_WorldEntitySceneObjectArrayBase + 0x30c0;
          *(undefined2 *)(value4 + 0xc) = 0x2027;
          *(int *)(value4 + 0x10) = value5;
          *(undefined4 *)(value2 + 0xc) = 0xb;
          *(undefined4 *)(value2 + 0x30) = 0;
        }
      }
      break;
    case 0xb:
      *(int *)(value4 + 0x14) = *(int *)(value4 + 0x14) - *(int *)(value2 + 0x20);
      *(int *)(value4 + 0x1c) = *(int *)(value4 + 0x1c) - *(int *)(value2 + 0x28);
      *(int *)(value4 + 0x18) =
           (*(int *)(value2 + 0x24) * *(int *)(value2 + 0x30) -
           ((int)((&g_ParabolicArcHeightOffsetTable)[*(int *)(value2 + 0x18)] << 9) >> 0xc)) +
           *(int *)(value2 + 0x2c);
      *(uint *)(value2 + 0x18) = *(int *)(value2 + 0x1c) + *(int *)(value2 + 0x18) & 0xff;
      *(int *)(value2 + 0x30) = *(int *)(value2 + 0x30) + 1;
      *(short *)(value4 + 0xa2) = *(short *)(value4 + 0xa2) + 0x100;
      *(short *)(value4 + 0xa0) = *(short *)(value4 + 0xa0) + 0x20;
      if (*(int *)(value2 + 0x14) <= *(int *)(value2 + 0x30)) {
        *(undefined4 *)(value2 + 0xc) = 0xc;
      }
      break;
    case 0xc:
      *(ushort *)(value4 + 0xe) = *(ushort *)(value4 + 0xe) & 0x7fff;
      value4 = CEntities::SpawnEntityByTypeAtPosition
                        (*(undefined4 *)(value4 + 0x14),*(undefined4 *)(value4 + 0x18),
                         *(undefined4 *)(value4 + 0x1c),0x15e,0x11);
      if (value4 != 0) {
        *(undefined4 *)(*(int *)(value4 + 0x38) + 0xb4) = 1;
        *(undefined4 *)(*(int *)(value4 + 0x38) + 0xa8) = 11000;
        *(undefined4 *)(*(int *)(value4 + 0x38) + 0xac) = 11000;
        *(undefined4 *)(*(int *)(value4 + 0x38) + 0xb0) = 11000;
      }
      _g_CampBoxCameraShakeTimer = 8;
      _g_CampBoxCameraShakeAmplitude = 0xc;
      PlayForceFeedbackEffect_Stub(0,2,0xf);
      *(undefined4 *)(value2 + 0xc) = 5;
      PlayAudioById(0x1c3,(int *)0,(undefined4 *)0);
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

