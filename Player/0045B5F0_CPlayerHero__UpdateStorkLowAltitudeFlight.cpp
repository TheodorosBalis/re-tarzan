#include "tarzan_ghidra_types.hpp"

// Address: 0x0045B5F0
// Label: CPlayerHero::UpdateStorkLowAltitudeFlight
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStorkLowAltitudeFlight(void)

{
  short *value5;
  int value;
  undefined2 value3;
  int value2;
  uint value4;
  
  value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value2 != 0) {
    value = *(int *)(value2 + 0x1c);
    *(undefined2 *)(g_PlayerEntitySceneObject + 0xa6) = 1;
    value3 = g_PlayerActionState;
    value4 = -value - 0x800U & 0xfff;
    if (((g_StorkTerrainCollisionFlags & 9) != 0) && (g_StorkImpactReactionCooldownActive == 0)) {
      g_PlayerActionState = 4;
      g_PreviousPlayerActionState = value3;
      (*(code *)g_StorkEnterTerrainImpactReactionHandlerPtr)();
      return;
    }
    if ((g_StorkTerrainCollisionFlags & 2) != 0) {
      g_StorkFlapBoostStage = 0;
    }
    if ((g_StorkTerrainCollisionFlags & 0x40) != 0) {
      g_PlayerActionState = 1;
      g_PreviousPlayerActionState = value3;
      (*(code *)g_StorkEnterFreeFlightHandlerPtr)();
      return;
    }
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x3f00;
    if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
      value4 = (-*(int *)(value2 + 0x1c) - 0x800U & 0xfff) - 0x140;
    }
    if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
      value4 = (-*(int *)(value2 + 0x1c) - 0x800U & 0xfff) + 0x140;
    }
    if (((byte)g_PlayerInputHeldMask & 0x10) != 0) {
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x3f00;
    }
    if (((byte)g_PlayerInputHeldMask & 0x40) != 0) {
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x3000;
    }
    if (0x3eff < (int)(*(uint *)(g_PlayerMotionState + 0x10) & 0xffffff00)) {
      *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x700;
    }
    value5 = (short *)(g_PlayerEntitySceneObject + 0xa2);
    value2 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),value4)
    ;
    *value5 = *value5 + (short)(value2 >> 3);
    if (((g_PlayerInputPressedMask & 0x200000) != 0) && (g_StorkFlapBoostStage < 5)) {
      *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x38;
      PlayAudioById(0x41a,(int *)0,(undefined4 *)0);
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 3;
      (*(code *)g_StorkEnterFlapAscentHandlerPtr)();
      return;
    }
    value5 = (short *)(g_PlayerEntitySceneObject + 0xa0);
    value2 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa0),0);
    *value5 = *value5 + (short)(value2 >> 2);
    value5 = (short *)(g_PlayerEntitySceneObject + 0xa4);
    value2 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa4),0);
    *value5 = *value5 + (short)(value2 >> 2);
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + 0x20;
    CPlayerHero::ApproachStorkForwardSpeed();
    CPlayerHero::ClampStorkFlightSpeedAndTilt();
    CPlayerHero::ApplyStorkForwardMotionXZ();
    if ((g_StorkTerrainCollisionFlags & 4) != 0) {
      *(undefined **)(g_PlayerAnimationState + 0xc) = &DAT_00503ee8;
      CPlayerHero::AdvanceAnimationScript();
      return;
    }
    *(undefined **)(g_PlayerAnimationState + 0xc) = &DAT_00503e3c;
    CPlayerHero::AdvanceAnimationScript();
  }
  return;
}

