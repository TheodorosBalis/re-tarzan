#include "tarzan_ghidra_types.hpp"

// Address: 0x00480EF0
// Label: CPlayerHero::AdvanceLeafSwimmingSurfaceTrack
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CPlayerHero::AdvanceLeafSwimmingSurfaceTrack(void)

{
  uint value2;
  int value;
  ushort *dataCursor;
  uint value3;
  
  value = g_LeafSwimmingCenterRouteSurfaceIndex * 4 + 4;
  dataCursor = (ushort *)(*(int *)(value + g_CollisionSurfaceTable) + value + g_CollisionSurfaceTable);
  value3 = (uint)*dataCursor;
  if (g_LeafSwimmingCameraYawTarget == 0) {
    value2 = FindRuntimePathSegmentForEntitySceneObject(dataCursor,g_PlayerEntitySceneObject);
    if (value2 == 0xffffffff) {
      return 0;
    }
    g_LeafSwimmingRouteAdvanceDistance = dataCursor + value2 * 0xe + 0x18;
    _g_LeafSwimmingSurfaceProgress = *(undefined4 *)(dataCursor + 0x22);
    g_LeafSwimmingCameraYawTarget = 1;
    g_LeafSwimmingNextRouteNode = value2;
  }
  value = CPlayerHero::UpdateLeafSwimmingRouteHeadingAndChooseSegmentStep
                    (g_LeafSwimmingRouteAdvanceDistance,g_PlayerEntitySceneObject);
  if (value == 1) {
    g_LeafSwimmingRouteAdvanceDistance = g_LeafSwimmingRouteAdvanceDistance + 0xe;
    g_LeafSwimmingNextRouteNode = g_LeafSwimmingNextRouteNode + 1;
  }
  else if (value == 2) {
    g_LeafSwimmingRouteAdvanceDistance = g_LeafSwimmingRouteAdvanceDistance + -0xe;
    g_LeafSwimmingNextRouteNode = g_LeafSwimmingNextRouteNode - 1;
  }
  value = g_LeafSwimmingNextRouteNode * 0xe;
  if (g_LeafSwimmingRouteAdvanceDistance + value3 * 0xe < g_LeafSwimmingRouteAdvanceDistance) {
    g_LeafSwimmingRouteAdvanceDistance = g_LeafSwimmingRouteAdvanceDistance + value3 * 0xe;
  }
  if (g_LeafSwimmingRouteAdvanceDistance < dataCursor + 0x18) {
    g_LeafSwimmingRouteAdvanceDistance = dataCursor + 0x18;
  }
  if ((int)value3 <= (int)g_LeafSwimmingNextRouteNode) {
    g_LeafSwimmingNextRouteNode = value3;
  }
  if ((int)g_LeafSwimmingNextRouteNode < 1) {
    g_LeafSwimmingNextRouteNode = 0;
  }
  _g_LeafSwimmingSurfaceProgress = *(undefined4 *)(dataCursor + value + 0x22);
  return 0;
}

