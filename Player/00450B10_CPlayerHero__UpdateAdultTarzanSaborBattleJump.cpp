#include "tarzan_ghidra_types.hpp"

// Address: 0x00450B10
// Label: CPlayerHero::UpdateAdultTarzanSaborBattleJump
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSaborBattleJump(void)

{
  int value;
  
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 2) {
    *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
    *(ushort *)(g_PlayerEntitySceneObject + 0xa2) =
         *(ushort *)(g_PlayerEntitySceneObject + 0xa2) ^ 0x800;
    g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle ^ 0x800;
  }
  CPlayerHero::UpdateAdultTarzanSaborBattleFacing();
  CPlayerHero::UpdateAdultTarzanSaborBattleLateralSpeed();
  if (*(int *)(g_PlayerMotionState + 0x10) != 0) {
    CPlayerHero::MoveAdultTarzanInSaborBattle(*(int *)(g_PlayerMotionState + 0x10));
  }
  if (*(char *)(g_PlayerMotionState + 0xd) == '\0') {
    *(int *)(g_PlayerMotionState + 0x20) =
         *(int *)(g_PlayerMotionState + 0x20) + *(int *)(g_PlayerMotionState + 0x24);
    if (*(int *)(g_PlayerMotionState + 0x2c) < *(int *)(g_PlayerMotionState + 0x20)) {
      *(int *)(g_PlayerMotionState + 0x20) = *(int *)(g_PlayerMotionState + 0x2c);
    }
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + *(int *)(g_PlayerMotionState + 0x20);
  }
  else {
    value = *(int *)(g_PlayerMotionState + 0x28);
    if (((g_PlayerInputHeldMask & 0x200000) == 0) && (0x40 < *(int *)(g_PlayerMotionState + 0x20)))
    {
      value = 0x28;
    }
    value = *(int *)(g_PlayerMotionState + 0x20) - value;
    *(int *)(g_PlayerMotionState + 0x20) = value;
    if (value < 0) {
      *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
      *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
      *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x70;
      *(undefined4 *)(g_PlayerMotionState + 0x24) = 5;
    }
    else {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
           *(int *)(g_PlayerEntitySceneObjectData + 0xc) - *(int *)(g_PlayerMotionState + 0x20);
    }
  }
  if (0 < *(int *)(g_PlayerMotionState + 0x20)) {
    if (g_SaborBattleGroundY <= *(int *)(g_PlayerEntitySceneObjectData + 0xc)) {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) = g_SaborBattleGroundY;
      CPlayerHero::SetAdultTarzanActionState(0x38);
      PlayAudioById(0x8b,(int *)0,(undefined4 *)0);
    }
  }
  return;
}

