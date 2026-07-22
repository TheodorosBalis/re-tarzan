#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1A60
// Label: ZeroHugeDynamicBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ZeroHugeDynamicBuffer(undefined4 *arg1,int arg2,int arg3,int arg4)

{
  byte flagByte;
  undefined2 value3;
  uint value4;
  undefined4 *bufferCursor;
  byte *value5;
  int value;
  undefined4 *bufferCursor2;
  int value2;
  undefined4 scratchBuffer [128];
  
  value = 0;
  if ((((g_ActiveStreamedPlaybackHandle != 0) && (arg1 != (undefined4 *)0x0)) &&
      (g_StreamedFrameReadCursor != (undefined4 *)0x0)) && (g_StreamedWorkActiveBuffer != 0)) {
    if (arg3 == 0) {
      bufferCursor = scratchBuffer;
      for (value2 = 0x80; value2 != 0; value2 = value2 + -1) {
        *bufferCursor = *g_StreamedFrameReadCursor;
        g_StreamedFrameReadCursor = g_StreamedFrameReadCursor + 1;
        bufferCursor = bufferCursor + 1;
      }
    }
    else {
      value2 = 0x100;
      bufferCursor = scratchBuffer;
      do {
        value4 = (uint)*(ushort *)(((int)g_StreamedFrameReadCursor - (int)scratchBuffer) + (int)bufferCursor);
        _g_HugeDynamicBufferBase = (value4 & 0x7fe0) << 1 | value4 & 0x3f;
        value2 = value2 + -1;
        *(short *)bufferCursor = (short)_g_HugeDynamicBufferBase;
        bufferCursor = (undefined4 *)((int)bufferCursor + 2);
      } while (value2 != 0);
    }
    arg2 = arg2 / 2;
    bufferCursor = arg1;
    if (arg4 == 0) {
      value = 0;
      g_StreamedWorkFileHandle = 0;
      do {
        value2 = 0xa0;
        value5 = (byte *)(value + g_StreamedWorkActiveBuffer);
        bufferCursor = arg1;
        do {
          value2 = value2 + -1;
          *bufferCursor = CONCAT22(*(undefined2 *)((int)scratchBuffer + (uint)value5[1] * 2),
                             *(undefined2 *)((int)scratchBuffer + (uint)*value5 * 2));
          value5 = value5 + 2;
          bufferCursor = bufferCursor + 1;
        } while (value2 != 0);
        value = value + 0x140;
        arg1 = (undefined4 *)((int)arg1 + arg2 * 2);
      } while (value < 0x12c00);
    }
    else {
      do {
        value5 = (byte *)(g_StreamedWorkActiveBuffer + value);
        value2 = 0x140;
        bufferCursor2 = bufferCursor;
        do {
          flagByte = *value5;
          value5 = value5 + 1;
          value3 = *(undefined2 *)((int)scratchBuffer + (uint)flagByte * 2);
          value2 = value2 + -1;
          *bufferCursor2 = CONCAT22(value3,value3);
          bufferCursor2 = bufferCursor2 + 1;
        } while (value2 != 0);
        value = value + 0x140;
        bufferCursor = bufferCursor + arg2;
      } while (value < 0x12c00);
      if (g_StreamedWorkFileHandle < 5) {
        g_StreamedWorkFileHandle = g_StreamedWorkFileHandle + 1;
        value = 0xf0;
        arg1 = (undefined4 *)((int)arg1 + arg2 * 2);
        do {
          bufferCursor = arg1;
          for (value2 = 0x140; value2 != 0; value2 = value2 + -1) {
            *bufferCursor = 0;
            bufferCursor = bufferCursor + 1;
          }
          arg1 = arg1 + arg2;
          value = value + -1;
        } while (value != 0);
      }
    }
    g_StreamedFrameReadCursor = (undefined4 *)0x0;
    g_StreamedWorkActiveBuffer = 0;
  }
  return;
}

