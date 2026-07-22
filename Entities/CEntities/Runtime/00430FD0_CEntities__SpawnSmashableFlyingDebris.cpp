#include "tarzan_ghidra_types.hpp"

// Address: 0x00430FD0
// Label: CEntities::SpawnSmashableFlyingDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
CEntities::SpawnSmashableFlyingDebris
          (undefined4 entry,undefined4 sceneObject,undefined4 attachment,int flags,undefined2 arg5)

{
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value2 = CEntities::SpawnEntityByTypeAtPosition(entry,sceneObject,attachment,0x1c,0x11);
  if (value2 != 0) {
    CEntities::InitSmashableFlyingDebris(value2);
    value = *(int *)(value2 + 0x38);
    if (value != 0) {
      value3 = g_CurrentWorldSceneContext;
      if (flags != 0x8000) {
        value3 = g_WorldEntitySceneObjectArrayBase + flags * 0x68;
      }
      *(int *)(value + 0x10) = value3;
      *(undefined2 *)(value + 0xc) = arg5;
      value3 = CEntities::FindEntityAttachmentByFlags(value2,0x10000000);
      if (value3 != 0) {
        value5 = g_CameraUpdateEyePoint - *(int *)(value + 0x14);
        value4 = g_CameraUpdateEyePointZ - *(int *)(value + 0x1c);
        value2 = g_CameraUpdateEyePointY - *(int *)(value + 0x18);
        *(int *)(value3 + 0xc) = g_CameraUpdateEyePoint;
        *(int *)(value3 + 0x10) = g_CameraUpdateEyePointY;
        *(int *)(value3 + 0x14) = g_CameraUpdateEyePointZ;
        *(int *)(value3 + 0x18) = *(int *)(value + 0x14) + (value5 - value5 / 2);
        *(int *)(value3 + 0x1c) = *(int *)(value + 0x18) + (value2 - value2 / 2);
        *(int *)(value3 + 0x20) = *(int *)(value + 0x1c) + (value4 - value4 / 2);
        *(undefined2 *)(value3 + 0x78) = 0xc0;
        *(undefined2 *)(value3 + 0x7a) = 0x40;
        return 0;
      }
    }
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(value2);
  }
  return 1;
}

