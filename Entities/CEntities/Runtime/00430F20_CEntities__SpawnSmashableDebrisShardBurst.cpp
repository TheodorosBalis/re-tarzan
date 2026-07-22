#include "tarzan_ghidra_types.hpp"

// Address: 0x00430F20
// Label: CEntities::SpawnSmashableDebrisShardBurst
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
CEntities::SpawnSmashableDebrisShardBurst
          (undefined4 entry,int sceneObject,undefined4 attachment,int flags,undefined2 arg5,
          undefined4 arg6,undefined4 arg7,int arg8)

{
  int value;
  int value2;
  int value3;
  
  value = CEntities::SpawnEntityByTypeAtPosition(entry,sceneObject,attachment,0x1b,0x11);
  if (value != 0) {
    CEntities::InitSmashableDebrisShardBurst(value);
    value2 = *(int *)(value + 0x38);
    if (value2 != 0) {
      value3 = g_CurrentWorldSceneContext;
      if (flags != 0x8000) {
        value3 = g_WorldEntitySceneObjectArrayBase + flags * 0x68;
      }
      *(int *)(value2 + 0x10) = value3;
      *(undefined2 *)(value2 + 0xc) = arg5;
      value2 = CEntities::FindEntityAttachmentByFlags(value,0x10000000);
      if (value2 != 0) {
        *(undefined4 *)(value2 + 0x14) = arg6;
        *(undefined4 *)(value2 + 0x40) = arg7;
        *(int *)(value2 + 0x34) = sceneObject + arg8;
        return 0;
      }
    }
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(value);
  }
  return 1;
}

