#include "tarzan_ghidra_types.hpp"

// Address: 0x004901C0
// Label: CPlayerHero::UpdateYoungWaterIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungWaterIdle(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) && (((byte)g_PlayerInputHeldMask & 0xf0) != 0)) &&
     (g_PlayerCollisionFacingFlags == '\0')) {
    g_PlayerActionState = 0x28;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x004901f1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterSwimForwardHandlerPtr)();
    return;
  }
  CPlayerHero::SteerYoungAirMoveHeadingFromHorizontalInput();
  CPlayerHero::UpdateMovementAndCollision(1);
  CPlayerHero::AdvanceAnimationScript();
  CPlayerHero::SpawnYoungWaterAttachmentEffects();
  return;
}

