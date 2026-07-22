#include "tarzan_ghidra_types.hpp"

// Address: 0x0048F330
// Label: CPlayerHero::EnterYoungClimbableEdgeHang
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterYoungClimbableEdgeHang(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     (((g_CameraFollowFlags | 0x10) & g_PlayerInputHeldMask) != 0)) {
    g_PlayerActionState = 0x22;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048f365. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterClimbableEdgePullUpHandlerPtr)();
    return;
  }
  if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
    CPlayerHero::PlayAnimation(0x6f);
    return;
  }
  CPlayerHero::PlayAnimation(0x6b);
  return;
}

