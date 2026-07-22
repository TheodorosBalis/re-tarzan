#include "tarzan_ghidra_types.hpp"

// Address: 0x0046C5D0
// Label: CPlayerHero::EnterAdultTarzanClimbableEdgeHang
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterAdultTarzanClimbableEdgeHang(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     (((g_CameraFollowFlags | 0x10) & g_PlayerInputHeldMask) != 0)) {
    g_PlayerActionState = 0x21;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0046c605. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterClimbableEdgePullUpHandlerPtr)();
    return;
  }
  if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
    CPlayerHero::PlayAdultTarzanAnimation(0x6b);
    return;
  }
  CPlayerHero::PlayAdultTarzanAnimation(0x67);
  return;
}

