#include "tarzan_ghidra_types.hpp"

// Address: 0x0048DD80
// Label: CPlayerHero::EnterYoungTarzanFalling
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungTarzanFalling(void)

{
  int value;
  undefined2 value2;
  char resultFlag;
  
  value = g_PlayerEntitySceneObject;
  if (*(int *)(g_PlayerEntitySceneObject + 0x60) != 0) {
    *(undefined4 *)(*(int *)(g_PlayerEntitySceneObject + 0x60) + 0x60) = 0;
  }
  *(undefined4 *)(value + 0x60) = 0;
  resultFlag = CPlayerHero::IsOnTreeSurfingSurface();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    if (g_PreviousPlayerActionState == 0x23) {
      CPlayerHero::PlayAnimation(0x11);
      return;
    }
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x30;
    g_PlayerTargetMoveSpeed = 0x30;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 4;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x10;
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
    *(undefined4 *)(g_PlayerMotionState + 0x24) = 4;
    *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
    if ((g_PlayerCurrentAnimationId != 0x8d) && (g_PlayerCurrentAnimationId != 0x91)) {
      switch(g_PreviousPlayerActionState) {
      case 5:
        g_CurrentSwingEntity = 0;
        g_PlayerActionState = 8;
        return;
      case 6:
      case 0x30:
      case 0x31:
        break;
      case 0xe:
      case 0x10:
        CPlayerHero::PlayAnimation(0x28);
        g_CurrentSwingEntity = 0;
        g_PlayerActionState = 0x11;
        return;
      case 0x18:
      case 0x1d:
        if (g_CurrentSwingEntity == 0) {
          if (g_PlayerAnimationSurfaceSide == '\0') {
            CPlayerHero::PlayAnimation(0x5b);
            g_CurrentSwingEntity = 0;
            return;
          }
          CPlayerHero::PlayAnimation(0x5c);
          g_CurrentSwingEntity = 0;
          return;
        }
      default:
        CPlayerHero::PlayAnimation(0x11);
      }
    }
    g_CurrentSwingEntity = 0;
    return;
  }
  g_PlayerActionState = 0x24;
  g_PreviousPlayerActionState = value2;
  (*(code *)g_YoungEnterDiveHandlerPtr)();
  return;
}

