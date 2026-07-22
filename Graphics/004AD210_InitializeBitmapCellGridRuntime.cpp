#include "tarzan_ghidra_types.hpp"

// Address: 0x004AD210
// Label: InitializeBitmapCellGridRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitializeBitmapCellGridRuntime(int arg1,int *arg2,int arg3)

{
  int value;
  int *intCursor;
  int value2;
  int value3;
  undefined4 *dataCursor;
  int value4;
  undefined4 *dataCursor2;
  int value5;
  int localState3;
  int localState2;
  int localState;
  
  intCursor = arg2;
  value = arg1;
  if (((arg1 != 0) && (arg2 != (int *)0x0)) && (arg3 != 0)) {
    arg2[1] = 2;
    *(undefined4 *)((int)arg2 + 0x3a) = *(undefined4 *)(arg1 + 0xc);
    *(undefined4 *)((int)arg2 + 0x3e) = *(undefined4 *)(arg1 + 0x10);
    value3 = 1 << ((byte)*(undefined4 *)(arg1 + 0xc) & 0x1f);
    *(int *)((int)arg2 + 0x42) = value3;
    *(int *)((int)arg2 + 0x46) = 1 << ((byte)*(undefined4 *)(arg1 + 0x10) & 0x1f);
    *(int *)((int)arg2 + 0x4a) = value3 + -1;
    *(int *)((int)arg2 + 0x4e) = *(int *)((int)arg2 + 0x46) + -1;
    *(int *)((int)arg2 + 0x32) = value3 * *(int *)(arg1 + 4);
    *(int *)((int)arg2 + 0x36) = *(int *)(arg1 + 8) * *(int *)((int)arg2 + 0x46);
    dataCursor = (undefined4 *)(arg1 + 0x14);
    dataCursor2 = (undefined4 *)((int)arg2 + 0x56);
    for (value2 = 7; value2 != 0; value2 = value2 + -1) {
      *dataCursor2 = *dataCursor;
      dataCursor = dataCursor + 1;
      dataCursor2 = dataCursor2 + 1;
    }
    if (*(int *)((int)arg2 + 0x6a) < 1) {
      arg1 = 0;
    }
    else {
      arg1 = (value3 + 0x27f) / *(int *)((int)arg2 + 0x42);
    }
    *(int *)((int)arg2 + 0x2a) = *(int *)(value + 4) + arg1;
    *(undefined4 *)((int)arg2 + 0x2e) = *(undefined4 *)(value + 8);
    value2 = *(int *)(value + 4);
    value3 = *(int *)(value + 8);
    *arg2 = 0;
    value2 = AllocZeroedModelHeapBlock((value2 + arg1) * value3 * 0x1c,&DAT_00518dc8);
    localState3 = value + 0x34;
    *arg2 = value2;
    arg2[2] = 0;
    value2 = 0;
    localState = 0;
    arg2 = (int *)0x0;
    if (0 < *(int *)(value + 8)) {
      do {
        value3 = 0;
        localState2 = 0;
        if (0 < *(int *)(value + 4)) {
          value4 = value2 * 0xe;
          value5 = localState3;
          do {
            BuildBitmapCellRenderCommand
                      (value5,value4 + *intCursor,*(undefined2 *)((int)intCursor + 0x42),
                       CONCAT22((short)((uint)value3 >> 0x10),*(undefined2 *)((int)intCursor + 0x46)),
                       arg3);
            localState2 = localState2 + 1;
            value5 = value5 + 2;
            value2 = (int)arg2 + 1;
            value3 = *(int *)(value + 4);
            value4 = value4 + 0xe;
            arg2 = (int *)value2;
          } while (localState2 < value3);
        }
        value3 = 0;
        if (0 < arg1) {
          value4 = value2 * 0xe;
          value2 = value2 + arg1;
          value5 = value2;
          do {
            BuildBitmapCellRenderCommand
                      (localState3 + (value3 % *(int *)(value + 4)) * 2,value4 + *intCursor,
                       CONCAT22((short)((uint)value5 >> 0x10),*(undefined2 *)((int)intCursor + 0x42)),
                       *(undefined2 *)((int)intCursor + 0x46),arg3);
            value3 = value3 + 1;
            value4 = value4 + 0xe;
            value5 = arg1;
            arg2 = (int *)value2;
          } while (value3 < arg1);
        }
        localState3 = localState3 + *(int *)(value + 4) * 2;
        localState = localState + 1;
      } while (localState < *(int *)(value + 8));
    }
  }
  return;
}

