#include "tarzan_ghidra_types.hpp"

// Address: 0x004AA0E0
// Label: ProjectAndQueueModelTriangles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ProjectAndQueueModelTriangles(int arg1,int arg2)

{
  float *floatCursor;
  int value;
  int value2;
  uint value5;
  int value3;
  int value4;
  ushort *dataCursor;
  
  value3 = arg1;
  value4 = TransformModelVerticesForRender(arg1);
  if ((((arg1 != 0) && (value4 != -1)) && (arg2 != -1)) &&
     (value2 = *(int *)(arg1 + 0x20), value2 != 0)) {
    value = arg1 + 0x20;
    dataCursor = (ushort *)(arg1 + 0x24 + value2);
    arg1 = 0;
    if (0 < *(int *)(value + value2)) {
      do {
        value5 = *(uint *)(dataCursor + 10);
        value = ((uint)*dataCursor + value4) * 0x3c;
        floatCursor = (float *)(&g_ModelProjectionScratch + value);
        if (-1 < (int)value5) {
          *floatCursor = *(float *)(&g_ModelProjectionScratch +
                              ((((int)value5 >> 2) + arg2) * 0xf + (value5 & 3)) * 4);
          *(undefined4 *)(&g_ModelProjectionScreenY0 + value) =
               *(undefined4 *)
                (&g_ModelProjectionScreenY0 +
                ((((int)*(uint *)(dataCursor + 10) >> 2) + arg2) * 0xf + (*(uint *)(dataCursor + 10) & 3)
                ) * 4);
          *(undefined4 *)(&g_ModelProjectionCameraZ0 + value) =
               *(undefined4 *)
                (&g_ModelProjectionCameraZ0 +
                ((((int)*(uint *)(dataCursor + 10) >> 2) + arg2) * 0xf + (*(uint *)(dataCursor + 10) & 3)
                ) * 4);
        }
        value5 = *(uint *)(dataCursor + 0xc);
        if (-1 < (int)value5) {
          *(undefined4 *)(&DAT_00a348b4 + value) =
               *(undefined4 *)
                (&g_ModelProjectionScratch + ((((int)value5 >> 2) + arg2) * 0xf + (value5 & 3)) * 4
                );
          *(undefined4 *)(&DAT_00a348c0 + value) =
               *(undefined4 *)
                (&g_ModelProjectionScreenY0 +
                ((((int)*(uint *)(dataCursor + 0xc) >> 2) + arg2) * 0xf +
                (*(uint *)(dataCursor + 0xc) & 3)) * 4);
          *(undefined4 *)(&DAT_00a348cc + value) =
               *(undefined4 *)
                (&g_ModelProjectionCameraZ0 +
                ((((int)*(uint *)(dataCursor + 0xc) >> 2) + arg2) * 0xf +
                (*(uint *)(dataCursor + 0xc) & 3)) * 4);
        }
        value5 = *(uint *)(dataCursor + 0xe);
        if (-1 < (int)value5) {
          *(undefined4 *)(&DAT_00a348b8 + value) =
               *(undefined4 *)
                (&g_ModelProjectionScratch + ((((int)value5 >> 2) + arg2) * 0xf + (value5 & 3)) * 4
                );
          *(undefined4 *)(&DAT_00a348c4 + value) =
               *(undefined4 *)
                (&g_ModelProjectionScreenY0 +
                ((((int)*(uint *)(dataCursor + 0xe) >> 2) + arg2) * 0xf +
                (*(uint *)(dataCursor + 0xe) & 3)) * 4);
          *(undefined4 *)(&DAT_00a348d0 + value) =
               *(undefined4 *)
                (&g_ModelProjectionCameraZ0 +
                ((((int)*(uint *)(dataCursor + 0xe) >> 2) + arg2) * 0xf +
                (*(uint *)(dataCursor + 0xe) & 3)) * 4);
        }
        if (((_g_FloatZero < *(float *)(&g_ModelProjectionCameraZ0 + value)) &&
            (_g_FloatZero < *(float *)(&DAT_00a348cc + value))) &&
           ((_g_FloatZero < *(float *)(&DAT_00a348d0 + value) &&
            ((*(ushort *)(&DAT_00a348e8 + value) & 0x180) >> 7 !=
             (uint)((*(float *)(&DAT_00a348c4 + value) -
                    *(float *)(&g_ModelProjectionScreenY0 + value)) *
                    (*(float *)(&DAT_00a348b4 + value) - *floatCursor) -
                    (*(float *)(&DAT_00a348c0 + value) -
                    *(float *)(&g_ModelProjectionScreenY0 + value)) *
                    (*(float *)(&DAT_00a348b8 + value) - *floatCursor) <= _g_FloatZero))))) {
          QueueRenderPacket(floatCursor);
        }
        arg1 = arg1 + 1;
        dataCursor = dataCursor + 0x10;
      } while (arg1 < *(int *)(value3 + 0x20 + value2));
      return value4;
    }
  }
  return value4;
}

