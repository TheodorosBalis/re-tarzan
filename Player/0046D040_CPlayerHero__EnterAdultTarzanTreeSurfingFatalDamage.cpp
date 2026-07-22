#include "tarzan_ghidra_types.hpp"

// Address: 0x0046D040
// Label: CPlayerHero::EnterAdultTarzanTreeSurfingFatalDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanTreeSurfingFatalDamage(void)

{
  int value;
  undefined4 value4;
  int value2;
  int value3;
  
  g_PlayerSurfaceMotionSpeed = 0x40;
  value3 = CEntities::SpawnEntityByTypeAtPosition
                    (*(undefined4 *)(g_PlayerEntitySceneObjectData + 4),
                     *(undefined4 *)(g_PlayerEntitySceneObjectData + 6),
                     *(undefined4 *)(g_PlayerEntitySceneObjectData + 8),0x2e,0x11);
  value = *(int *)(value3 + 0x38);
  if (value != 0) {
    *(undefined4 *)(value + 0x14) = *(undefined4 *)(g_PlayerEntitySceneObjectData + 4);
    *(undefined4 *)(value + 0x18) = *(undefined4 *)(g_PlayerEntitySceneObjectData + 6);
    value4 = *(undefined4 *)(g_PlayerEntitySceneObjectData + 8);
    *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0x7fff;
    *(undefined4 *)(value + 0x1c) = value4;
    *(int *)(value + 0x10) = g_WorldEntitySceneObjectArrayBase + 0xd0;
    *(undefined2 *)(value + 0xc) = *g_PlayerEntitySceneObjectData;
    *(undefined2 *)(value + 0xa0) = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0);
    *(undefined2 *)(value + 0xa2) = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2);
    *(undefined2 *)(value + 0xa4) = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa4);
    *(undefined2 *)(value + 0xa6) = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa6);
    value2 = g_PlayerEntitySceneObject;
    *(undefined4 *)(value + 0x10c) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
    *(undefined4 *)(value + 0x110) = *(undefined4 *)(value2 + 0x110);
    *(undefined4 *)(value + 0x110) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
    *(undefined4 *)(value + 0x10c) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
    *(undefined4 *)(value + 0x114) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x114);
    *(undefined2 *)(value + 0x142) = *(undefined2 *)(g_PlayerEntitySceneObject + 0x142);
    value2 = g_PlayerEntitySceneObject;
    *(undefined4 *)(value + 0x14) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
    *(undefined4 *)(value + 0x18) = *(undefined4 *)(value2 + 0x18);
    *(undefined4 *)(value + 0x1c) = *(undefined4 *)(value2 + 0x1c);
    value2 = g_PlayerEntitySceneObject;
    *(undefined4 *)(value + 0x3c) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x3c);
    *(undefined4 *)(value + 0x40) = *(undefined4 *)(value2 + 0x40);
    *(undefined4 *)(value + 0x44) = *(undefined4 *)(value2 + 0x44);
    value2 = g_PlayerEntitySceneObject;
    *(undefined4 *)(value + 0x48) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x48);
    *(undefined4 *)(value + 0x4c) = *(undefined4 *)(value2 + 0x4c);
    *(undefined4 *)(value + 0x50) = *(undefined4 *)(value2 + 0x50);
    value2 = g_PlayerEntitySceneObject;
    *(undefined4 *)(value + 0x54) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x54);
    *(undefined4 *)(value + 0x58) = *(undefined4 *)(value2 + 0x58);
    *(undefined4 *)(value + 0x5c) = *(undefined4 *)(value2 + 0x5c);
    g_ActiveCameraAnchorEntry = value3;
  }
  CPlayerHero::BeginScriptedMotionSequence(0,0,0,0,0,0x1e);
  CPlayerHero::PlayAdultTarzanAnimation(0x24);
  QueuePlayerDamageEvent(0,0x200);
  g_PlayerSequenceDelayTicks = 0x1e;
  return;
}

