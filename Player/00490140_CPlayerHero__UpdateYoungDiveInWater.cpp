#include "tarzan_ghidra_types.hpp"

// Address: 0x00490140
// Label: CPlayerHero::UpdateYoungDiveInWater
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungDiveInWater(void)

{
  int value;
  undefined4 localState3;
  uint localState2;
  undefined4 localState;
  
  if (g_PlayerAirMovePitchAngle != 0) {
    localState = 0xfffffe00;
    localState2 = (uint)g_PlayerAirMovePitchAngle;
    localState3 = 0x49015b;
    value = GetWrappedSignedAngleDelta12Bit();
    if ((value >> 4 ^ value >> 0x1f) - (value >> 0x1f) < 2) {
      g_PlayerAirMovePitchAngle = 0;
    }
    else {
      g_PlayerAirMovePitchAngle = g_PlayerAirMovePitchAngle + (short)(value >> 4);
    }
  }
  localState = 1;
  localState2 = 0x490188;
  CPlayerHero::UpdateMovementAndCollision();
  localState = 0x490190;
  CPlayerHero::AdvanceAnimationScript();
  value = GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x100,&localState3);
  if (value != 0) {
    CEntities::SpawnEntityByTypeAtPosition
              (localState3,*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7d,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (localState3,*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7e,0x11);
  }
  value = GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x200,&localState3);
  if (value != 0) {
    CEntities::SpawnEntityByTypeAtPosition
              (localState3,*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7d,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (localState3,*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7e,0x11);
  }
  value = GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x400,&localState3);
  if (value != 0) {
    CEntities::SpawnEntityByTypeAtPosition
              (localState3,*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7d,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (localState3,*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7e,0x11);
  }
  value = GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x800,&localState3);
  if (value != 0) {
    CEntities::SpawnEntityByTypeAtPosition
              (localState3,*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7d,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (localState3,*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7e,0x11);
  }
  return;
}

