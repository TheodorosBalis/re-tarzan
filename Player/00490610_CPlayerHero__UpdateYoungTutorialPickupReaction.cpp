#include "tarzan_ghidra_types.hpp"

// Address: 0x00490610
// Label: CPlayerHero::UpdateYoungTutorialPickupReaction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungTutorialPickupReaction(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  value2 = g_PlayerActionState;
  g_PlayerDamageInvulnerabilityTicks = 0x3c;
  if (g_TutorialPickupSequencePhase == 2) {
    g_PlayerActionState = 0x37;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00490642. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterTarzanAndTerkTutorialPickupHandlerPtr)();
    return;
  }
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00490668. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
    return;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 5) {
    g_TutorialPickupSequencePhase = 1;
  }
  else {
    if (value == 6) {
      *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
      *(ushort *)(g_PlayerEntitySceneObject + 0xa2) =
           *(ushort *)(g_PlayerEntitySceneObject + 0xa2) ^ 0x800;
      return;
    }
    if (value == 8) {
      CPlayerHero::PlayAnimation(0x94);
      return;
    }
  }
  return;
}

