#include "tarzan_ghidra_types.hpp"

// Address: 0x0045B2D0
// Label: CPlayerHero::UpdateStorkFreeFlight
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStorkFreeFlight(void)

{
  short *value4;
  undefined2 value2;
  int value;
  uint value3;
  
  value3 = 0;
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  value2 = g_PlayerActionState;
  if (value != 0) {
    value3 = -*(int *)(value + 0x1c) - 0x800U & 0xfff;
  }
  if (((g_StorkTerrainCollisionFlags & 1) != 0) && (g_StorkImpactReactionCooldownActive == 0)) {
    g_PlayerActionState = 4;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_StorkEnterTerrainImpactReactionHandlerPtr)();
    return;
  }
  if ((g_StorkTerrainCollisionFlags & 2) != 0) {
    g_StorkFlapBoostStage = 0;
    PlayAudioById(0x41b,(int *)0,(undefined4 *)0);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 2;
    (*(code *)g_StorkEnterLowAltitudeFlightHandlerPtr)();
    return;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xffffffe8;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x3f00;
  if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
    *(short *)(g_PlayerEntitySceneObject + 0xa4) = *(short *)(g_PlayerEntitySceneObject + 0xa4) + 10
    ;
    value3 = (-*(int *)(value + 0x1c) - 0x800U & 0xfff) - 0x140;
  }
  if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
    *(short *)(g_PlayerEntitySceneObject + 0xa4) =
         *(short *)(g_PlayerEntitySceneObject + 0xa4) + -10;
    value3 = (-*(int *)(value + 0x1c) - 0x800U & 0xfff) + 0x140;
  }
  if (((g_PlayerInputPressedMask & 0x200000) != 0) && (g_StorkFlapBoostStage < 5)) {
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  }
  if (((byte)g_PlayerInputHeldMask & 0x10) != 0) {
    *(short *)(g_PlayerEntitySceneObject + 0xa0) =
         *(short *)(g_PlayerEntitySceneObject + 0xa0) + 0xf;
  }
  if (((byte)g_PlayerInputHeldMask & 0x40) != 0) {
    *(short *)(g_PlayerEntitySceneObject + 0xa0) =
         *(short *)(g_PlayerEntitySceneObject + 0xa0) + -0xf;
  }
  value4 = (short *)(g_PlayerEntitySceneObject + 0xa2);
  value = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),value3);
  *value4 = *value4 + (short)(value >> 4);
  CPlayerHero::IntegrateStorkVerticalMotion();
  CPlayerHero::ApproachStorkForwardSpeed();
  CPlayerHero::ClampStorkFlightSpeedAndTilt();
  CPlayerHero::DampStorkPitchAndRoll();
  CPlayerHero::ApplyStorkForwardMotionXZ();
  CPlayerHero::AdvanceAnimationScript();
  return;
}

