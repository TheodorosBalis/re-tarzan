#include "tarzan_ghidra_types.hpp"

// Address: 0x0048C440
// Label: CEntities::ProcessEntityDeath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::ProcessEntityDeath(int entry6,int sceneObject)

{
  undefined **dataCursor;
  ushort value2;
  int entry;
  short shortValue;
  uint value3;
  int entry2;
  int entry3;
  int entry4;
  int entry5;
  undefined4 *dataCursor2;
  short *value;
  undefined4 *dataCursor3;
  undefined2 *dataCursor4;
  bool flagByte;
  
  flagByte = _g_PlayerHeroMode == 2;
  value3 = (uint)*(ushort *)(&g_EntityDeathEffectPrimaryCountTable + sceneObject * 8);
  value2 = *(ushort *)(&g_EntityDeathButterflyCountTable + sceneObject * 8);
  entry2 = CEntities::SpawnEntityByTypeAtPosition
                    (*(undefined4 *)(entry6 + 0x14),*(undefined4 *)(entry6 + 0x18),
                     *(undefined4 *)(entry6 + 0x1c),0x15,0x11);
  if (entry2 != 0) {
    entry = *(int *)(entry2 + 0x38);
    if (entry != 0) {
      *(int *)(entry + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3a8;
      *(undefined2 *)(entry + 0xa6) = 0;
      *(undefined2 *)(entry + 0xe) = 0x421;
      dataCursor2 = (undefined4 *)(entry6 + 0x108);
      dataCursor3 = (undefined4 *)(entry + 0x108);
      for (entry5 = 0xf; entry5 != 0; entry5 = entry5 + -1) {
        *dataCursor3 = *dataCursor2;
        dataCursor2 = dataCursor2 + 1;
        dataCursor3 = dataCursor3 + 1;
      }
      shortValue = *(short *)(entry6 + 0xa2);
      if (flagByte) {
        *(undefined4 *)(entry + 0xb4) = 1;
        *(undefined4 *)(entry + 0xa8) = 0xa00;
        *(undefined4 *)(entry + 0xac) = 0xa00;
        *(undefined4 *)(entry + 0xb0) = 0xa00;
      }
      entry5 = 0;
      if (value2 != 0) {
        do {
          entry3 = CreateEntityEntitySceneObject((uint *)entry2,entry5 + 10);
          if (entry3 != 0) {
            dataCursor = &g_EntityDeathButterflyOffsetListTable + sceneObject * 2;
            *(int *)(entry3 + 0x18) =
                 (int)*(short *)((&g_EntityDeathButterflyOffsetListTable)[sceneObject * 2] +
                                entry5 * 8 + 4) + *(int *)(entry + 0x18);
            *(int *)(entry3 + 0x14) =
                 *(int *)(entry + 0x14) -
                 ((int)(short)(&g_SinCosTable12Bit)[(int)shortValue - 0x400U & 0xfff] *
                  (int)*(short *)(*dataCursor + entry5 * 8 + 2) >> 0xc);
            *(int *)(entry3 + 0x1c) =
                 *(int *)(entry + 0x1c) -
                 ((int)(short)(&g_SinCosTable12Bit)[(int)shortValue & 0xfff] *
                  (int)*(short *)(*dataCursor + entry5 * 8 + 2) >> 0xc);
            *(undefined *)(entry3 + 0x74) = (*dataCursor)[entry5 * 8];
            entry4 = g_WorldEntitySceneObjectArrayBase;
            *(ushort *)(entry3 + 0xe) = *(ushort *)(entry3 + 0xe) | 0x1421;
            *(int *)(entry3 + 0x10) = entry4 + 0x3a8;
            *(undefined2 *)(entry3 + 0xc) = 0x204c;
            entry4 = RandomModulo(0x800);
            *(int *)(entry3 + 0x20) = entry4 + 0x600;
            entry4 = RandomModulo(0x800);
            *(int *)(entry3 + 0x24) = entry4 + 0x600;
            entry4 = RandomModulo(0x800);
            *(int *)(entry3 + 0x28) = entry4 + 0x600;
            *(undefined4 *)(entry3 + 0x30) = 0;
          }
          entry5 = entry5 + 1;
        } while (entry5 < (int)(uint)value2);
      }
      entry5 = CEntities::CreateChildEntitySceneObjectArrayAttachment(entry2,1,value3);
      if (entry5 != 0) {
        value = (short *)(entry5 + 0x10);
        entry5 = CEntities::CreateEntityAttachment(entry2,0xb8,0x10000021);
        if ((entry5 != 0) && (entry3 = 0, value3 != 0)) {
          dataCursor4 = (undefined2 *)(entry5 + 0xc);
          do {
            *(int *)(value + 2) = g_WorldEntitySceneObjectArrayBase + 0x3a8;
            shortValue = RandomModulo(8);
            *value = shortValue + 0x2019;
            value[4] = 0;
            value[5] = 0;
            value[6] = 0;
            value[7] = 0;
            value[8] = 0;
            value[9] = 0;
            entry4 = RandomModulo(0x10);
            dataCursor4[4] = (short)entry4;
            *(int *)(value + 10) =
                 (int)*(short *)(&g_DeathButterflyOffsetVectorTableX + entry4 * 8);
            *(int *)(value + 0xc) =
                 (int)*(short *)(&g_DeathButterflyOffsetVectorTableY + entry4 * 8);
            *(int *)(value + 0xe) =
                 (int)*(short *)(&g_DeathButterflyOffsetVectorTableZ + entry4 * 8);
            value[1] = 0x421;
            value[0x12] = 0;
            value[0x13] = 0;
            *(undefined **)(entry5 + 0xb4) = &g_EntityDeathEffectPrimaryCountTable + sceneObject * 8;
            *dataCursor4 = 0;
            dataCursor4[1] = 0xff80;
            dataCursor4[2] = 0x20;
            dataCursor4[3] = (short)entry3 * 4 + -1;
            value = value + 0x14;
            dataCursor4[6] = 0;
            entry3 = entry3 + 1;
            dataCursor4 = dataCursor4 + 7;
          } while (entry3 < (int)value3);
        }
      }
      PlayAudioById(0xad,(int *)0,(undefined4 *)entry + 0x14);
    }
    if (*(short *)(entry2 + 0x44) != 0) {
      CEntities::ReleaseEntityToFreeList((byte *)entry2);
    }
  }
  return;
}

