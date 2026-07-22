#include "tarzan_ghidra_types.hpp"

// Address: 0x00416C90
// Label: ComingOfAge::UpdateBranchBoost
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateBranchBoost(int entry)

{
  char resultFlag;
  short shortValue;
  int value;
  short *value6;
  int value2;
  int value3;
  short *value7;
  int value4;
  undefined4 value5;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (value == 0) goto LAB_00416ea5;
  if (*(short *)(entry + 0x48) == 2) {
    value3 = *(int *)(entry + 0x4c);
    if ((*(ushort *)(entry + 0x42) & 0x80) == 0) {
      if ((*(ushort *)(entry + 0x42) & 0x40) == 0) {
        *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffe;
      }
      else {
        *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 1;
      }
      if (0 < value3) {
        value3 = value3 + -1;
      }
    }
    else {
      *(int *)(value + 0x1c) = g_PlayerActiveSurfaceDefinition;
      if (g_PlayerActiveSurfaceDefinition != 0) {
        value3 = *(int *)(g_PlayerActiveSurfaceDefinition + 0x90) -
                *(int *)(g_PlayerActiveSurfaceDefinition + 0x74);
        if (((g_PlayerContactSurfaceThisFrame - g_PlayerActiveSurfaceDefinition) + -0x30) / 0x1c < 3
           ) {
          value4 = *(int *)(g_PlayerActiveSurfaceDefinition + 0x90) -
                  *(int *)(g_PlayerEntitySceneObject + 0x10c);
          if (value4 < value3) {
            value3 = (value4 * 4) / value3;
            *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffe;
            goto LAB_00416e22;
          }
          if ((*(byte *)(entry + 0x4a) & 1) != 0) {
            value3 = RandomModulo(4);
            g_PreviousPlayerActionState = g_PlayerActionState;
            g_PlayerActionState = 0x30;
            (*(code *)g_AdultTarzanEnterFastForwardLaunchHandlerPtr)();
            PlayAudioById(0xd7,(int *)0,(undefined4 *)value + 0xc);
            if (value3 == 0) {
              value5 = 99;
LAB_00416dd5:
              PlayAudioById(value5,g_PlayerEntitySceneObject + 0x104,g_PlayerEntitySceneObject + 0x14
                           );
            }
            else {
              if (value3 == 1) {
                value5 = 100;
                goto LAB_00416dd5;
              }
              if (value3 == 2) {
                value5 = 0x65;
                goto LAB_00416dd5;
              }
              if (value3 == 3) {
                value5 = 0x66;
                goto LAB_00416dd5;
              }
            }
            *(undefined2 *)(entry + 0x48) = 4;
          }
          *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffe;
          value3 = 4;
          goto LAB_00416e22;
        }
        value3 = 0;
      }
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffe;
    }
LAB_00416e22:
    *(int *)(entry + 0x4c) = value3;
    *(undefined2 *)(value + 0x28) = 0xffff;
    *(short *)(value + 0x2a) = (short)(value3 >> 1);
  }
  shortValue = CEntities::AdvanceEntityScriptTimer(value);
  if (shortValue != 0) {
    *(undefined2 *)(entry + 0x48) = 2;
  }
  value3 = *(int *)(value + 0x18);
  if (((value3 != 0) &&
      (value6 = (short *)CEntities::ResolveChildSceneObjectArrayFromRef(value3),
      value6 != (short *)0x0)) && (value4 = 0, 0 < *value6)) {
    value2 = 0;
    value7 = value6 + 2;
    do {
      CEntities::TransformChildSceneObjectLocalPointToWorld
                (value7,value3,&g_BranchBoostChildWorldPositionScratch);
      if (*(int *)(value + 0x1c) != 0) {
        *(undefined4 *)(*(int *)(value + 0x1c) + 0x34 + value2) =
             g_BranchBoostChildSceneObjectPtrScratch;
      }
      value4 = value4 + 1;
      value7 = value7 + 4;
      value2 = value2 + 0x1c;
    } while (value4 < *value6);
  }
LAB_00416ea5:
  resultFlag = IsEntitySourceRefOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

