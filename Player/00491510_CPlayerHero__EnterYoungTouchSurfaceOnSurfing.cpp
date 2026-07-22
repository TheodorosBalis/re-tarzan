#include "tarzan_ghidra_types.hpp"

// Address: 0x00491510
// Label: CPlayerHero::EnterYoungTouchSurfaceOnSurfing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterYoungTouchSurfaceOnSurfing(void)

{
  undefined4 value;
  
  if (g_PlayerTreeSurfingLateralThresholdSide == 1) {
    switch(g_PlayerCurrentAnimationId) {
    case 0x2e:
      goto switchD_00491533_caseD_2e;
    default:
      goto switchD_00491533_caseD_2f;
    case 0x31:
      goto switchD_00491533_caseD_31;
    case 0x34:
      goto switchD_00491533_caseD_34;
    case 0x37:
      goto switchD_00491533_caseD_37;
    case 0x3a:
switchD_00491533_caseD_3a:
      value = 0x3b;
      goto LAB_00491592;
    }
  }
  if (g_PlayerTreeSurfingLateralThresholdSide != 2) {
    switch(g_PlayerCurrentAnimationId) {
    case 0x2e:
switchD_00491533_caseD_2e:
      value = 0x2f;
      break;
    default:
switchD_00491533_caseD_2f:
      value = 0x23;
      break;
    case 0x31:
switchD_00491533_caseD_31:
      value = 0x32;
      break;
    case 0x34:
switchD_00491533_caseD_34:
      value = 0x35;
      break;
    case 0x37:
switchD_00491533_caseD_37:
      value = 0x38;
      break;
    case 0x3a:
      goto switchD_00491533_caseD_3a;
    }
LAB_00491592:
    CPlayerHero::PlayAnimation(value);
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_PlayerSurfaceMotionSpeed;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x80;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
    if (g_PlayerLoopingSoundHandle == 0) {
      PlayAudioById(0x29,(int *)&g_PlayerLoopingSoundHandle,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
    _g_TreeSurfingReboundTimer = 0xffffffff;
    return;
  }
  switch(g_PlayerCurrentAnimationId) {
  case 0x2e:
    goto switchD_00491533_caseD_2e;
  default:
    goto switchD_00491533_caseD_2f;
  case 0x31:
    goto switchD_00491533_caseD_31;
  case 0x34:
    goto switchD_00491533_caseD_34;
  case 0x37:
    goto switchD_00491533_caseD_37;
  case 0x3a:
    value = 0x34;
    goto LAB_00491592;
  }
}

