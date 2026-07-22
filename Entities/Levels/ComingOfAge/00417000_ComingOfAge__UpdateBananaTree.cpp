#include "tarzan_ghidra_types.hpp"

// Address: 0x00417000
// Label: ComingOfAge::UpdateBananaTree
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateBananaTree(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  uint value5;
  int value2;
  char resultFlag;
  undefined2 value6;
  int value3;
  short *value7;
  short *value8;
  int value4;
  ushort *dataCursor;
  
  value3 = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if ((value3 == 0) || (value = entity->sceneObjects, value == 0)) goto switchD_004171ee_caseD_5;
  if ((*(byte *)(entry + 0x42) & 0x10) != 0) {
    if (((EntitySceneObject *)value)->surfacePathIndex == -1) {
      value5 = *(uint *)(g_PlayerContactSurfaceThisFrame + -8);
      value2 = g_PlayerContactSurfaceThisFrame;
      while ((value5 & 0x10000000) != 0) {
        value5 = *(uint *)(value2 + -0x24);
        value2 = value2 + -0x1c;
      }
      value5 = *(uint *)(value2 + 0x14);
      value2 = value2 + -0x1c;
      while ((value5 & 0x200) == 0) {
        value5 = *(uint *)(value2 + 0x4c);
        value2 = value2 + 0x1c;
      }
      ((EntitySceneObject *)value)->surfacePathIndex = *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
      ((EntitySceneObject *)value)->surfaceIndex = *(undefined4 *)(value2 + 0x28);
    }
    CEntities::SpawnEntityByTypeAtPosition
              (*(undefined4 *)(g_PlayerEntitySceneObjectData + 8),
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10),0x13,0x11);
    *(byte *)(entry + 0x4b) = *(byte *)(entry + 0x4b) | 0x80;
    *(ushort *)(entry + 0x42) = *(ushort *)(entry + 0x42) & 0xffef;
  }
  if (*(short *)(entry + 0x48) == 1) {
    if ((*(byte *)(entry + 0x4b) & 0x80) == 0) {
      if ((*(byte *)(entry + 0x42) & 0x80) != 0) {
        *(undefined2 *)(entry + 0x48) = 2;
        PlayAudioById(0xd2,(int *)0,(undefined4 *)value3 + 0xc);
        CEntities::ResetScriptAttachmentSequenceState(value3,6);
      }
    }
    else {
LAB_004170cf:
      *(undefined2 *)(entry + 0x48) = 3;
      CEntities::ResetScriptAttachmentSequenceState(value3,1);
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0x7fff;
    }
  }
  else if (*(short *)(entry + 0x48) == 2) {
    if ((*(byte *)(entry + 0x4b) & 0x80) != 0) goto LAB_004170cf;
    if ((*(byte *)(entry + 0x42) & 0x80) == 0) {
      *(undefined2 *)(entry + 0x48) = 1;
    }
  }
  value2 = *(int *)(value3 + 0x18);
  if (((value2 != 0) &&
      (value7 = (short *)CEntities::ResolveChildSceneObjectArrayFromRef(value2),
      value7 != (short *)0x0)) && (*(int *)(value + 0x38) != 0)) {
    value4 = 0;
    dataCursor = (ushort *)(*(int *)(value + 0x38) + 0x10);
    if (0 < *value7) {
      value8 = value7 + 2;
      do {
        CEntities::TransformChildSceneObjectLocalPointToWorld
                  (value8,value2,&g_BranchBoostChildWorldPositionScratch);
        *(int *)(dataCursor + 4) = g_BranchBoostChildWorldPositionScratch - ((EntitySceneObject *)value)->x;
        *(int *)(dataCursor + 6) = g_BranchBoostChildSceneObjectPtrScratch - ((EntitySceneObject *)value)->y;
        *(int *)(dataCursor + 8) = ((EntitySceneObject *)value)->z - g_BranchBoostChildWorldPositionZScratch;
        if ((*dataCursor != 0x2021) && (*dataCursor = *dataCursor + 1, 0x2017 < *dataCursor)) {
          *dataCursor = 0x2000;
        }
        dataCursor = dataCursor + 0x14;
        value4 = value4 + 1;
        value8 = value8 + 4;
      } while (value4 < *value7);
    }
  }
  value6 = CEntities::AdvanceEntityScriptTimer(value3);
  switch(value6) {
  case 4:
    if (*(short *)(entry + 0x48) == 3) {
      *(undefined2 *)(entry + 0x48) = 2;
    }
    break;
  case 8:
    if ((*(byte *)(entry + 0x4b) & 0x80) == 0) {
      CEntities::ResetScriptAttachmentSequenceState(value3,3);
    }
    *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0x7fff;
    break;
  case 9:
    value3 = *(int *)(entry + 0x50);
    *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0x7fff;
    value2 = *(int *)(&g_ComingOfAgeBananaTreeRewardEntitySequenceTable +
                    *(int *)(&g_ComingOfAgeBananaTreeRewardIndex0 + value3 * 4) * 4);
    if (value2 != -1) {
      if (value2 != 0) {
        CEntities::SpawnMappedEffectOnSurfaceWithRandomOffset
                  (value2,((EntitySceneObject *)value)->surfacePathIndex,((EntitySceneObject *)value)->surfaceIndex,0xfffffb00,
                   0x280,0x100);
      }
      *(int *)(&g_ComingOfAgeBananaTreeRewardIndex0 + value3 * 4) =
           *(int *)(&g_ComingOfAgeBananaTreeRewardIndex0 + value3 * 4) + 1;
    }
    break;
  case 0x15:
    PlayAudioById(0xd2,(int *)0,(undefined4 *)value3 + 0xc);
    break;
  case 0x16:
    PlayAudioById(0xd4,(int *)0,(undefined4 *)value3 + 0xc);
  }
switchD_004171ee_caseD_5:
  resultFlag = IsEntitySourceRefOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

