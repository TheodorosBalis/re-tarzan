#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1C20
// Label: DecodeMpcCutsceneFrameBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 DecodeMpcCutsceneFrameBlock(void)

{
  byte flagByte;
  ushort value;
  ushort value2;
  bool flagByte3;
  int entry2;
  uint value3;
  uint *dataCursor5;
  int entry3;
  uint *dataCursor6;
  uint *dataCursor;
  int entry;
  byte flagByte2;
  int *intCursor;
  uint *dataCursor2;
  int *intCursor2;
  int *intCursor3;
  undefined1 *dataCursor3;
  ushort *dataCursor4;
  uint *localState2;
  ushort *localState3;
  undefined1 *localState4;
  int localState;
  uint localState5;
  uint *incomingStackArg;
  int incomingStackArg2;
  undefined4 *incomingStackArg3;
  undefined4 *incomingStackArg4;
  
  SafeCheckStackPtr();
  if (((incomingStackArg != (uint *)0x0) && (incomingStackArg3 != (undefined4 *)0x0)) &&
     (incomingStackArg4 != (undefined4 *)0x0)) {
    g_CutsceneFrameDecodeBuffer = incomingStackArg;
    *incomingStackArg3 = &g_CutsceneBlockDecodeScratch;
    *incomingStackArg4 = g_CutsceneFrameDecodeBuffer + 1;
    if ((*g_CutsceneFrameDecodeBuffer & 0xffffff) != 0x43504d) {
      return 0xfffffffe;
    }
    if (incomingStackArg2 == 0) {
      intCursor2 = (int *)&stack0x00000018;
      entry = 0;
      do {
        if (entry < 0x20) {
          entry3 = entry;
          intCursor = intCursor2;
          intCursor3 = intCursor2;
          do {
            entry2 = (((int)(char)entry3 << 7) >> 7 & 7U | (uint)(byte)((char)entry3 << 3)) -
                    (((int)(char)entry << 7) >> 7 & 7U | (uint)(byte)((char)entry << 3));
            entry2 = entry2 * entry2;
            *intCursor3 = entry2;
            *intCursor = entry2;
            entry3 = entry3 + 1;
            intCursor = intCursor + 0x20;
            intCursor3 = intCursor3 + 1;
          } while (entry3 < 0x20);
        }
        entry = entry + 1;
        intCursor2 = intCursor2 + 0x21;
      } while (entry < 0x20);
      dataCursor2 = g_CutsceneFrameDecodeBuffer + 1;
      localState = 0;
      dataCursor3 = &g_StreamedFileWorkState_Field0028;
      localState4 = &g_StreamedFileWorkState_Field0028;
      entry = localState;
      localState3 = (ushort *)localState4;
      dataCursor = dataCursor2;
      do {
        do {
          value2 = (ushort)*dataCursor2;
          value = (ushort)*dataCursor;
          flagByte3 = *(int *)(&stack0x00000018 +
                          ((value2 >> 10 & 0x1f) * 0x20 + (value >> 10 & 0x1f)) * 4) +
                  *(int *)(&stack0x00000018 + ((value2 >> 5 & 0x1f) * 0x20 + (value >> 5 & 0x1f)) * 4
                          ) +
                  *(int *)(&stack0x00000018 + ((value2 & 0x1f) * 0x20 + (value & 0x1f)) * 4) < 0x3e9;
          dataCursor3[entry] = flagByte3;
          entry = entry + 1;
          dataCursor2 = (uint *)((int)dataCursor2 + 2);
          *(bool *)localState3 = flagByte3;
          localState3 = (ushort *)((int)localState3 + 0x100);
        } while (entry < 0x100);
        localState3 = (ushort *)(localState4 + 0x101);
        entry = localState + 1;
        dataCursor2 = (uint *)((int)dataCursor + 2);
        dataCursor3 = dataCursor3 + 0x100;
        localState = entry;
        localState4 = (undefined1 *)localState3;
        dataCursor = dataCursor2;
      } while ((int)localState3 < 0x734ff8);
      intCursor2 = &g_MpcCutsceneDecodeState_Field000C;
      do {
        entry = rand();
        entry3 = rand();
        intCursor = intCursor2 + 1;
        *intCursor2 = (entry % 5) * 0x140 + -0x282 + entry3 % 5;
        intCursor2 = intCursor;
      } while ((int)intCursor < 0x769b78);
    }
    dataCursor2 = g_CutsceneFrameDecodeBuffer;
    entry = 0;
    localState2 = g_CutsceneFrameDecodeBuffer + incomingStackArg2 * 0x960 + 0x81;
    do {
      entry3 = 0;
      dataCursor = localState2;
      do {
        value2 = (ushort)*dataCursor;
        if (value2 < 65000) {
          if (0x34bb < value2) {
            return 0xfffffffe;
          }
          entry2 = 4;
          dataCursor6 = dataCursor2 + (uint)value2 * 4 + 0x8d21;
          dataCursor5 = &g_CutsceneBlockDecodeScratch + entry + entry3;
          do {
            value3 = *dataCursor6;
            dataCursor6 = dataCursor6 + 1;
            *dataCursor5 = value3;
            dataCursor5 = dataCursor5 + 0x50;
            entry2 = entry2 + -1;
          } while (entry2 != 0);
        }
        else {
          value3 = value2 - 65000;
          dataCursor5 = &g_CutsceneBlockDecodeScratch + entry + entry3;
          entry2 = 4;
          do {
            *dataCursor5 = value3 | ((value3 * 0x100 | value3) << 8 | value3) << 8;
            dataCursor5 = dataCursor5 + 0x50;
            entry2 = entry2 + -1;
          } while (entry2 != 0);
        }
        entry3 = entry3 + 1;
        dataCursor = (uint *)((int)dataCursor + 2);
      } while (entry3 < 0x50);
      entry = entry + 0x140;
      localState2 = localState2 + 0x28;
    } while (entry < 0x4b00);
    localState3 = (ushort *)((int)dataCursor2 + incomingStackArg2 * 0x2580 + 0x2a6);
    localState = 0x500;
    flagByte2 = (byte)g_CutsceneFrameYPlaneScratch;
    do {
      localState2 = (uint *)0x4;
      dataCursor4 = localState3;
      do {
        value2 = *dataCursor4;
        if (64999 < value2) {
          localState4 = (undefined1 *)0x4;
          entry = localState;
          do {
            entry2 = 4;
            entry3 = (int)localState2;
            do {
              flagByte2 = flagByte2 + 1;
              if (0x2e < flagByte2) {
                flagByte2 = 0;
              }
              g_CutsceneFrameYPlaneScratch = CONCAT31(*( undefined1 *)((int)&g_CutsceneFrameYPlaneScratch + 1),flagByte2);
              flagByte = *(byte *)((int)&g_CutsceneBlockDecodeScratch +
                               entry3 + (&g_MpcCutsceneDecodeState_Field000C)[flagByte2] + entry);
              localState5 = (uint)flagByte;
              if ((&g_StreamedFileWorkState_Field0028)
                  [localState5 + (value2 + 0x18 & 0xff) * 0x100] != '\0') {
                *(byte *)((int)&g_CutsceneBlockDecodeScratch + entry3 + entry) = flagByte;
              }
              entry3 = entry3 + 1;
              entry2 = entry2 + -1;
            } while (entry2 != 0);
            entry = entry + 0x140;
            localState4 = (undefined1 *)((int)localState4 + -1);
          } while (localState4 != (undefined1 *)0x0);
        }
        localState2 = (uint *)((int)localState2 + 4);
        dataCursor4 = dataCursor4 + 1;
      } while ((int)localState2 < 0x13c);
      localState = localState + 0x500;
      localState3 = localState3 + 0x50;
    } while (localState < 0x12700);
    return 0;
  }
  return 0xffffffff;
}

