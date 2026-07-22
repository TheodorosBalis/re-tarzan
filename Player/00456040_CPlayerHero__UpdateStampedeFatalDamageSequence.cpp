#include "tarzan_ghidra_types.hpp"

// Address: 0x00456040
// Label: CPlayerHero::UpdateStampedeFatalDamageSequence
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateStampedeFatalDamageSequence(void)

{
  short *value5;
  int value;
  uint value4;
  int value2;
  int value3;
  int localState3;
  int localState2;
  int localState;
  
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  localState3 = g_StampedeCameraTargetX;
  localState2 = g_StampedeCameraTargetY + 0xa0;
  localState = g_StampedeCameraTargetZ;
  CEntities::AdvanceEntitySceneObjectParabolicArc
            (*(int *)(g_PlayerEntity + 0x38) + 0x14,&localState3,0x534070,
             g_PlayerEntitySceneObject + 0x14);
  value5 = (short *)(g_PlayerEntitySceneObject + 0xa2);
  value = GetWrappedSignedAngleDelta12Bit
                    ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),_g_StampedeEntryCameraZ);
  *value5 = *value5 + (short)(value >> 3);
  value = *(int *)(g_PlayerEntitySceneObject + 0x14) - g_StampedeCameraTargetX;
  value2 = *(int *)(g_PlayerEntitySceneObject + 0x1c) - g_StampedeCameraTargetZ;
  value3 = *(int *)(g_PlayerEntitySceneObject + 0x18) - g_StampedeCameraTargetY;
  value4 = SqrtToInt(value3 * value3 + value2 * value2 + value * value);
  if (0x16400 < (int)(value4 & 0xffffffc0)) {
    *(short *)(g_PlayerEntitySceneObject + 0xa0) =
         *(short *)(g_PlayerEntitySceneObject + 0xa0) + 0xa0;
    *(short *)(g_PlayerEntitySceneObject + 0xa4) =
         *(short *)(g_PlayerEntitySceneObject + 0xa4) + 0x10;
    CPlayerHero::AdvanceAnimationScript();
    return;
  }
  value5 = (short *)(g_PlayerEntitySceneObject + 0xa0);
  value = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa0),0);
  *value5 = *value5 + (short)(value >> 4);
  value5 = (short *)(g_PlayerEntitySceneObject + 0xa4);
  value = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa4),0);
  *value5 = *value5 + (short)(value >> 4);
  CPlayerHero::AdvanceAnimationScript();
  return;
}

