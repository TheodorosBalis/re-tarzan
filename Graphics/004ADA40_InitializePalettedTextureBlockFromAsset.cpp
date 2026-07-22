#include "tarzan_ghidra_types.hpp"

// Address: 0x004ADA40
// Label: InitializePalettedTextureBlockFromAsset
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitializePalettedTextureBlockFromAsset(uint *graphicsObject,uint source2)

{
  ushort value4;
  undefined4 value5;
  int *intCursor2;
  int value2;
  uint value6;
  undefined1 *dataCursor4;
  uint value7;
  undefined4 *dataCursor5;
  int value3;
  ushort *dataCursor;
  int *intCursor;
  undefined4 *dataCursor2;
  uint *dataCursor3;
  int value;
  uint localState2;
  undefined4 localState [256];
  
  if (source2 != 0) {
    dataCursor3 = graphicsObject;
    for (value3 = 7; value3 != 0; value3 = value3 + -1) {
      *dataCursor3 = 0;
      dataCursor3 = dataCursor3 + 1;
    }
    graphicsObject[6] = 0;
    graphicsObject[2] = source2;
    graphicsObject[1] = 0;
    value6 = AllocZeroedModelHeapBlock((uint)*(ushort *)(source2 + 8) * 0x26,&DAT_00518dd4);
    graphicsObject[1] = value6;
    value4 = *(ushort *)(source2 + 8);
    *graphicsObject = (uint)value4;
    localState2 = (uint)*(ushort *)(source2 + 10);
    dataCursor = (ushort *)(*(int *)(source2 + 0x10) + 0x10 + source2);
    if (localState2 != 0) {
      dataCursor2 = localState;
      do {
        *dataCursor2 = dataCursor;
        dataCursor2 = dataCursor2 + 1;
        dataCursor = dataCursor + *dataCursor + 2;
        localState2 = localState2 - 1;
      } while (localState2 != 0);
    }
    value3 = 0;
    if (value4 != 0) {
      dataCursor4 = (undefined1 *)(value6 + 0x14);
      do {
        if ((byte)dataCursor[6] == 0xff) {
          value6 = 0;
        }
        else {
          value6 = (uint)(byte)dataCursor[6];
        }
        value5 = localState[value6];
        *dataCursor4 = 0;
        *(undefined4 *)(dataCursor4 + 0xe) = value5;
        *(undefined4 *)(dataCursor4 + 2) = 0;
        *(undefined4 *)(dataCursor4 + -4) = 0xffffffff;
        *(ushort *)(dataCursor4 + -0x12) =
             ((-(ushort)((*(byte *)((int)dataCursor + 0xd) & 0x7f) != 0) & 0xfffe) + 4) * *dataCursor;
        *(ushort *)(dataCursor4 + -0x10) = dataCursor[1];
        *(ushort *)(dataCursor4 + -0xc) = dataCursor[4];
        *(ushort *)(dataCursor4 + -10) = dataCursor[5];
        *(uint *)(dataCursor4 + -8) = (int)dataCursor + (0x10 - source2);
        value3 = value3 + 1;
        dataCursor = dataCursor + (uint)*dataCursor * (uint)dataCursor[1] + 8;
        dataCursor4 = dataCursor4 + 0x26;
      } while (value3 < (int)*graphicsObject);
    }
    value3 = 0;
    if (*(int *)(source2 + 0x14) == 0) {
      graphicsObject[3] = 0;
    }
    else {
      graphicsObject[3] = *(int *)(source2 + 0x14) + source2;
    }
    intCursor2 = (int *)graphicsObject[3];
    if (intCursor2 != (int *)0x0) {
      value = intCursor2[1];
      if ((value != 0) &&
         (intCursor = (int *)(value + 8 + (int)intCursor2), 0 < *(int *)(value + 4 + (int)intCursor2))) {
        do {
          value2 = *intCursor;
          value3 = value3 + 1;
          intCursor = intCursor + 4;
          *(undefined1 *)(graphicsObject[1] + 0x14 + value2 * 0x26) = 1;
        } while (value3 < *(int *)(value + 4 + (int)intCursor2));
      }
      value3 = *intCursor2;
      if (value3 != 0) {
        value = 0;
        if (0 < *(int *)(value3 + (int)intCursor2)) {
          intCursor = (int *)((int)intCursor2 + value3 + 8);
          do {
            value = value + 1;
            value2 = graphicsObject[1] + *intCursor * 0x26;
            *(uint **)(value2 + 0x16) = graphicsObject;
            *(int *)(value2 + 0x1a) = *intCursor;
            intCursor = intCursor + 5;
          } while (value < *(int *)(value3 + (int)intCursor2));
        }
      }
    }
    value3 = *(int *)(source2 + 0x18);
    if (value3 == 0) {
      graphicsObject[4] = 0;
      graphicsObject[5] = 0;
    }
    else {
      dataCursor2 = (undefined4 *)(value3 + 0x1c + source2);
      value7 = AllocZeroedModelHeapBlock(*(int *)(value3 + 0x18 + source2) * 0x72,&DAT_00518dd0);
      value6 = *(uint *)(value3 + 0x18 + source2);
      graphicsObject[5] = value7;
      graphicsObject[4] = value6;
      value = 0;
      if (0 < *(int *)(value3 + 0x18 + source2)) {
        dataCursor5 = (undefined4 *)(value7 + 0x52);
        do {
          value5 = *dataCursor2;
          dataCursor2 = dataCursor2 + 1;
          *dataCursor5 = value5;
          dataCursor5 = (undefined4 *)((int)dataCursor5 + 0x72);
          value = value + 1;
        } while (value < *(int *)(value3 + 0x18 + source2));
        return;
      }
    }
  }
  return;
}

