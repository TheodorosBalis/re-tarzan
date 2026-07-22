#include "tarzan_ghidra_types.hpp"

// Address: 0x0046E4B0
// Label: ReleasePlayerFromSwingMode1
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleasePlayerFromSwingMode1(void)

{
  undefined2 value4;
  int value;
  int value2;
  int value3;
  short shortValue;
  uint value5;
  
  value5 = 0;
  shortValue = 0;
  value = CEntities::FindEntityAttachmentByFlags(g_CurrentSwingEntity,0x8000000);
  if (value != 0) {
    *(undefined2 *)(value + 0xe) = 4;
    value5 = (uint)*(ushort *)(g_ActiveSwingMotionTable + 8 + (uint)*(ushort *)(value + 0x10) * 0xc);
    shortValue = *(short *)(g_ActiveSwingMotionTable + 10 + (uint)*(ushort *)(value + 0x10) * 0xc);
  }
  value4 = g_PlayerActionState;
  if (g_CurrentSwingEntity != 0) {
    PlayAudioById(0x56,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    if ((g_PreviousPlayerActionState == 0x1e) && (value5 != 0)) {
      SnapEntitySceneObjectVerticalPositionToCurrentSurface(g_PlayerEntitySceneObject);
      value = *(int *)(g_PlayerEntitySceneObjectData + 8) -
              *(int *)(g_PlayerEntitySceneObject + 0x48);
      value2 = *(int *)(g_PlayerEntitySceneObjectData + 0xc) -
              *(int *)(g_PlayerEntitySceneObject + 0x4c);
      value3 = *(int *)(g_PlayerEntitySceneObjectData + 0x10) -
              *(int *)(g_PlayerEntitySceneObject + 0x50);
      value = SqrtToInt(value3 * value3 + value2 * value2 + value * value);
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x40;
      g_PlayerTargetMoveSpeed = 0x40;
      *(int *)(g_PlayerMotionState + 0x10) = (value >> 7) + 0x10;
      *(undefined4 *)(g_PlayerMotionState + 0x18) = 1;
      *(undefined4 *)(g_PlayerMotionState + 0x14) = 4;
      *(undefined4 *)(g_PlayerMotionState + 0x20) = *(undefined4 *)(g_PlayerMotionState + 0x10);
      *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x70;
      *(undefined4 *)(g_PlayerMotionState + 0x24) = 5;
      *(undefined4 *)(g_PlayerMotionState + 0x28) = 8;
      *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
      value = g_CurrentSwingSegmentIndex;
      if (g_MaxSwingSegmentIndex < g_CurrentSwingSegmentIndex) {
        value = g_MaxSwingSegmentIndex;
      }
      *(int *)(g_PlayerMotionState + 0x20) = value << 3;
      if (*(int *)(g_PlayerMotionState + 0x20) < 0x20) {
        *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x20;
      }
      CPlayerHero::UpdateMovementAndCollision(1);
      CPlayerHero::UpdateJumpArcVerticalMotion(0);
      g_PlayerMoveHeadingAngle = *(ushort *)(g_PlayerEntitySceneObject + 0x132);
      if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
        g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle ^ 0x800;
      }
      *(ushort *)(g_PlayerEntitySceneObject + 0xa2) = g_PlayerMoveHeadingAngle;
      g_PlayerCurrentAnimationId = (undefined2)value5;
      *(undefined **)(g_PlayerAnimationState + 0xc) = (&g_AdultTarzanAnimationScriptPtrTable)[value5]
      ;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(short *)(g_PlayerAnimationState + 0x16) = shortValue + -1;
      CPlayerHero::AdvanceAnimationScript();
      g_PlayerJumpArcActive = 0;
      return;
    }
    if (g_PreviousPlayerActionState == 0x17) {
      if (*(byte *)(g_PlayerEntitySceneObject + 0x75) != g_PlayerFacingBeforeSwing) {
        *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
        *(ushort *)(g_PlayerEntitySceneObject + 0xa2) =
             *(ushort *)(g_PlayerEntitySceneObject + 0xa2) ^ 0x800;
      }
    }
    SnapEntitySceneObjectVerticalPositionToCurrentSurface(g_PlayerEntitySceneObject);
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    g_PlayerTargetMoveSpeed = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 4;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x70;
    *(undefined4 *)(g_PlayerMotionState + 0x24) = 5;
    *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
    CPlayerHero::UpdateMovementAndCollision(1);
    g_PlayerMoveHeadingAngle = *(ushort *)(g_PlayerEntitySceneObject + 0x132);
    if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle ^ 0x800;
    }
    *(ushort *)(g_PlayerEntitySceneObject + 0xa2) = g_PlayerMoveHeadingAngle;
    CPlayerHero::PlayAdultTarzanAnimation(0x4e);
    return;
  }
  g_PlayerActionState = 7;
  g_PreviousPlayerActionState = value4;
  (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
  return;
}

