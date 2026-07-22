#include "tarzan_ghidra_types.hpp"

// Address: 0x004609B0
// Label: CPlayerHero::UpdateAdultTarzanElephantTransitionArc
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanElephantTransitionArc(void)

{
  ushort *dataCursor;
  short *value3;
  int value;
  int value2;
  
  CPlayerHero::AdvanceAnimationScript();
  *(int *)(g_PlayerEntitySceneObject + 0x14) =
       *(int *)(g_PlayerEntitySceneObject + 0x14) + _g_AdultTarzanElephantTransitionArcDeltaX;
  *(int *)(g_PlayerEntitySceneObject + 0x1c) =
       *(int *)(g_PlayerEntitySceneObject + 0x1c) + _g_AdultTarzanElephantTransitionArcDeltaZ;
  *(int *)(g_PlayerEntitySceneObject + 0x18) =
       (_g_AdultTarzanElephantTransitionArcElapsedTicks * _g_AdultTarzanElephantTransitionArcDeltaY
       - ((int)((&g_ParabolicArcHeightOffsetTable)[_g_AdultTarzanElephantTransitionArcPhase] << 9)
         >> 0xc)) + _g_AdultTarzanElephantTransitionArcBaseY;
  _g_AdultTarzanElephantTransitionArcPhase =
       _g_AdultTarzanElephantTransitionArcPhaseStep + _g_AdultTarzanElephantTransitionArcPhase &
       0xff;
  _g_AdultTarzanElephantTransitionArcElapsedTicks =
       _g_AdultTarzanElephantTransitionArcElapsedTicks + 1;
  value3 = (short *)(g_PlayerEntitySceneObject + 0xa2);
  value2 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),0x800);
  *value3 = *value3 + (short)(value2 >> 4);
  if (g_AdultTarzanElephantLevelExitDismountActive == 0) {
    if (_g_AdultTarzanElephantTransitionArcPhase == 0) {
      InitHudExtraLifeMeter();
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 6;
      (*(code *)g_AdultTarzanElephantEnterTransitionArcHandlerPtr)();
      if (g_AdultTarzanElephantEntitySceneObject != 0) {
        *(byte *)(g_AdultTarzanElephantEntitySceneObject + 0xf) =
             *(byte *)(g_AdultTarzanElephantEntitySceneObject + 0xf) | 0x80;
        value = g_AdultTarzanElephantEntitySceneObject;
        value2 = *(int *)(g_AdultTarzanElephantMountTargetEntity + 0x38);
        *(undefined4 *)(g_AdultTarzanElephantEntitySceneObject + 0x14) =
             *(undefined4 *)(value2 + 0x14);
        *(undefined4 *)(value + 0x18) = *(undefined4 *)(value2 + 0x18);
        *(undefined4 *)(value + 0x1c) = *(undefined4 *)(value2 + 0x1c);
        *(undefined2 *)(g_AdultTarzanElephantEntitySceneObject + 0xc) =
             _g_AdultTarzanElephantMountArrivalModelFrameTable;
        GetSceneAttachmentWorldPositionByMask
                  (g_AdultTarzanElephantEntitySceneObject,1,g_PlayerEntitySceneObject + 0x14);
      }
      dataCursor = (ushort *)(*(int *)(g_AdultTarzanElephantMountTargetEntity + 0x38) + 0xe);
      *dataCursor = *dataCursor & 0x7fff;
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(g_AdultTarzanElephantMountTargetEntity);
      return;
    }
  }
  else {
    _g_AdultTarzanElephantExitResourceReleaseTicks =
         _g_AdultTarzanElephantExitResourceReleaseTicks + 1;
    if (_g_AdultTarzanElephantExitResourceReleaseTicks == 0x10) {
      ReleaseWorldSceneAuxResourceNoOp(g_CurrentWorldSceneContext,2);
    }
    if (_g_AdultTarzanElephantTransitionArcPhase == 0) {
      _g_PlayerHeroMode = 1;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x47;
      (*(code *)g_AdultTarzanActionCallback_Field0220)();
      g_PlayerMoveHeadingAngle = 0x800;
      if (g_AdultTarzanElephantEntitySceneObject != 0) {
        *(ushort *)(g_AdultTarzanElephantEntitySceneObject + 0xe) =
             *(ushort *)(g_AdultTarzanElephantEntitySceneObject + 0xe) & 0x7fff;
        UnloadEncodedResourceId(0x27);
        UnloadEncodedResourceId(0x27);
      }
    }
  }
  return;
}

