#include "tarzan_ghidra_types.hpp"

// Address: 0x0042F650
// Label: CEntities::InitSmashableDebrisShardBurst
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitSmashableDebrisShardBurst(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value5;
  ushort *dataCursor;
  undefined4 value4;
  int value;
  int value2;
  undefined4 *dataCursor2;
  int value3;
  
  value5 = (byte *)(entity->sceneObjects + 0xf);
  *value5 = *value5 | 0x10;
  dataCursor = (ushort *)(entity->sceneObjects + 0xe);
  *dataCursor = *dataCursor & 0x7fff;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 3;
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2003;
  *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 3;
  value = CEntities::CreateEntityAttachment(entry,0x53c,0x10000000);
  if (value != 0) {
    *(undefined4 *)(value + 0x10) = 0x10;
    *(undefined4 *)(value + 0x2c) = 0;
    value2 = CEntities::CreateChildEntitySceneObjectArrayAttachment
                      (entry,1,*(undefined2 *)(value + 0x10));
    if (value2 == 0) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    }
    else {
      *(int *)(value + 0x2c) = value2;
      *(undefined4 *)(value + 0x14) = 4;
      *(undefined4 *)(value + 0x18) = 1;
      *(undefined4 *)(value + 0x1c) = 0;
      *(undefined4 *)(value + 0x40) = 8;
      *(undefined4 *)(value + 0x524) = 0x100;
      value4 = *(undefined4 *)(entity->sceneObjects + 0x18);
      *(undefined4 *)(value + 0x24) = 0x400;
      *(undefined4 *)(value + 0x3c) = 0x400;
      value2 = 0;
      *(undefined4 *)(value + 0x34) = value4;
      *(undefined4 *)(value + 0x20) = 0x5a;
      *(undefined4 *)(value + 0x28) = 0x14;
      *(undefined4 *)(value + 0x38) = 0x40;
      *(undefined4 *)(value + 0x52c) = 0;
      if (0 < *(int *)(value + 0x10)) {
        value3 = 0;
        dataCursor2 = (undefined4 *)(value + 0x50);
        do {
          *dataCursor2 = 0;
          value2 = value2 + 1;
          dataCursor2 = dataCursor2 + 0xd;
          *(undefined2 *)(value3 + 0x12 + *(int *)(value + 0x2c)) = 0;
          value3 = value3 + 0x28;
        } while (value2 < *(int *)(value + 0x10));
        return;
      }
    }
  }
  return;
}

