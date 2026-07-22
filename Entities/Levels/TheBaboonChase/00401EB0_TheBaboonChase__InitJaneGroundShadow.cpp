#include "tarzan_ghidra_types.hpp"

// Address: 0x00401EB0
// Label: TheBaboonChase::InitJaneGroundShadow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::InitJaneGroundShadow(void)

{
  int value;
  int value2;
  
  g_JaneGroundShadowEntitySceneObject = CreateEntityEntitySceneObject((uint *)g_PlayerEntity,5);
  if (g_JaneGroundShadowEntitySceneObject != 0) {
    *(ushort *)(g_JaneGroundShadowEntitySceneObject + 0xe) =
         *(ushort *)(g_JaneGroundShadowEntitySceneObject + 0xe) | 0xc41;
    *(int *)(g_JaneGroundShadowEntitySceneObject + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3a8
    ;
    *(undefined2 *)(g_JaneGroundShadowEntitySceneObject + 0xc) = 0x2010;
    value2 = g_PlayerEntitySceneObject;
    value = g_JaneGroundShadowEntitySceneObject;
    *(undefined4 *)(g_JaneGroundShadowEntitySceneObject + 0x14) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
    *(undefined4 *)(value + 0x18) = *(undefined4 *)(value2 + 0x18);
    *(undefined4 *)(value + 0x1c) = *(undefined4 *)(value2 + 0x1c);
    *(undefined4 *)(g_JaneGroundShadowEntitySceneObject + 0x6c) = 0xffffff9c;
    *(ushort *)(g_JaneGroundShadowEntitySceneObject + 0xe) =
         *(ushort *)(g_JaneGroundShadowEntitySceneObject + 0xe) | 0x441;
    *(undefined4 *)(g_JaneGroundShadowEntitySceneObject + 0x30) = 0x400;
  }
  return;
}

