#include "tarzan_ghidra_types.hpp"

// Address: 0x0045BDB0
// Label: CPlayerHero::UpdateStorkGroundedRecoveryWait
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStorkGroundedRecoveryWait(void)

{
  short *value2;
  int value;
  
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  if ((g_PlayerInputHeldMask & 0x4000) != 0) {
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x2100;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x2100;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x42;
    *(undefined4 *)(g_PlayerMotionState + 0x24) = 5;
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 3;
                    /* WARNING: Could not recover jumptable at 0x0045be0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_StorkEnterFlapAscentHandlerPtr)();
    return;
  }
  value2 = (short *)(g_PlayerEntitySceneObject + 0xa0);
  value = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa0),0);
  *value2 = *value2 + (short)(value >> 3);
  value2 = (short *)(g_PlayerEntitySceneObject + 0xa4);
  value = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa4),0);
  *value2 = *value2 + (short)(value >> 3);
  CPlayerHero::AdvanceAnimationScript();
  return;
}

