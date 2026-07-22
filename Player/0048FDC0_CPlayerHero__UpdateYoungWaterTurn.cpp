#include "tarzan_ghidra_types.hpp"

// Address: 0x0048FDC0
// Label: CPlayerHero::UpdateYoungWaterTurn
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungWaterTurn(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
    if (g_PlayerCurrentCollisionMode == 2) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048fe2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTarzanTurnAroundHandlerPtr)();
      return;
    }
    if ((g_PlayerInputHeldMask & 0x80) == 0) {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + 0x2d;
    }
    else {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + -0x2d;
    }
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  CPlayerHero::AdvanceAnimationScript();
  CPlayerHero::SpawnYoungWaterAttachmentEffects();
  return;
}

