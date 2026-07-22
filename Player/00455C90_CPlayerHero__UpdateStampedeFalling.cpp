#include "tarzan_ghidra_types.hpp"

// Address: 0x00455C90
// Label: CPlayerHero::UpdateStampedeFalling
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStampedeFalling(void)

{
  short *value4;
  undefined2 value2;
  char resultFlag;
  int value;
  uint value3;
  
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    CPlayerHero::UpdateJumpArcVerticalMotion(0);
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(g_PlayerEntitySceneObject);
    value3 = -*(int *)(value + 0x1c) - 0x800U & 0xfff;
    resultFlag = CPlayerHero::TryResolveGroundContactSnap();
    value2 = g_PlayerActionState;
    if (resultFlag != '\0') {
      g_PlayerActionState = 1;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_StampedeEnterRunningHandlerPtr)();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
      value3 = (-*(int *)(value + 0x1c) - 0x800U & 0xfff) - 0x1c2;
    }
    if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
      value3 = (-*(int *)(value + 0x1c) - 0x800U & 0xfff) + 0x1c2;
    }
    value4 = (short *)(g_PlayerEntitySceneObject + 0xa2);
    value = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),value3)
    ;
    *value4 = *value4 + (short)(value >> 3);
    CPlayerHero::ApproachStampedeForwardSpeed();
    CPlayerHero::ApplyStampedeForwardMotionXZ();
    CPlayerHero::AdvanceAnimationScript();
  }
  return;
}

