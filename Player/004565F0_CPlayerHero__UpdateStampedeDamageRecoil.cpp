#include "tarzan_ghidra_types.hpp"

// Address: 0x004565F0
// Label: CPlayerHero::UpdateStampedeDamageRecoil
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateStampedeDamageRecoil(void)

{
  short *value3;
  undefined2 value2;
  char resultFlag;
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    value3 = (short *)(g_PlayerEntitySceneObject + 0xa2);
    _g_StampedeDamageRecoilFacingTarget = -*(int *)(value + 0x1c) - 0x800U & 0xfff;
    value = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                       _g_StampedeDamageRecoilFacingTarget);
    *value3 = *value3 + (short)(value >> 4);
    CPlayerHero::ApproachStampedeLateralRecoilSpeedAndMoveX();
    CPlayerHero::ApproachStampedeRecoilForwardSpeedAndMoveZ();
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(g_PlayerEntitySceneObject);
    resultFlag = CPlayerHero::TrySnapToNearbyGround();
    if (resultFlag == '\0') {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
           *(int *)(g_PlayerEntitySceneObjectData + 0xc) + 0x20;
    }
  }
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if (value != 0) {
    g_PlayerActionState = 1;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00456687. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_StampedeEnterRunningHandlerPtr)();
    return;
  }
  return;
}

