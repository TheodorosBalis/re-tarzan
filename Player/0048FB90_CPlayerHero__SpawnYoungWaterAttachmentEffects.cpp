#include "tarzan_ghidra_types.hpp"

// Address: 0x0048FB90
// Label: CPlayerHero::SpawnYoungWaterAttachmentEffects
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::SpawnYoungWaterAttachmentEffects(void)

{
  int value;
  undefined4 localState2 [2];
  undefined4 localState;
  
  value = GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x100,localState2);
  if (value != 0) {
    CEntities::SpawnEntityByTypeAtPosition
              (localState2[0],*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7d,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (localState2[0],*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7e,0x11);
  }
  value = GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x200,localState2);
  if (value != 0) {
    CEntities::SpawnEntityByTypeAtPosition
              (localState2[0],*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7d,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (localState2[0],*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7e,0x11);
  }
  value = GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x400,localState2);
  if (value != 0) {
    CEntities::SpawnEntityByTypeAtPosition
              (localState2[0],*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7d,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (localState2[0],*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7e,0x11);
  }
  value = GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x800,localState2);
  if (value != 0) {
    CEntities::SpawnEntityByTypeAtPosition
              (localState2[0],*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7d,0x11);
    CEntities::SpawnEntityByTypeAtPosition
              (localState2[0],*(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),localState,0x7e,0x11);
  }
  return;
}

