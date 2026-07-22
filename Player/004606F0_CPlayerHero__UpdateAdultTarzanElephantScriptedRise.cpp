#include "tarzan_ghidra_types.hpp"

// Address: 0x004606F0
// Label: CPlayerHero::UpdateAdultTarzanElephantScriptedRise
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanElephantScriptedRise(void)

{
  short *value2;
  int value;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  undefined2 localState3;
  undefined2 localState2;
  undefined2 localState;
  
  if (g_AdultTarzanElephantEntitySceneObject != 0) {
    *(int *)(g_AdultTarzanElephantEntitySceneObject + 0x18) =
         *(int *)(g_AdultTarzanElephantEntitySceneObject + 0x18) + 0x28;
    *(short *)(g_AdultTarzanElephantEntitySceneObject + 0xa0) =
         *(short *)(g_AdultTarzanElephantEntitySceneObject + 0xa0) + 0x20;
    CPlayerHero::AdvanceAdultTarzanElephantAnimationFrames(0x11);
    GetSceneAttachmentWorldPositionByMask
              (g_AdultTarzanElephantEntitySceneObject,1,g_PlayerEntitySceneObject + 0x14);
    value2 = (short *)(g_PlayerEntitySceneObject + 0xa2);
    value = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                       g_AdultTarzanElephantDesiredFacingAngle);
    *value2 = *value2 + (short)(value >> 3);
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
  CPlayerHero::AdvanceAnimationScript();
  return;
}

