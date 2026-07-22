#include "tarzan_ghidra_types.hpp"

// Address: 0x004714D0
// Label: CPlayerHero::EnterTarzanSurfingWithJaneSurfing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTarzanSurfingWithJaneSurfing(void)

{
  undefined *dataCursor;
  
  if (g_PlayerTreeSurfingLateralThresholdSide != 1) {
    if (g_PlayerTreeSurfingLateralThresholdSide != 2) {
      switch(g_PlayerCurrentAnimationId) {
      case 10:
        goto switchD_004714fc_caseD_a;
      default:
        goto switchD_004714fc_caseD_b;
      case 0xd:
        goto switchD_004714fc_caseD_d;
      case 0x10:
        goto switchD_004714fc_caseD_10;
      case 0x13:
        goto switchD_004714fc_caseD_13;
      case 0x16:
        goto switchD_004714fc_caseD_16;
      }
    }
    switch(g_PlayerCurrentAnimationId) {
    case 10:
      g_PlayerCurrentAnimationId = 0xb;
      dataCursor = g_JaneSurfingSurfaceMotionTable;
      goto LAB_00471665;
    default:
      g_PlayerCurrentAnimationId = 2;
      dataCursor = g_JaneSurfingSurfAnimationScript;
      break;
    case 0xd:
      g_PlayerCurrentAnimationId = 0xe;
      dataCursor = g_JaneSurfingCurrentPathNode;
      goto LAB_00471695;
    case 0x10:
      g_PlayerCurrentAnimationId = 0x11;
      dataCursor = g_JaneSurfingNextPathNode;
      break;
    case 0x13:
      g_PlayerCurrentAnimationId = 0x14;
      dataCursor = g_JaneSurfingPathSegmentLength;
      goto LAB_00471665;
    case 0x16:
      g_PlayerCurrentAnimationId = 0x10;
      dataCursor = g_JaneSurfingCurrentPathSpeed;
      goto LAB_00471695;
    }
LAB_00471635:
    *(undefined **)(g_PlayerAnimationState + 0xc) = dataCursor;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    goto LAB_004716ae;
  }
  switch(g_PlayerCurrentAnimationId) {
  case 10:
switchD_004714fc_caseD_a:
    g_PlayerCurrentAnimationId = 0xb;
    dataCursor = g_JaneSurfingSurfaceMotionTable;
    goto LAB_00471635;
  default:
switchD_004714fc_caseD_b:
    g_PlayerCurrentAnimationId = 2;
    dataCursor = g_JaneSurfingSurfAnimationScript;
    break;
  case 0xd:
switchD_004714fc_caseD_d:
    g_PlayerCurrentAnimationId = 0xe;
    dataCursor = g_JaneSurfingCurrentPathNode;
    goto LAB_00471665;
  case 0x10:
switchD_004714fc_caseD_10:
    g_PlayerCurrentAnimationId = 0x11;
    dataCursor = g_JaneSurfingNextPathNode;
    break;
  case 0x13:
switchD_004714fc_caseD_13:
    g_PlayerCurrentAnimationId = 0x14;
    dataCursor = g_JaneSurfingPathSegmentLength;
    goto LAB_00471635;
  case 0x16:
switchD_004714fc_caseD_16:
    g_PlayerCurrentAnimationId = 0x17;
    dataCursor = g_JaneSurfingPathSegmentAngle;
LAB_00471665:
    *(undefined **)(g_PlayerAnimationState + 0xc) = dataCursor;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    goto LAB_004716ae;
  }
LAB_00471695:
  *(undefined **)(g_PlayerAnimationState + 0xc) = dataCursor;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
LAB_004716ae:
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_PlayerSurfaceMotionSpeed;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
    if (g_TarzanSurfingWithJaneActionSoundActive != '\0') {
      PlayAudioById(0x237,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
    g_TarzanSurfingWithJaneActionEffectTimer = 0;
    g_TarzanSurfingWithJaneActionSoundActive = '\0';
  }
  if (g_PlayerLoopingSoundHandle == 0) {
    PlayAudioById(0x79,(int *)&g_PlayerLoopingSoundHandle,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  }
  _g_TarzanSurfingWithJaneActionPhaseValue = 0xffffffff;
  return;
}

