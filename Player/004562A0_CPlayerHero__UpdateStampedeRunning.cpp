#include "tarzan_ghidra_types.hpp"

// Address: 0x004562A0
// Label: CPlayerHero::UpdateStampedeRunning
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStampedeRunning(void)

{
  short *value5;
  undefined2 value3;
  char resultFlag;
  int value;
  int value2;
  uint value4;
  
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(g_PlayerEntitySceneObject);
    resultFlag = CPlayerHero::TrySnapToNearbyGround();
    value3 = g_PlayerActionState;
    if (resultFlag == '\0') {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = value3;
      (*(code *)g_StampedeEnterFallingHandlerPtr)();
      return;
    }
    value4 = -*(int *)(value + 0x1c) - 0x800U & 0xfff;
    if (g_StampedeForceRunTowardExit == 0) {
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xffffc400;
      if (((byte)g_PlayerInputHeldMask & 0x40) != 0) {
        *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xffffc400;
      }
      if (((byte)g_PlayerInputHeldMask & 0x10) != 0) {
        *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xffffe200;
      }
      value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
      value3 = g_PlayerActionState;
      if (value2 != 0) {
        if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
          value4 = (-*(int *)(value + 0x1c) - 0x800U & 0xfff) - 0x1c2;
        }
        if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
          value4 = (-*(int *)(value + 0x1c) - 0x800U & 0xfff) + 0x1c2;
        }
      }
      if ((g_PlayerInputPressedMask & 0x200000) != 0) {
        g_PlayerActionState = 2;
        g_PreviousPlayerActionState = value3;
        (*(code *)g_StampedeEnterJumpHandlerPtr)();
        return;
      }
      value5 = (short *)(g_PlayerEntitySceneObject + 0xa2);
      value = GetWrappedSignedAngleDelta12Bit
                        ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),value4);
      *value5 = *value5 + (short)(value >> 3);
      CPlayerHero::ApproachStampedeForwardSpeed();
      CPlayerHero::ApplyStampedeForwardMotionXZ();
      CPlayerHero::AdvanceAnimationScript();
      return;
    }
    value = GetAngleFromXZVector12Bit
                      (0x505b - *(int *)(g_PlayerEntitySceneObject + 0x14),
                       -0x24a0c - *(int *)(g_PlayerEntitySceneObject + 0x1c));
    value5 = (short *)(g_PlayerEntitySceneObject + 0xa2);
    value = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),value - 0x800U & 0xfff);
    *value5 = *value5 + (short)(value >> 3);
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xffffba00;
    CPlayerHero::ApproachStampedeForwardSpeed();
    CPlayerHero::ApplyStampedeForwardMotionXZ();
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

