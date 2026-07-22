#include "tarzan_ghidra_types.hpp"

// Address: 0x0048C740
// Label: CEntities::UpdateButterfliesOnDeath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateButterfliesOnDeath(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  bool flagByte;
  short shortValue;
  ushort value3;
  int value2;
  uint value4;
  uint value5;
  ushort *dataCursor;
  ushort *dataCursor2;
  
  flagByte = false;
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + 0x9f;
    if (*(int *)(value + 0x38) != 0) {
      dataCursor2 = (ushort *)(*(int *)(value + 0x38) + 0x10);
      value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000021);
      if (value2 != 0) {
        dataCursor = (ushort *)(value2 + 0xc);
        for (value5 = (uint)**(ushort **)(value2 + 0xb4); value5 != 0; value5 = value5 - 1) {
          if (dataCursor[6] == 0) {
            dataCursor[3] = dataCursor[3] - 1;
            if ((short)dataCursor[3] < 0) {
              shortValue = RandomModulo(0x30);
              value3 = shortValue + 0x40;
              dataCursor[2] = value3;
              value4 = ((EntitySceneObject *)value)->yaw - 0x400 & 0xfff;
              *dataCursor = (ushort)value4;
              *(int *)(dataCursor2 + 4) =
                   (int)(short)(&g_SinCosTable12Bit)[value4 - 0x400 & 0xfff] * (int)(short)value3 >>
                   0xc;
              *(int *)(dataCursor2 + 8) =
                   (int)(short)(&g_SinCosTable12Bit)[value4] * (int)(short)value3 >> 0xc;
              value2 = RandomModulo(0x80);
              *(byte *)((int)dataCursor2 + 3) = *(byte *)((int)dataCursor2 + 3) | 0x80;
              *(int *)(dataCursor2 + 6) = -0x80 - value2;
              dataCursor[6] = 1;
              dataCursor[3] = 0x3c;
              dataCursor[5] = 0x1000;
            }
LAB_0048c93b:
            flagByte = true;
          }
          else if (dataCursor[6] == 1) {
            dataCursor[3] = dataCursor[3] - 1;
            if ((short)dataCursor[3] < 0) {
              dataCursor[6] = 2;
              dataCursor2[1] = dataCursor2[1] & 0x7fff;
              goto LAB_0048c93b;
            }
            *dataCursor2 = *dataCursor2 + 1;
            if (0x2020 < *dataCursor2) {
              *dataCursor2 = 0x2019;
            }
            value3 = *dataCursor;
            value2 = (short)dataCursor[2] + 5;
            *(int *)(dataCursor2 + 4) =
                 (short)(&g_SinCosTable12Bit)[value3 - 0x400 & 0xfff] * value2 >> 0xc;
            *(int *)(dataCursor2 + 8) = (short)(&g_SinCosTable12Bit)[value3 & 0xfff] * value2 >> 0xc;
            *(int *)(dataCursor2 + 6) = *(int *)(dataCursor2 + 6) + -0xf;
            dataCursor[2] = (ushort)value2;
            value2 = dataCursor[5] - 0x44;
            if (value2 < 0) {
              value2 = 1;
LAB_0048c846:
              value4 = (uint)dataCursor[4];
              *(int *)(dataCursor2 + 10) =
                   (int)(*(short *)(&g_DeathButterflyOffsetVectorTableX + value4 * 8) * value2 +
                        (*(short *)(&g_DeathButterflyOffsetVectorTableX + value4 * 8) * value2 >> 0x1f
                        & 0xfffU)) >> 0xc;
              *(int *)(dataCursor2 + 0xc) =
                   (int)(*(short *)(&g_DeathButterflyOffsetVectorTableY + value4 * 8) * value2 +
                        (*(short *)(&g_DeathButterflyOffsetVectorTableY + value4 * 8) * value2 >> 0x1f
                        & 0xfffU)) >> 0xc;
              *(int *)(dataCursor2 + 0xe) =
                   (int)(*(short *)(&g_DeathButterflyOffsetVectorTableZ + value4 * 8) * value2 +
                        (*(short *)(&g_DeathButterflyOffsetVectorTableZ + value4 * 8) * value2 >> 0x1f
                        & 0xfffU)) >> 0xc;
            }
            else if (value2 != 0) goto LAB_0048c846;
            dataCursor[5] = (ushort)value2;
            goto LAB_0048c93b;
          }
          dataCursor2 = dataCursor2 + 0x14;
          dataCursor = dataCursor + 7;
        }
        for (value = ((EntitySceneObject *)value)->next; value != 0; value = ((EntitySceneObject *)value)->next) {
          if (*(char *)(value + 0x74) == '\0') {
            if ((*(byte *)(value + 0xf) & 0x80) != 0) {
              *(short *)(value + 0xc) = *(short *)(value + 0xc) + 1;
              if (0x205b < *(ushort *)(value + 0xc)) {
                *(undefined2 *)(value + 0xe) = 0;
              }
              goto LAB_0048c97f;
            }
          }
          else {
            *(char *)(value + 0x74) = *(char *)(value + 0x74) + -1;
LAB_0048c97f:
            flagByte = true;
          }
        }
        if (flagByte) {
          return;
        }
      }
    }
  }
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

