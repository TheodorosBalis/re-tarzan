#include "tarzan_ghidra_types.hpp"

// Address: 0x004AD650
// Label: BuildBitmapCellEntityList
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BuildBitmapCellEntityList(uint arg1,undefined4 *arg2,int arg3,int arg4)

{
  short *value;
  int *intCursor;
  undefined2 *dataCursor2;
  char *stringCursor;
  undefined2 value2;
  undefined4 *dataCursor3;
  uint *dataCursor4;
  byte flagByte;
  uint value3;
  ushort *dataCursor;
  uint localState;
  ushort *localState4;
  ushort *localState3;
  int localState2;
  
  dataCursor3 = arg2;
  if (arg2 != (undefined4 *)0x0) {
    *arg2 = 0;
    if (*(ushort *)(arg2 + 2) != 0) {
      dataCursor4 = (uint *)AllocZeroedModelHeapBlock
                                 ((uint)*(ushort *)(arg2 + 2) * 0x1c,&DAT_00518dcc);
      value = (short *)(arg2 + 2);
      *arg2 = dataCursor4;
      localState4 = (ushort *)(arg2[5] + 0x14 + (int)arg2);
      intCursor = arg2 + 6;
      arg2 = (undefined4 *)0x0;
      localState3 = (ushort *)(*intCursor + 0x18 + (int)dataCursor3);
      localState = 0;
      dataCursor = (ushort *)(dataCursor3[7] + 0x1c + (int)dataCursor3);
      localState2 = 0;
      if (*value != 0) {
        do {
          localState = localState - 1;
          if ((int)localState < 0) {
            arg2 = (undefined4 *)(uint)*localState3;
            localState = *localState3 >> 9 & 0x3f;
            localState3 = localState3 + 1;
          }
          dataCursor2 = (undefined2 *)(*(int *)(arg1 + 4) + ((uint)arg2 & 0x1ff) * 0x26);
          value3 = arg1;
          if ((*(int *)(dataCursor2 + 0xb) == 0) && (*(char *)(dataCursor2 + 10) == '\0')) {
            value3 = 0;
          }
          dataCursor4[5] = value3;
          dataCursor4[6] = (uint)arg2 & 0x1ff;
          *(ushort *)((int)dataCursor4 + 0x12) =
               (byte)(*(byte *)(dataCursor2 + 3) ^ (byte)*(ushort *)((int)dataCursor4 + 0x12)) & 0xf ^
               *(ushort *)((int)dataCursor4 + 0x12);
          value2 = *dataCursor2;
          *(undefined2 *)(dataCursor4 + 4) = value2;
          *(undefined2 *)((int)dataCursor4 + 0xe) = value2;
          *(undefined2 *)(dataCursor4 + 3) = value2;
          stringCursor = (char *)(arg4 + (uint)*localState4 * 2);
          *(byte *)((int)dataCursor4 + 0xd) = *(byte *)((int)dataCursor4 + 0xd) + *stringCursor;
          *(byte *)(dataCursor4 + 3) = (byte)dataCursor4[3] + stringCursor[1];
          *(byte *)((int)dataCursor4 + 0xf) = *(byte *)((int)dataCursor4 + 0xf) + stringCursor[2];
          *(byte *)((int)dataCursor4 + 0xe) = *(byte *)((int)dataCursor4 + 0xe) + stringCursor[3];
          *(byte *)((int)dataCursor4 + 0x11) = *(byte *)((int)dataCursor4 + 0x11) + stringCursor[4];
          *(byte *)(dataCursor4 + 4) = (byte)dataCursor4[4] + stringCursor[5];
          value3 = *(uint *)(arg3 + (*dataCursor & 0x7fff) * 4);
          *dataCursor4 = value3 & 0xff00 | value3 >> 0x10 & 0xff | (value3 & 0xff) << 0x10 | 0xff000000;
          value3 = *(uint *)(arg3 + 4 + (*dataCursor & 0x7fff) * 4);
          dataCursor4[1] = value3 & 0xff00 | value3 >> 0x10 & 0xff | (value3 & 0xff) << 0x10 | 0xff000000;
          value3 = *(uint *)(arg3 + 8 + (*dataCursor & 0x7fff) * 4);
          _g_TextureColorConvertScratch =
               value3 & 0xff00 | value3 >> 0x10 & 0xff | (value3 & 0xff) << 0x10;
          dataCursor4[2] = _g_TextureColorConvertScratch | 0xff000000;
          *(ushort *)((int)dataCursor4 + 0x12) =
               (ushort)((*dataCursor & 0x8000) >> 0xb) | *(ushort *)((int)dataCursor4 + 0x12) & 0xffef;
          if ((uint)*(byte *)((int)dataCursor4 + 2) * 2 < 0xff) {
            flagByte = *(byte *)((int)dataCursor4 + 2) << 1;
          }
          else {
            flagByte = 0xff;
          }
          *(byte *)((int)dataCursor4 + 2) = flagByte;
          if ((uint)*(byte *)((int)dataCursor4 + 1) * 2 < 0xff) {
            flagByte = *(byte *)((int)dataCursor4 + 1) << 1;
          }
          else {
            flagByte = 0xff;
          }
          *(byte *)((int)dataCursor4 + 1) = flagByte;
          if ((uint)(byte)*dataCursor4 * 2 < 0xff) {
            flagByte = (byte)*dataCursor4 << 1;
          }
          else {
            flagByte = 0xff;
          }
          *(byte *)dataCursor4 = flagByte;
          if ((uint)*(byte *)((int)dataCursor4 + 6) * 2 < 0xff) {
            flagByte = *(byte *)((int)dataCursor4 + 6) << 1;
          }
          else {
            flagByte = 0xff;
          }
          *(byte *)((int)dataCursor4 + 6) = flagByte;
          if ((uint)*(byte *)((int)dataCursor4 + 5) * 2 < 0xff) {
            flagByte = *(byte *)((int)dataCursor4 + 5) << 1;
          }
          else {
            flagByte = 0xff;
          }
          *(byte *)((int)dataCursor4 + 5) = flagByte;
          if ((uint)(byte)dataCursor4[1] * 2 < 0xff) {
            flagByte = (byte)dataCursor4[1] << 1;
          }
          else {
            flagByte = 0xff;
          }
          *(byte *)(dataCursor4 + 1) = flagByte;
          if ((uint)*(byte *)((int)dataCursor4 + 10) * 2 < 0xff) {
            flagByte = *(byte *)((int)dataCursor4 + 10) << 1;
          }
          else {
            flagByte = 0xff;
          }
          *(byte *)((int)dataCursor4 + 10) = flagByte;
          if ((uint)*(byte *)((int)dataCursor4 + 9) * 2 < 0xff) {
            flagByte = *(byte *)((int)dataCursor4 + 9) << 1;
          }
          else {
            flagByte = 0xff;
          }
          *(byte *)((int)dataCursor4 + 9) = flagByte;
          if ((uint)(byte)dataCursor4[2] * 2 < 0xff) {
            flagByte = (byte)dataCursor4[2] << 1;
          }
          else {
            flagByte = 0xff;
          }
          *(byte *)(dataCursor4 + 2) = flagByte;
          if (((uint)arg2 & 0x8000) != 0) {
            *(byte *)((int)dataCursor4 + 0x12) = *(byte *)((int)dataCursor4 + 0x12) | 0xf;
            *(undefined2 *)(dataCursor4 + 4) = 0x1fd;
            ((byte *)((int)dataCursor4 + 0xe))[0] = 0xfd;
            ((byte *)((int)dataCursor4 + 0xe))[1] = 1;
            *(undefined2 *)(dataCursor4 + 3) = 0x1fd;
          }
          localState4 = localState4 + 1;
          localState2 = localState2 + 1;
          dataCursor = dataCursor + 1;
          dataCursor4 = dataCursor4 + 7;
        } while (localState2 < (int)(uint)*(ushort *)(dataCursor3 + 2));
      }
    }
  }
  return;
}

