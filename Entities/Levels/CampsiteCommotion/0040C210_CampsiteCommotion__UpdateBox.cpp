#include "tarzan_ghidra_types.hpp"

// Address: 0x0040C210
// Label: CampsiteCommotion::UpdateBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CampsiteCommotion::UpdateBox(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  undefined2 upperWord;
  undefined2 upperWord2;
  undefined2 upperWord3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000004);
    if (value2 != 0) {
      if (0 < *(short *)(value2 + 0xc)) {
        *(short *)(value + 0xa0) =
             (short)((int)(short)(&g_SinCosTable12Bit)[*(ushort *)(value2 + 0xe) - 0x400 & 0xfff] *
                     (int)*(short *)(value2 + 0xc) >> 0xc);
        ((EntitySceneObject *)value)->pitch =
             (short)((int)(short)(&g_SinCosTable12Bit)[*(ushort *)(value2 + 0xe) & 0xfff] *
                     (int)*(short *)(value2 + 0xc) >> 0xc);
        *(short *)(value2 + 0xc) = *(short *)(value2 + 0xc) + -4;
        *(short *)(value2 + 0xe) = *(short *)(value2 + 0xe) + 0x80;
      }
      if ((*(ushort *)(entry + 0x48) & 1) == 0) {
        if (((EntitySceneObject *)value)->linkedSceneObject != 0) {
          *(undefined2 *)(value2 + 0xc) = 100;
          *(ushort *)(entry + 0x48) = *(ushort *)(entry + 0x48) | 1;
        }
      }
      else if (((EntitySceneObject *)value)->linkedSceneObject == 0) {
        *(ushort *)(entry + 0x48) = *(ushort *)(entry + 0x48) & 0xfffe;
      }
      if ((*(ushort *)(entry + 0x42) & 0x10) != 0) {
        *(ushort *)(entry + 0x42) = *(ushort *)(entry + 0x42) & 0xffef;
        *(short *)(value2 + 0x10) = *(short *)(value2 + 0x10) + -1;
        if (*(short *)(value2 + 0x10) < 1) {
          CEntities::SpawnEntityByTypeAtPosition
                    (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                     ((EntitySceneObject *)value)->z,0x11d,0x11);
          _g_CampBoxCameraShakeTimer = 6;
          _g_CampBoxCameraShakeAmplitude = 0x18;
          PlayForceFeedbackEffect_Stub(0,2,0xf);
          PlayAudioById(0x29a,0,(undefined4 *)(&((EntitySceneObject *)value)->x));
          PlayForceFeedbackEffect_Stub(0,3,0xf8);
          CEntities::SpawnMappedPickupOrEffectAtPosition
                    (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                     ((EntitySceneObject *)value)->z,
                     CONCAT22(upperWord,*(undefined2 *)(value2 + 0x12)),
                     CONCAT22(upperWord3,*(undefined2 *)(value2 + 0x14)),
                     CONCAT22(upperWord2,*(undefined2 *)(value2 + 0x16)));
          CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        }
        else {
          *(undefined2 *)(value2 + 0xc) = 100;
          *(ushort *)(entry + 0x48) = *(ushort *)(entry + 0x48) | 1;
          PlayAudioById(0x28a,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
          CEntities::SpawnEntityByTypeAtPosition
                    (*(undefined4 *)(g_PlayerEntitySceneObjectData + 8),
                     *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
                     *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10),0x13,0x11);
        }
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

