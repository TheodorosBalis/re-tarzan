#include "tarzan_ghidra_types.hpp"

// Address: 0x0046E9E0
// Label: CPlayerHero::UpdateAdultTarzanSwingPump
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanSwingPump(void)

{
  undefined2 value2;
  int value;
  undefined4 value3;
  
  if (g_CurrentSwingEntity != 0) {
    if (((byte)g_PlayerInputHeldMask & 0xa0) == 0) {
      if (_g_PlayerSwingPumpCooldown != 0) {
        _g_PlayerSwingPumpCooldown = _g_PlayerSwingPumpCooldown + -1;
      }
    }
    else {
      _g_PlayerSwingPumpCooldown = 10;
    }
    value = UpdatePlayerOnSwing(g_CurrentSwingEntity);
    value2 = g_PlayerActionState;
    if (value == 8) {
      PlayAudioById(0x51,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
      if (g_PlayerAnimationSurfaceSide == '\0') {
        value3 = 0x60;
      }
      else {
        value3 = 0x5f;
      }
      PlayAudioById(value3,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
    else if ((value == 0xc) && (_g_PlayerSwingPumpCooldown == 0)) {
      g_PlayerActionState = 0x17;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterSwingingHandlerPtr)();
    }
  }
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    *(undefined1 *)(g_PlayerEntitySceneObject + 0x75) = g_PlayerSwingPumpVelocity;
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x1b;
                    /* WARNING: Could not recover jumptable at 0x0046eac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterSwingReleaseHandlerPtr)();
    return;
  }
  return;
}

