#include "tarzan_ghidra_types.hpp"

// Address: 0x00457E30
// Label: Stampede::InitPalmTree
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::InitPalmTree(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  uint value4;
  uint value5;
  undefined4 *dataCursor;
  uint *dataCursor2;
  int *localState4;
  uint localState3;
  uint localState2;
  int localState;
  
  value = entry;
  value5 = 0;
  *(undefined2 *)(entity->sceneObjects + 0xa2) = 0x400;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x30c0;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x1a;
  *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
  value2 = CEntities::CreateEntityAttachment(entry,0x2c4,0x10000000);
  if (value2 != 0) {
    localState = 0;
    if ((entity->descriptor != 0) &&
       (localState = *(int *)(entity->descriptor + 0x10), *(int *)(localState + 4) == 1)) {
      *(undefined2 *)(entity->sceneObjects + 0xa2) = 0xc00;
    }
    *(undefined4 *)(value2 + 0xc) = 7;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_00503540);
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2055;
    *(undefined4 *)(value2 + 700) = 0;
    *(undefined4 *)(value2 + 0x2c0) = 0;
    value3 = CreateEntityEntitySceneObject((uint *)entry,3);
    if (value3 != 0) {
      *(int *)(value2 + 0x10) = value3;
      *(undefined2 *)(value3 + 0xa6) = 0;
      *(undefined4 *)(value3 + 0xb4) = 1;
    }
    localState4 = (int *)(value2 + 0x34);
    dataCursor = (undefined4 *)(value2 + 0x28c);
    entry = 0;
    localState2 = 0;
    localState3 = 0xffffff80;
    dataCursor2 = (uint *)(value2 + 0x8c);
    do {
      value2 = CreateEntityEntitySceneObject((uint *)value,entry + 4);
      if (value2 != 0) {
        *localState4 = value2;
        *(undefined2 *)(value2 + 0xa6) = 0;
        *(int *)(value2 + 0x14) =
             ((short)(&g_SinCosTable12Bit)[value5 - 0x400 & 0xfff] * 200 >> 0xc) +
             *(int *)(*(int *)(value + 0x38) + 0x14);
        *(int *)(value2 + 0x18) = *(int *)(*(int *)(value + 0x38) + 0x18) + -0x600;
        *(int *)(value2 + 0x1c) =
             ((short)(&g_SinCosTable12Bit)[value5 & 0xfff] * 200 >> 0xc) +
             *(int *)(*(int *)(value + 0x38) + 0x1c);
        value3 = g_WorldEntitySceneObjectArrayBase + 0x30c0;
        *(undefined2 *)(value2 + 0xc) = 0x2040;
        *(int *)(value2 + 0x10) = value3;
        value2 = RandomModulo(0x80);
        dataCursor[1] = value2 + 0x100;
        *dataCursor = 0;
        if (*(int *)(localState + 4) == 0) {
          value2 = RandomModulo(4);
          value4 = (uint)((value2 + 0x1d) * (int)g_LevelEntityInitScratch_Field1788) >> 0xc;
        }
        else {
          value2 = RandomModulo(4);
          value4 = -((uint)((value2 + 0x1d) * (int)g_LevelEntityInitScratch_Field1788) >> 0xc);
        }
        *dataCursor2 = value4;
        dataCursor2[1] = -(((int)(short)(&g_SinCosTable12Bit)[localState3 & 0xfff] << 4) >> 0xc);
        dataCursor2[-0xd] = 5;
        dataCursor2[-0xc] = 0;
        dataCursor2[-5] = 2;
        dataCursor2[-10] = localState2;
        dataCursor2[-7] = *(uint *)(*(int *)(value + 0x38) + 0x18);
      }
      localState4 = localState4 + 1;
      localState3 = localState3 + 0x40;
      entry = entry + 1;
      value5 = value5 + 0x2aa;
      dataCursor = dataCursor + 2;
      dataCursor2 = dataCursor2 + 0x18;
      localState2 = localState2 + 0xc;
    } while ((int)localState3 < 0x100);
  }
  return;
}

