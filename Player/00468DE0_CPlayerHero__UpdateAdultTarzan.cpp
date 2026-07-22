#include "tarzan_ghidra_types.hpp"

// Address: 0x00468DE0
// Label: CPlayerHero::UpdateAdultTarzan
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzan(void)

{
  char resultFlag;
  
  if (g_ActiveSwingEntityList != 0) {
    g_MaxSwingSegmentIndex = *(undefined4 *)(g_ActiveSwingEntityList + 0x50);
  }
  if (g_PlayerActionState != 0xc) {
    if (g_PlayerBalanceWobbleTimer < 0) {
      g_PlayerBalanceWobbleTimer = g_PlayerBalanceWobbleTimer + 1;
    }
    else if ((g_PlayerEdgeBalanceInputMask & g_PlayerInputHeldMask) != 0) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0xc;
      (*(code *)g_AdultTarzanEnterEdgeBalanceHandlerPtr)();
    }
  }
  if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
    if (g_PlayerCurrentCollisionMode == 0) goto LAB_00468eb5;
    if (g_PlayerCurrentCollisionMode == 1) {
      CPlayerHero::BuildCameraRelativeInputMasks();
    }
    else if (g_PlayerCurrentCollisionMode == 2) {
      resultFlag = ShouldMirrorCameraFollowSideForActiveAnchor();
      if (resultFlag == '\0') {
        g_CameraRelativeTurnInputMask = 0x20;
        g_CameraFollowFlags = 0x90;
      }
      else {
        g_CameraRelativeTurnInputMask = 0x80;
        g_CameraFollowFlags = 0x30;
      }
    }
    else {
      g_CameraRelativeTurnInputMask = 0xa0;
      g_CameraFollowFlags = 0x10;
    }
  }
  else {
    g_CameraRelativeTurnInputMask = 0;
    g_CameraFollowFlags = 0;
  }
  CPlayerHero::RefreshClimbableEdgeCollisionContext();
LAB_00468eb5:
  (*(code *)(&g_AdultTarzanActionStateUpdateColumn)[(uint)g_PlayerActionState * 2])();
  CPlayerHero::UpdateEntitySceneObjectFacingAngles();
  return;
}

