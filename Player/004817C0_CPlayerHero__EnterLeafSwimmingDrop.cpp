#include "tarzan_ghidra_types.hpp"

// Address: 0x004817C0
// Label: CPlayerHero::EnterLeafSwimmingDrop
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterLeafSwimmingDrop(void)

{
  int value;
  undefined4 value2;
  
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x200;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 0x180;
  if (g_LeafSwimmingStageSet == 0) {
    g_PlayerCurrentAnimationId = 0;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_LeafSwimmingEarlyStageAnimationScript;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  }
  else {
    g_PlayerCurrentAnimationId = 1;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_LeafSwimmingLateStageAnimationScript;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  }
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x5800;
  _g_LeafSwimmingCameraRouteNode = 0x200;
  _g_LeafSwimmingDropSplashTimer = 0;
  g_LeafSwimmingMidStageMotionTable = 0;
  g_LeafSwimmingCameraTargetDistance = g_LeafSwimmingDropCameraDistance;
  g_LeafSwimmingCameraTargetDistanceScale = g_LeafSwimmingDropStartHeight;
  if (_g_PlayerHeroMode == 0xb) {
    value = RandomModulo(4);
    if (value == 0) {
      value2 = 0x456;
    }
    else if (value == 1) {
      value2 = 0x457;
    }
    else if (value == 2) {
      value2 = 0x458;
    }
    else {
      if (value != 3) goto LAB_00481904;
      value2 = 0x459;
    }
    PlayAudioById(value2,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  }
LAB_00481904:
  if (_g_PlayerHeroMode == 0xc) {
    value = RandomModulo(4);
    if (value == 0) {
      PlayAudioById(0x45b,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
      g_LeafSwimmingPlayerRouteSurfaceIndex = 0;
      return;
    }
    if (value == 1) {
      PlayAudioById(0x45c,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
      g_LeafSwimmingPlayerRouteSurfaceIndex = 0;
      return;
    }
    if (value == 2) {
      PlayAudioById(0x45d,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
      g_LeafSwimmingPlayerRouteSurfaceIndex = 0;
      return;
    }
    if (value == 3) {
      PlayAudioById(0x45e,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
  }
  g_LeafSwimmingPlayerRouteSurfaceIndex = 0;
  return;
}

