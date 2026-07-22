#include "tarzan_ghidra_types.hpp"

// Address: 0x004601C0
// Label: CPlayerHero::UpdateAdultTarzanElephantMountArrival
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanElephantMountArrival(void)

{
  short *value2;
  int value;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  undefined2 localState3;
  undefined2 localState2;
  undefined2 localState;
  
  CPlayerHero::AdvanceAnimationScript();
  RefreshEntitySceneObjectNatureTerrainVerticalDelta(g_AdultTarzanElephantEntitySceneObject);
  CEntities::CheckEntitySceneObjectCollisionDelta(g_AdultTarzanElephantEntitySceneObject);
  if (*(char *)(g_PlayerEntitySceneObject + 0x74) == '\0') {
    PlayAudioById(0x48,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    PlayAudioById(0x46,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  }
  if (*(char *)(g_PlayerEntitySceneObject + 0x74) == '\x0e') {
    PlayAudioById(0x3bb,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  }
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
    CPlayerHero::AdvanceAdultTarzanElephantAnimationFrames(0x36);
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
  if (*(char *)(g_PlayerEntitySceneObject + 0x74) == '6') {
    *(undefined1 *)(g_PlayerEntitySceneObject + 0x74) = 6;
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 1;
    (*(code *)g_AdultTarzanElephantEnterIdleHandlerPtr)();
  }
  return;
}

