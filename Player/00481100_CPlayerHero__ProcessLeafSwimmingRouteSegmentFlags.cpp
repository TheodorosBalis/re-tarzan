#include "tarzan_ghidra_types.hpp"

// Address: 0x00481100
// Label: CPlayerHero::ProcessLeafSwimmingRouteSegmentFlags
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::ProcessLeafSwimmingRouteSegmentFlags(void)

{
  int value;
  
  value = g_LeafSwimmingCenterRouteSurfaceIndex * 4 + 4;
  value = *(int *)(value + g_CollisionSurfaceTable) + value + g_CollisionSurfaceTable;
  if ((g_LeafSwimmingSurfaceProgress & 8) != 0) {
    g_LeafSwimmingWhirlpoolPullActive =
         *(undefined4 *)(value + 0x34 + g_LeafSwimmingNextRouteNode * 0x1c);
  }
  if ((g_LeafSwimmingSurfaceProgress & 4) != 0) {
    g_LeafSwimmingCameraDynamicPitchActive = 1;
    g_LeafSwimmingWhirlpoolPullActive =
         *(undefined4 *)(value + 0x50 + g_LeafSwimmingNextRouteNode * 0x1c);
    if (g_PlayerActionState != 2) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 2;
                    /* WARNING: Could not recover jumptable at 0x0048117b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*_g_LeafSwimmingEnterDropCallback)();
      return;
    }
  }
  return;
}

