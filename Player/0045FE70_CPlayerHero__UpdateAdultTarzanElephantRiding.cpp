#include "tarzan_ghidra_types.hpp"

// Address: 0x0045FE70
// Label: CPlayerHero::UpdateAdultTarzanElephantRiding
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanElephantRiding(void)

{
  short *value3;
  undefined2 value2;
  int value;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  undefined2 localState3;
  undefined2 localState2;
  undefined2 localState;
  
  g_AdultTarzanElephantCameraLeadTarget = 2000;
  CPlayerHero::ApplyAdultTarzanElephantForwardMotionXZ();
  CPlayerHero::ApproachAdultTarzanElephantForwardSpeed();
  CPlayerHero::AdvanceAnimationScript();
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    g_AdultTarzanElephantDesiredFacingAngle = -*(int *)(value + 0x1c) - 0x800U & 0xfff;
    if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
      g_AdultTarzanElephantDesiredFacingAngle = (-*(int *)(value + 0x1c) - 0x800U & 0xfff) + 0x1c2;
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 100;
    }
    if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
      g_AdultTarzanElephantDesiredFacingAngle = (-*(int *)(value + 0x1c) - 0x800U & 0xfff) - 0x1c2;
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 100;
    }
  }
  if (g_AdultTarzanElephantEntitySceneObject != 0) {
    CPlayerHero::AdvanceAdultTarzanElephantAnimationFrames(0x11);
    GetSceneAttachmentWorldPositionByMask
              (g_AdultTarzanElephantEntitySceneObject,1,g_PlayerEntitySceneObject + 0x14);
    value3 = (short *)(g_PlayerEntitySceneObject + 0xa2);
    value = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                       g_AdultTarzanElephantDesiredFacingAngle);
    *value3 = *value3 + (short)(value >> 3);
    *(undefined2 *)(g_AdultTarzanElephantEntitySceneObject + 0xa2) =
         *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2);
    localState3 = 0;
    localState2 = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2);
    localState = 0;
    g_ModelHierarchyTransformStackBaseTranslationX = 0;
    g_ModelHierarchyTransformStackBaseTranslationY = 0;
    g_ModelHierarchyTransformStackBaseTranslationZ = 0;
    BuildBasisMatrixFromEulerAngles(&localState3,&g_ModelHierarchyTransformStackBase);
    dataCursor = (undefined4 *)
             BuildEntitySceneObjectModelBoneWorldBasis(g_AdultTarzanElephantEntitySceneObject,7);
    dataCursor[5] = 0;
    dataCursor[6] = 0;
    dataCursor[7] = 0;
    dataCursor2 = (undefined4 *)(g_PlayerEntitySceneObject + 0xb8);
    for (value = 8; value != 0; value = value + -1) {
      *dataCursor2 = *dataCursor;
      dataCursor = dataCursor + 1;
      dataCursor2 = dataCursor2 + 1;
    }
    *(undefined4 *)(g_PlayerEntitySceneObject + 0xf8) = FrameCount;
  }
  value2 = g_PlayerActionState;
  if (((byte)g_PlayerInputPressedMask & 0x40) != 0) {
    g_PlayerActionState = 5;
    g_PreviousPlayerActionState = value2;
    (*(code *)PTR_CPlayerHero__EnterAdultTarzanElephantRiderAction_005058f0)();
  }
  return;
}

