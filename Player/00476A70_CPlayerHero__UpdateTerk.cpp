#include "tarzan_ghidra_types.hpp"

// Address: 0x00476A70
// Label: CPlayerHero::UpdateTerk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateTerk(void)

{
  char resultFlag;
  
  if (g_PlayerActionState != 0x10) {
    if (g_PlayerBalanceWobbleTimer < 0) {
      g_PlayerBalanceWobbleTimer = g_PlayerBalanceWobbleTimer + 1;
    }
    else if ((g_PlayerEdgeBalanceInputMask & g_PlayerInputHeldMask) != 0) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x10;
      (*(code *)g_TerkActionState_Field01C8)();
    }
  }
  if (g_PlayerCurrentCollisionMode == 2) {
    resultFlag = ShouldMirrorCameraFollowSideForActiveAnchor();
    if (resultFlag == '\0') {
      g_CameraRelativeTurnInputMask = 0x20;
      g_CameraFollowFlags = 0x80;
    }
    else {
      g_CameraRelativeTurnInputMask = 0x80;
      g_CameraFollowFlags = 0x20;
    }
  }
  else {
    g_CameraRelativeTurnInputMask = 0xa0;
    g_CameraFollowFlags = 0x10;
  }
  CPlayerHero::RefreshClimbableEdgeCollisionContext();
  g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraFollowFlags;
  (*(code *)(&g_TerkActionStateUpdateColumn)[(uint)g_PlayerActionState * 2])();
  CPlayerHero::UpdateEntitySceneObjectFacingAngles();
  if (g_PlayerActionState == 0) {
    g_PlayerTerkPlankMonkeyInteractionState = g_PlayerTerkPlankMonkeyInteractionState + 1;
    return;
  }
  g_PlayerTerkPlankMonkeyInteractionState = 0;
  return;
}

