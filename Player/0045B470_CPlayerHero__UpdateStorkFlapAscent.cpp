#include "tarzan_ghidra_types.hpp"

// Address: 0x0045B470
// Label: CPlayerHero::UpdateStorkFlapAscent
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStorkFlapAscent(void)

{
  short *value4;
  undefined2 value2;
  int value;
  uint value3;
  
  value3 = 0;
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    value3 = -*(int *)(value + 0x1c) - 0x800U & 0xfff;
  }
  if (((g_StorkTerrainCollisionFlags & 1) != 0) && (g_StorkImpactReactionCooldownActive == 0)) {
    CPlayerHero::EnterStorkTerrainImpactReaction();
    return;
  }
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
  value4 = (short *)(g_PlayerEntitySceneObject + 0xa2);
  value = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),value3);
  *value4 = *value4 + (short)(value >> 4);
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_StorkFlapBoostStage = g_StorkFlapBoostStage + 1;
    if (g_StorkFlapBoostStage < 5) {
      *(undefined4 *)(g_PlayerMotionState + 0x20) =
           *(undefined4 *)(&g_StorkFlapVerticalVelocityTable + g_StorkFlapBoostStage * 4);
      *(undefined4 *)(g_PlayerMotionState + 0x24) = 5;
    }
  }
  value = CPlayerHero::IntegrateStorkVerticalMotion();
  value2 = g_PlayerActionState;
  if (value != 0) {
    if ((g_StorkTerrainCollisionFlags & 2) != 0) {
      PlayAudioById(0x41b,(int *)0,(undefined4 *)0);
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 2;
      (*(code *)g_StorkEnterLowAltitudeFlightHandlerPtr)();
      return;
    }
    g_PlayerActionState = 1;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_StorkEnterFreeFlightHandlerPtr)();
    return;
  }
  CPlayerHero::ApproachStorkForwardSpeed();
  CPlayerHero::ClampStorkFlightSpeedAndTilt();
  CPlayerHero::ApplyStorkForwardMotionXZ();
  CPlayerHero::AdvanceAnimationScript();
  return;
}

