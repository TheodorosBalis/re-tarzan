#include "tarzan_ghidra_types.hpp"

// Address: 0x004380C0
// Label: CPlayerHero::EnterJaneDamageReaction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterJaneDamageReaction(void)

{
  if (g_JaneDamageReactionType == 0) {
    g_PlayerCurrentAnimationId = 9;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_JanePositiveLateralImpactAnimationScriptPtr;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    _g_JaneLateralRecoilAcceleration = 4;
    _g_JaneLateralRecoilDeceleration = 4;
    _g_JaneLateralRecoilSpeed = 0;
    _g_JaneLateralRecoilTargetSpeed = 0x20;
  }
  if (g_JaneDamageReactionType == 1) {
    g_PlayerCurrentAnimationId = 8;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneNegativeLateralImpactAnimationScriptPtr;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    _g_JaneLateralRecoilAcceleration = 4;
    _g_JaneLateralRecoilDeceleration = 4;
    _g_JaneLateralRecoilSpeed = 0;
    _g_JaneLateralRecoilTargetSpeed = 0xffffffe0;
  }
  if (g_JaneDamageReactionType == 2) {
    g_PlayerCurrentAnimationId = 10;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneTerrainHazardAnimationScriptPtr;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
  }
  if (g_JaneDamageReactionType == 3) {
    g_PlayerCurrentAnimationId = 8;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneNegativeLateralImpactAnimationScriptPtr;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
  }
  if (g_JaneDamageReactionType == 4) {
    PlayAudioById(0x23d,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    g_PlayerCurrentAnimationId = 0xb;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneFatalDamageAnimationScriptPtr;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    QueuePlayerDamageEvent(0,0x200);
    g_PlayerSequenceDelayTicks = 0;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x34) = 2;
  *(undefined4 *)(g_PlayerMotionState + 0x38) = 2;
  *(undefined4 *)(g_PlayerMotionState + 0x30) = 0x20;
  *(undefined4 *)(g_PlayerMotionState + 0x3c) = 0xffffffe0;
  g_PlayerFacingCurrentCollisionSurface = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 4;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 4;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  return;
}

