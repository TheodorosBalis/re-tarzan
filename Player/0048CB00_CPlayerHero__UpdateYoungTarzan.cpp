#include "tarzan_ghidra_types.hpp"

// Address: 0x0048CB00
// Label: CPlayerHero::UpdateYoungTarzan
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungTarzan(void)

{
  char resultFlag;
  
  if ((g_PlayerPickupInteractionFlags & 0x4000) != 0) {
    g_TutorialPickupSkipApproachFlag = g_PlayerInputPressedMask & 0x4000;
    if ((g_PlayerInputPressedMask & 0x80) != 0) {
      g_InputPreviousMask = g_InputPreviousMask & 0xffffff7f;
    }
    if ((g_PlayerInputPressedMask & 0x20) != 0) {
      g_InputPreviousMask = g_InputPreviousMask & 0xffffffdf;
    }
  }
  if (g_PlayerActionState != 0xd) {
    if (g_PlayerBalanceWobbleTimer < 0) {
      g_PlayerBalanceWobbleTimer = g_PlayerBalanceWobbleTimer + 1;
    }
    else if (((g_PlayerInputHeldMask & g_PlayerEdgeBalanceInputMask) != 0) &&
            (g_PlayerPickupInteractionFlags == 0)) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0xd;
      (*(code *)g_YoungEnterEdgeBalanceHandlerPtr)();
    }
  }
  switch(g_PlayerCurrentCollisionMode) {
  case 0:
    goto switchD_0048cb94_caseD_0;
  case 1:
    CPlayerHero::BuildCameraRelativeInputMasks();
    break;
  case 2:
    resultFlag = ShouldMirrorCameraFollowSideForActiveAnchor();
    if (resultFlag == '\0') {
      g_CameraRelativeTurnInputMask = 0x20;
      g_CameraFollowFlags = 0x90;
    }
    else {
      g_CameraRelativeTurnInputMask = 0x80;
      g_CameraFollowFlags = 0x30;
    }
    break;
  default:
    g_CameraRelativeTurnInputMask = 0xa0;
    g_CameraFollowFlags = 0x10;
  }
  CPlayerHero::RefreshClimbableEdgeCollisionContext();
switchD_0048cb94_caseD_0:
  (**(code **)(&g_YoungTarzanActionStateUpdateColumn + (uint)g_PlayerActionState * 8))();
  CPlayerHero::UpdateEntitySceneObjectFacingAngles();
  return;
}

