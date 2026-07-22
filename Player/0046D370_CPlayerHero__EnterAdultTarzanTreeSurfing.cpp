#include "tarzan_ghidra_types.hpp"

// Address: 0x0046D370
// Label: CPlayerHero::EnterAdultTarzanTreeSurfing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterAdultTarzanTreeSurfing(void)

{
  undefined4 value;
  
  if (g_PlayerTreeSurfingLateralThresholdSide == 1) {
    switch(g_PlayerCurrentAnimationId) {
    case 0x30:
      goto switchD_0046d393_caseD_30;
    default:
      goto switchD_0046d393_caseD_31;
    case 0x33:
      goto switchD_0046d393_caseD_33;
    case 0x36:
      goto switchD_0046d393_caseD_36;
    case 0x39:
      goto switchD_0046d393_caseD_39;
    case 0x3c:
switchD_0046d393_caseD_3c:
      value = 0x3d;
      goto LAB_0046d3f2;
    }
  }
  if (g_PlayerTreeSurfingLateralThresholdSide != 2) {
    switch(g_PlayerCurrentAnimationId) {
    case 0x30:
switchD_0046d393_caseD_30:
      value = 0x31;
      break;
    default:
switchD_0046d393_caseD_31:
      value = 0x25;
      break;
    case 0x33:
switchD_0046d393_caseD_33:
      value = 0x34;
      break;
    case 0x36:
switchD_0046d393_caseD_36:
      value = 0x37;
      break;
    case 0x39:
switchD_0046d393_caseD_39:
      value = 0x3a;
      break;
    case 0x3c:
      goto switchD_0046d393_caseD_3c;
    }
LAB_0046d3f2:
    CPlayerHero::PlayAdultTarzanAnimation(value);
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_PlayerSurfaceMotionSpeed;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x80;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
    if (g_PlayerLoopingSoundHandle == 0) {
      PlayAudioById(0x79,(int *)&g_PlayerLoopingSoundHandle,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
    _g_TarzanTreeSurfingJumpSurfaceState = 0xffffffff;
    return;
  }
  switch(g_PlayerCurrentAnimationId) {
  case 0x30:
    goto switchD_0046d393_caseD_30;
  default:
    goto switchD_0046d393_caseD_31;
  case 0x33:
    goto switchD_0046d393_caseD_33;
  case 0x36:
    goto switchD_0046d393_caseD_36;
  case 0x39:
    goto switchD_0046d393_caseD_39;
  case 0x3c:
    value = 0x36;
    goto LAB_0046d3f2;
  }
}

