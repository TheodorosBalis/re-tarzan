#include "tarzan_ghidra_types.hpp"

// Address: 0x0045FD10
// Label: CPlayerHero::AdvanceAdultTarzanElephantAnimationFrames
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::AdvanceAdultTarzanElephantAnimationFrames(uint arg1)

{
  byte flagByte;
  
  flagByte = *(byte *)(g_PlayerEntitySceneObject + 0x74);
  *(byte *)(g_PlayerEntitySceneObject + 0x74) = flagByte + 1;
  if (flagByte == arg1) {
    *(undefined1 *)(g_PlayerEntitySceneObject + 0x74) = 0;
  }
  if (*(char *)(g_PlayerEntitySceneObject + 0x74) == '\0') {
    PlayAudioById(900,(int *)0,(undefined4 *)g_AdultTarzanElephantEntitySceneObject + 0x14);
  }
  if (*(char *)(g_PlayerEntitySceneObject + 0x74) == '\n') {
    PlayAudioById(0x385,(int *)0,(undefined4 *)g_AdultTarzanElephantEntitySceneObject + 0x14);
  }
  if (arg1 == 0x11) {
    *(undefined2 *)(g_AdultTarzanElephantEntitySceneObject + 0xc) =
         *(undefined2 *)
          (&g_AdultTarzanElephantRidingModelFrameTable +
          (uint)*(byte *)(g_PlayerEntitySceneObject + 0x74) * 4);
    return;
  }
  if (arg1 == 0x36) {
    *(undefined2 *)(g_AdultTarzanElephantEntitySceneObject + 0xc) =
         *(undefined2 *)
          (&g_AdultTarzanElephantMountArrivalModelFrameTable +
          (uint)*(byte *)(g_PlayerEntitySceneObject + 0x74) * 4);
    return;
  }
  if (arg1 == 0x23) {
    *(undefined2 *)(g_AdultTarzanElephantEntitySceneObject + 0xc) =
         *(undefined2 *)
          (&g_AdultTarzanElephantFatalDamageModelFrameTable +
          (uint)*(byte *)(g_PlayerEntitySceneObject + 0x74) * 4);
  }
  return;
}

