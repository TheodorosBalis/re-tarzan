#include "tarzan_ghidra_types.hpp"

// Address: 0x004ACCE0
// Label: BuildPalettedTextureBlockRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildPalettedTextureBlockRuntime(int *graphicsObject)

{
  ushort value4;
  int value2;
  int *intCursor;
  uint value5;
  undefined2 value6;
  undefined2 *dataCursor;
  int *intCursor2;
  int value3;
  ushort *dataCursor2;
  int value;
  int localState;
  int localState2;
  
  if (graphicsObject != (int *)0x0) {
    dataCursor = (undefined2 *)graphicsObject[1];
    value2 = 0;
    if (0 < *graphicsObject) {
      do {
        *dataCursor = 0;
        value2 = value2 + 1;
        dataCursor = dataCursor + 0x13;
      } while (value2 < *graphicsObject);
    }
    if (graphicsObject[4] != 0) {
      localState = 0;
      if (0 < graphicsObject[4]) {
        intCursor2 = (int *)(graphicsObject[5] + 0x52);
        do {
          value2 = *intCursor2 + graphicsObject[2];
          value = 0;
          dataCursor2 = (ushort *)(value2 + 0x34);
          if (0 < *(int *)(value2 + 8)) {
            do {
              value3 = 0;
              if (0 < *(int *)(value2 + 4)) {
                do {
                  if ((*dataCursor2 & 0x8000) == 0) {
                    *(undefined2 *)(graphicsObject[1] + (uint)*dataCursor2 * 0x26) = 1;
                  }
                  value3 = value3 + 1;
                  dataCursor2 = dataCursor2 + 1;
                } while (value3 < *(int *)(value2 + 4));
              }
              value = value + 1;
            } while (value < *(int *)(value2 + 8));
          }
          localState = localState + 1;
          intCursor2 = (int *)((int)intCursor2 + 0x72);
        } while (localState < graphicsObject[4]);
      }
    }
    intCursor2 = (int *)graphicsObject[3];
    if (intCursor2 != (int *)0x0) {
      localState = 0;
      intCursor2 = (int *)(*intCursor2 + (int)intCursor2);
      intCursor = intCursor2 + 1;
      if (0 < *intCursor2) {
        do {
          value2 = *intCursor;
          localState2 = 0;
          dataCursor = (undefined2 *)(graphicsObject[1] + intCursor[1] * 0x26);
          if (0 < intCursor[2]) {
            do {
              value = *(int *)((int)intCursor + localState2 * 4 + value2);
              value5 = AllocatePalettedTextureAtlasRect(dataCursor[1],dataCursor[2],0);
              *(uint *)((int)intCursor + localState2 * 4 + value2) = value5;
              if (value5 != 0) {
                UploadPalettedTextureRect
                          (value5 >> 1 & 0xf,(value5 >> 5 & 0x1f) << 3,(value5 >> 10 & 0x1f) << 3,
                           dataCursor[1],dataCursor[2],(int)intCursor + localState2 * 4 + value + value2,
                           **(undefined2 **)(dataCursor + 0x11),*(undefined2 **)(dataCursor + 0x11) + 2);
              }
              localState2 = localState2 + 1;
            } while (localState2 < intCursor[2]);
          }
          dataCursor[3] = 0;
          *dataCursor = 0;
          localState = localState + 1;
          intCursor = intCursor + 5;
        } while (localState < *intCursor2);
      }
    }
    dataCursor = (undefined2 *)graphicsObject[1];
    value2 = 0;
    if (0 < *graphicsObject) {
      do {
        if (*(int *)(dataCursor + 0xb) == 0) {
          value4 = dataCursor[2];
          value6 = *dataCursor;
          if (value4 < 0x28) {
            value6 = 1;
          }
          if (*(char *)(dataCursor + 10) == '\0') {
            value5 = (uint)value4;
          }
          else {
            value5 = (uint)value4 << 1;
          }
          value5 = AllocatePalettedTextureAtlasRect(dataCursor[1],value5,value6);
          dataCursor[3] = (ushort)(value5 >> 1) & 0xf;
          *(uint *)(dataCursor + 8) = value5;
          *dataCursor = (short)((value5 >> 10 & 0x1f | (value5 >> 5 & 0xff) << 8) << 3);
          if ((value5 != 0) &&
             (UploadPalettedTextureRect
                        (value5 >> 1 & 0xf,(value5 >> 5 & 0x1f) << 3,(value5 >> 10 & 0x1f) << 3,
                         dataCursor[1],dataCursor[2],*(int *)(dataCursor + 6) + graphicsObject[2],
                         **(undefined2 **)(dataCursor + 0x11),*(undefined2 **)(dataCursor + 0x11) + 2),
             *(char *)(dataCursor + 10) != '\0')) {
            value5 = *(uint *)(dataCursor + 8);
            UploadPalettedTextureRect
                      (value5 >> 1 & 0xf,(value5 >> 5 & 0x1f) << 3,
                       (uint)(ushort)dataCursor[2] + (value5 >> 10 & 0x1f) * 8,dataCursor[1],
                       (uint)(ushort)dataCursor[2],*(int *)(dataCursor + 6) + graphicsObject[2],
                       **(undefined2 **)(dataCursor + 0x11),*(undefined2 **)(dataCursor + 0x11) + 2);
          }
        }
        value2 = value2 + 1;
        dataCursor = dataCursor + 0x13;
      } while (value2 < *graphicsObject);
    }
    if (graphicsObject[4] != 0) {
      value2 = graphicsObject[5];
      value = 0;
      if (0 < graphicsObject[4]) {
        do {
          InitializeBitmapCellGridRuntime(*(int *)(value2 + 0x52) + graphicsObject[2],value2,graphicsObject);
          value2 = value2 + 0x72;
          LegacyTransitionCallback_Stub(0,0,0);
          value = value + 1;
        } while (value < graphicsObject[4]);
      }
    }
  }
  return;
}

