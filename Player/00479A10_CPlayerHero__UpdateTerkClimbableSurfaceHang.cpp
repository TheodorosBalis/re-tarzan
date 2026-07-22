#include "tarzan_ghidra_types.hpp"

// Address: 0x00479A10
// Label: CPlayerHero::UpdateTerkClimbableSurfaceHang
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateTerkClimbableSurfaceHang(void)

{
  undefined2 value;
  char resultFlag;
  
  value = g_PlayerActionState;
  if (((g_PlayerSequenceFlags & 0xf000) == 0) && (((byte)g_PlayerInputHeldMask & 0x10) != 0)) {
    g_PlayerActionState = 0x16;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x00479a3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterClimbableSurfacePullUpHandlerPtr)();
    return;
  }
  if (((g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 0x17;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x00479a68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterClimbableSurfaceHopOffHandlerPtr)();
    return;
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = value;
    (*(code *)g_TerkEnterFallingHandlerPtr)();
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

