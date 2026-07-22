#include "tarzan_ghidra_types.hpp"

// Address: 0x004B75AF
// Label: StringConvertBuffersBigFunction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 StringConvertBuffersBigFunction(undefined4 arg1)

{
  BYTE *value7;
  byte *value12;
  byte flagByte;
  byte flagByte2;
  UINT CodePage;
  UINT *value9;
  BOOL value;
  uint value5;
  uint value6;
  BYTE *value8;
  int value2;
  byte *value10;
  int value3;
  byte *value11;
  undefined4 value4;
  undefined4 *bufferCursor;
  _cpinfo scratchBuffer;
  uint scratchBuffer2;
  
  _lock(0x19);
  CodePage = SelectSystemCharCodePage(arg1);
  if (CodePage != g_CrtCurrentCodePage) {
    if (CodePage != 0) {
      value3 = 0;
      value9 = &DAT_0051baa8;
LAB_004b75ec:
      if (*value9 != CodePage) goto code_r0x004b75f0;
      scratchBuffer2 = 0;
      bufferCursor = &DAT_00c47120;
      for (value2 = 0x40; value2 != 0; value2 = value2 + -1) {
        *bufferCursor = 0;
        bufferCursor = bufferCursor + 1;
      }
      value3 = value3 * 0x30;
      *(undefined1 *)bufferCursor = 0;
      value11 = &g_CrtStringConvertBufferC + value3;
      do {
        flagByte = *value11;
        value10 = value11;
        while ((flagByte != 0 && (flagByte = value10[1], flagByte != 0))) {
          value6 = (uint)*value10;
          if (value6 <= flagByte) {
            flagByte2 = (&g_CrtStringConvertBufferA)[scratchBuffer2];
            do {
              value12 = (byte *)((int)&DAT_00c47120 + value6 + 1);
              *value12 = *value12 | flagByte2;
              value6 = value6 + 1;
            } while (value6 <= flagByte);
          }
          value10 = value10 + 2;
          flagByte = *value10;
        }
        scratchBuffer2 = scratchBuffer2 + 1;
        value11 = value11 + 8;
      } while (scratchBuffer2 < 4);
      _g_CrtMbCodePageActive = 1;
      g_CrtCurrentCodePage = CodePage;
      g_CrtLocaleIdForCodePage = ReturnBasedOnArgSize(CodePage);
      DAT_00c47000 = *(undefined4 *)(&g_CrtStringConvertBufferB + value3);
      DAT_00c47004 = *(undefined4 *)(value3 + 0x51bab0);
      DAT_00c47008 = *(undefined4 *)(value3 + 0x51bab4);
      goto LAB_004b7740;
    }
    goto LAB_004b773b;
  }
  goto LAB_004b75d6;
code_r0x004b75f0:
  value9 = value9 + 0xc;
  value3 = value3 + 1;
  if (0x51bb97 < (int)value9) goto code_r0x004b75fb;
  goto LAB_004b75ec;
code_r0x004b75fb:
  value = GetCPInfo(CodePage,&scratchBuffer);
  value6 = 1;
  if (value == 1) {
    g_CrtLocaleIdForCodePage = 0;
    bufferCursor = &DAT_00c47120;
    for (value3 = 0x40; value3 != 0; value3 = value3 + -1) {
      *bufferCursor = 0;
      bufferCursor = bufferCursor + 1;
    }
    *(undefined1 *)bufferCursor = 0;
    if (scratchBuffer.MaxCharSize < 2) {
      _g_CrtMbCodePageActive = 0;
      g_CrtCurrentCodePage = CodePage;
    }
    else {
      g_CrtCurrentCodePage = CodePage;
      if (scratchBuffer.LeadByte[0] != '\0') {
        value8 = scratchBuffer.LeadByte + 1;
        do {
          flagByte = *value8;
          if (flagByte == 0) break;
          for (value5 = (uint)value8[-1]; value5 <= flagByte; value5 = value5 + 1) {
            value11 = (byte *)((int)&DAT_00c47120 + value5 + 1);
            *value11 = *value11 | 4;
          }
          value7 = value8 + 1;
          value8 = value8 + 2;
        } while (*value7 != 0);
      }
      do {
        value11 = (byte *)((int)&DAT_00c47120 + value6 + 1);
        *value11 = *value11 | 8;
        value6 = value6 + 1;
      } while (value6 < 0xff);
      g_CrtLocaleIdForCodePage = ReturnBasedOnArgSize(CodePage);
      _g_CrtMbCodePageActive = 1;
    }
    DAT_00c47000 = 0;
    DAT_00c47004 = 0;
    DAT_00c47008 = 0;
  }
  else {
    if (g_CrtCodePageAutoSelectMode == 0) {
      value4 = 0xffffffff;
      goto LAB_004b774d;
    }
LAB_004b773b:
    ZeroBufferC47000();
  }
LAB_004b7740:
  ConvertAndUpdateStringBuffers();
LAB_004b75d6:
  value4 = 0;
LAB_004b774d:
  _unlock(0x19);
  return value4;
}

