#include "tarzan_ghidra_types.hpp"

// Address: 0x00460E50
// Label: TarzanToTheRescue::UpdateLevelRuntimeHook
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TarzanToTheRescue::UpdateLevelRuntimeHook(void)

{
  short shortValue;
  
  CEntities::UpdateRandomAmbientSoundCue();
  if (_g_PlayerHeroMode == 1) {
    *(byte *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xf) =
         *(byte *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xf) | 0x80;
  }
  else {
    *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) =
         *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) & 0x7fff;
  }
  if (((g_AdultTarzanElephantRouteEvent10Active != 0) && (g_PlayerActionState != 3)) &&
     (g_AdultTarzanElephantRouteEvent10Value < *(int *)(g_PlayerEntitySceneObject + 0x18))) {
    g_AdultTarzanElephantMountTransitionBlocked = 1;
    QueuePlayerDamageEvent(0,0x600);
    g_PlayerSequenceDelayTicks = 0;
    g_AdultTarzanElephantRouteEvent10Active = 0;
    g_AdultTarzanElephantScriptedRiseActive = 1;
  }
  shortValue = g_PlayerActionState;
  if (((g_AdultTarzanElephantRouteEvent40Active != 0) && (g_PlayerActionState != 3)) &&
     ((g_PlayerActionState != 7 && ((g_PlayerActionState != 5 && (g_PlayerActionState != 2)))))) {
    g_PlayerActionState = 2;
    g_PreviousPlayerActionState = shortValue;
    (*(code *)g_AdultTarzanElephantEnterRideHandlerPtr)();
  }
  if (g_AdultTarzanElephantRouteEvent100Active != 0) {
    if (g_AdultTarzanElephantRouteEvent100Height < *(int *)(g_PlayerEntitySceneObject + 0x18)) {
      _g_AdultTarzanElephantRouteEvent100Triggered = 1;
      if (g_PlayerActionState != 0x2e) {
        QueuePlayerDamageEvent(0,0xc);
        CEntities::SpawnEntityByTypeAtPosition
                  (*(undefined4 *)(g_PlayerEntitySceneObject + 0x14),
                   *(undefined4 *)(g_PlayerEntitySceneObject + 0x18),
                   *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c),0x193,0x11);
        CEntities::SpawnEntityByTypeAtPosition
                  (*(undefined4 *)(g_PlayerEntitySceneObject + 0x14),
                   *(undefined4 *)(g_PlayerEntitySceneObject + 0x18),
                   *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c),0x195,0x11);
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0x2e;
        (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
        return;
      }
    }
    else {
      _g_AdultTarzanElephantRouteEvent100Triggered = 0;
    }
  }
  return;
}

