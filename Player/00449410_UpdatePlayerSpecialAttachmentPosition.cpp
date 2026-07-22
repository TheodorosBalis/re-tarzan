#include "tarzan_ghidra_types.hpp"

// Address: 0x00449410
// Label: UpdatePlayerSpecialAttachmentPosition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdatePlayerSpecialAttachmentPosition(void)

{
  if (g_PlayerSpecialAttachmentEntry != 0) {
    TransformSceneAttachmentToWorld
              (g_PlayerSpecialAttachmentEntry,g_PlayerEntitySceneObject,
               &g_PlayerSpecialAttachmentPosX);
    g_PlayerSpecialAttachmentFlags = *(undefined4 *)(g_PlayerSpecialAttachmentEntry + 0xc);
    return;
  }
  g_PlayerSpecialAttachmentPosX = *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
  g_PlayerSpecialAttachmentPosZ = *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c);
  g_PlayerSpecialAttachmentFlags = 0;
  g_PlayerSpecialAttachmentPosY =
       *(int *)(g_PlayerEntitySceneObject + 0x18) -
       (int)*(short *)(g_PlayerEntitySceneObject + 0x142) / 2;
  return;
}

