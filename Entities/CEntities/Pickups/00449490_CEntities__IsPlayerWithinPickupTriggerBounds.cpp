#include "tarzan_ghidra_types.hpp"

// Address: 0x00449490
// Label: CEntities::IsPlayerWithinPickupTriggerBounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
CEntities::IsPlayerWithinPickupTriggerBounds(int entry,int sceneObject,int attachment,int flags)

{
  char resultFlag;
  uint value4;
  uint value5;
  int value;
  int value2;
  int value3;
  int localState3;
  int localState2;
  undefined4 localState;
  
  value4 = g_PlayerSpecialAttachmentPosX - *(int *)(entry + 0x14);
  value5 = (int)value4 >> 0x1f;
  value2 = (value4 ^ value5) - value5;
  value4 = ((g_PlayerSpecialAttachmentPosY - *(int *)(entry + 0x40)) - *(int *)(entry + 0x18)) +
          0x70;
  value5 = (int)value4 >> 0x1f;
  value = (value4 ^ value5) - value5;
  value4 = g_PlayerSpecialAttachmentPosZ - *(int *)(entry + 0x1c);
  value5 = (int)value4 >> 0x1f;
  value3 = (value4 ^ value5) - value5;
  if (attachment != 0) {
    attachment = attachment + 0xe0;
  }
  if ((g_PlayerSpecialAttachmentFlags & 0x800) == 0) {
    attachment = attachment / 2;
  }
  if (flags == 0) {
    if ((((*(int *)(entry + 0x108) == 1) && (*(int *)(g_PlayerEntitySceneObject + 0x108) == 1)) &&
        (*(int *)(g_PlayerEntitySceneObject + 0x110) == *(int *)(entry + 0x110))) &&
       (value4 = *(int *)(g_PlayerEntitySceneObject + 0x10c) - *(int *)(entry + 0x10c),
       value5 = (int)value4 >> 0x1f, (int)((value4 ^ value5) - value5) <= sceneObject)) {
      if (attachment == 0) {
        return 1;
      }
      if (value <= attachment) {
        return 1;
      }
    }
    if (g_PlayerCurrentCollisionMode == 5) {
      localState3 = *(int *)(entry + 0x14);
      localState = *(undefined4 *)(entry + 0x1c);
      localState2 = *(int *)(entry + 0x18) + -0x50;
      resultFlag = CEntities::IsWorldPointInsideEntitySceneObjectBounds
                        (g_PlayerEntitySceneObject,&localState3);
      if (resultFlag != '\0') {
        return 1;
      }
    }
    else if (value3 * value3 + value2 * value2 < sceneObject * sceneObject) {
      if (attachment == 0) {
        if (value < 0x801) {
          return 1;
        }
      }
      else if (value <= attachment) {
        return 1;
      }
    }
  }
  else if (flags == 1) {
    if (value2 <= sceneObject) {
      return 1;
    }
  }
  else if (flags == 2) {
    if (value <= sceneObject) {
      return 1;
    }
  }
  else if ((flags == 3) && (value3 <= sceneObject)) {
    return 1;
  }
  return 0;
}

