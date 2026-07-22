#include "tarzan_ghidra_types.hpp"

// Address: 0x00474D10
// Label: KerchakChase::InitBreakableTreeBarrier
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::InitBreakableTreeBarrier(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value7;
  int value;
  undefined4 value6;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value2 = CEntities::CreateEntityAttachment(entry,0x220,0x10000000);
  value5 = 0;
  if (value2 != 0) {
    *(undefined4 *)(entity->sceneObjects + 0x10) = g_CurrentWorldSceneContext;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x5021;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    value7 = (byte *)(entity->sceneObjects + 0xf);
    *value7 = *value7 | 8;
    *(undefined4 *)(value2 + 0xc) = 0;
    *(undefined4 *)(value2 + 0x70) = 0;
    *(undefined4 *)(value2 + 0x74) = 0;
    *(undefined4 *)(value2 + 0x3c) = 3;
    *(undefined4 *)(value2 + 0x40) = 0;
    *(undefined4 *)(value2 + 0x5c) = 1;
    *(undefined4 *)(value2 + 0x48) = 0x18;
    value6 = *(undefined4 *)(entity->sceneObjects + 0x18);
    *(undefined4 *)(value2 + 0x10) = 0xffffffc0;
    *(undefined4 *)(value2 + 0x54) = value6;
    *(undefined4 *)(value2 + 0x1c) = 0;
    *(undefined4 *)(value2 + 0x14) = 2;
    *(undefined4 *)(value2 + 0x18) = 2;
    *(undefined2 *)(entity->sceneObjects + 0xa2) = 0x100;
    if ((entity->descriptor != 0) &&
       (*(int *)(*(int *)(entity->descriptor + 0x10) + 4) == 1)) {
      *(undefined2 *)(entity->sceneObjects + 0xa2) = 0xf700;
      *(undefined2 *)(entity->sceneObjects + 0xc) = 0x5021;
    }
    *(undefined4 *)(entity->sceneObjects + 0x6c) = 0xffffff80;
    do {
      value3 = CreateEntityEntitySceneObject((uint *)entry,value5 + 4);
      if (value3 != 0) {
        *(int *)(value2 + 0x90 + value5 * 4) = value3;
        *(undefined4 *)(value2 + 0x20 + value5 * 4) = 0;
        *(ushort *)(value3 + 0xe) = *(ushort *)(value3 + 0xe) & 0x7fff;
        *(undefined4 *)(value3 + 0x10) = g_CurrentWorldSceneContext;
        if (value5 == 0) {
          *(undefined2 *)(value3 + 0xc) = 0x2000;
        }
        else if (value5 == 1) {
          *(undefined2 *)(value3 + 0xc) = 0x2001;
        }
        else if (value5 == 2) {
          *(undefined2 *)(value3 + 0xc) = 0x2002;
        }
        else if (value5 == 3) {
          *(undefined2 *)(value3 + 0xc) = 0x2003;
        }
        *(undefined4 *)(value3 + 0x6c) = 0xffffff80;
        value = value5 * 0x60 + value2;
        *(undefined4 *)(value + 0xe0) = 0;
        *(undefined4 *)(value + 0xe4) = 0;
        *(undefined4 *)(value + 0xac) = 3;
        *(undefined4 *)(value + 0xb0) = 0;
        *(undefined4 *)(value + 0xcc) = 1;
        value4 = RandomModulo(5);
        *(int *)(value + 0xb8) = value4 + 0x18;
        *(undefined4 *)(value + 0xc4) = *(undefined4 *)(entity->sceneObjects + 0x18);
        *(undefined2 *)(value3 + 0xa6) = 0;
      }
      value5 = value5 + 1;
    } while (value5 < 4);
  }
  return;
}

