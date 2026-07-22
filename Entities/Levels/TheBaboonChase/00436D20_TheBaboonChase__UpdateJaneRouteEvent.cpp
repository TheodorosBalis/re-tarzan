#include "tarzan_ghidra_types.hpp"

// Address: 0x00436D20
// Label: TheBaboonChase::UpdateJaneRouteEvent
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TheBaboonChase::UpdateJaneRouteEvent(void)

{
  if ((_g_JaneRouteEventEnabled != 0) &&
     (_g_JaneRouteEventValue < *(int *)(g_PlayerEntitySceneObject + 0x18))) {
    PlayAudioById(0x23b,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    g_JaneGroundSnapSuppressed = 1;
    QueuePlayerDamageEvent(0,0x600);
    g_PlayerSequenceDelayTicks = 0;
    _g_JaneRouteEventEnabled = 0;
    g_JaneCameraTrackPaused = 1;
  }
  return;
}

