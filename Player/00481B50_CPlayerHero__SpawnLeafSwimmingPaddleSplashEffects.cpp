#include "tarzan_ghidra_types.hpp"

// Address: 0x00481B50
// Label: CPlayerHero::SpawnLeafSwimmingPaddleSplashEffects
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::SpawnLeafSwimmingPaddleSplashEffects(void)

{
  int value;
  int value2;
  undefined4 localState2 [2];
  undefined4 localState;
  
  if (*(short *)(g_PlayerAnimationState + 0x16) == 8) {
    value = GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x100,localState2);
    if (value != 0) {
      CEntities::SpawnEntityByTypeAtPosition
                (localState2[0],*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x193,0x11)
      ;
      CEntities::SpawnEntityByTypeAtPosition
                (localState2[0],*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x195,0x11)
      ;
    }
    value = GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x200,localState2);
    if (value != 0) {
      CEntities::SpawnEntityByTypeAtPosition
                (localState2[0],*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x193,0x11)
      ;
      CEntities::SpawnEntityByTypeAtPosition
                (localState2[0],*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x195,0x11)
      ;
    }
  }
  value = (short)(&g_SinCosTable12Bit)
                 [(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) - 0x580U & 0xfff] * 0xa0 >> 0xc;
  value2 = (short)(&g_SinCosTable12Bit)
                 [(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) - 0x180U & 0xfff] * 0xa0 >> 0xc;
  if (*(short *)(g_PlayerAnimationState + 0x16) == 0) {
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x193,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x195,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x194,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x194,0x11);
  }
  if (*(short *)(g_PlayerAnimationState + 0x16) == 0x10) {
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x193,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x195,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x194,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x194,0x11);
  }
  value = (short)(&g_SinCosTable12Bit)
                 [(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) - 0x280U & 0xfff] * 0xa0 >> 0xc;
  value2 = (short)(&g_SinCosTable12Bit)
                 [(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) + 0x180U & 0xfff] * 0xa0 >> 0xc;
  if (*(short *)(g_PlayerAnimationState + 0x16) == 8) {
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x193,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x195,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x194,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x194,0x11);
  }
  if (*(short *)(g_PlayerAnimationState + 0x16) == 0x18) {
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x193,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x195,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x194,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (*(int *)(g_PlayerEntitySceneObjectData + 8) + value,
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value2,0x194,0x11);
  }
  return;
}

