#include "tarzan_ghidra_types.hpp"

// Address: 0x00492B20
// Label: CPlayerHero::UpdateYoungSwingPump
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungSwingPump(void)

{
  undefined2 value2;
  int value;
  
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
      PlayAudioById(0x12,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
    else if ((value == 0xc) && (_g_PlayerSwingPumpCooldown == 0)) {
      g_PlayerActionState = 0x18;
      g_PreviousPlayerActionState = value2;
      (*_g_YoungEnterSwingIdleHandlerPtr)();
    }
  }
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    *(undefined1 *)(g_PlayerEntitySceneObject + 0x75) = g_PlayerSwingPumpVelocity;
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x1c;
                    /* WARNING: Could not recover jumptable at 0x00492bcf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterSwingReleaseHandlerPtr)();
    return;
  }
  return;
}

