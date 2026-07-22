#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7802
// Label: ConvertAndUpdateStringBuffers
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ConvertAndUpdateStringBuffers(void)

{
  byte *value3;
  BOOL value;
  uint value4;
  char resultFlag;
  uint value5;
  uint value6;
  ushort *bufferCursor2;
  undefined1 value7;
  BYTE *value2;
  undefined4 *bufferCursor;
  ushort scratchBuffer5 [256];
  undefined1 scratchBuffer4 [256];
  undefined1 scratchBuffer3 [256];
  undefined4 scratchBuffer [64];
  _cpinfo scratchBuffer2;
  
  value = GetCPInfo(g_CrtCurrentCodePage,&scratchBuffer2);
  if (value == 1) {
    value4 = 0;
    do {
      *(char *)((int)scratchBuffer + value4) = (char)value4;
      value4 = value4 + 1;
    } while (value4 < 0x100);
    scratchBuffer[0]._0_1_ = 0x20;
    if (scratchBuffer2.LeadByte[0] != 0) {
      value2 = scratchBuffer2.LeadByte + 1;
      do {
        value4 = (uint)scratchBuffer2.LeadByte[0];
        if (value4 <= *value2) {
          value5 = (*value2 - value4) + 1;
          bufferCursor = (undefined4 *)((int)scratchBuffer + value4);
          for (value6 = value5 >> 2; value6 != 0; value6 = value6 - 1) {
            *bufferCursor = 0x20202020;
            bufferCursor = bufferCursor + 1;
          }
          for (value5 = value5 & 3; value5 != 0; value5 = value5 - 1) {
            *(undefined1 *)bufferCursor = 0x20;
            bufferCursor = (undefined4 *)((int)bufferCursor + 1);
          }
        }
        scratchBuffer2.LeadByte[0] = value2[1];
        value2 = value2 + 2;
      } while (scratchBuffer2.LeadByte[0] != 0);
    }
    ConvertCPandUpdateBuffer
              (1,scratchBuffer,0x100,scratchBuffer5,g_CrtCurrentCodePage,g_CrtLocaleIdForCodePage,0);
    ReturnLengthOfConvertedString
              (g_CrtLocaleIdForCodePage,0x100,scratchBuffer,0x100,scratchBuffer3,0x100,g_CrtCurrentCodePage,0
              );
    ReturnLengthOfConvertedString
              (g_CrtLocaleIdForCodePage,0x200,scratchBuffer,0x100,scratchBuffer4,0x100,g_CrtCurrentCodePage,0
              );
    value4 = 0;
    bufferCursor2 = scratchBuffer5;
    do {
      if ((*bufferCursor2 & 1) == 0) {
        if ((*bufferCursor2 & 2) != 0) {
          value3 = (byte *)((int)&DAT_00c47120 + value4 + 1);
          *value3 = *value3 | 0x20;
          value7 = scratchBuffer4[value4];
          goto LAB_004b790e;
        }
        (&g_CrtCaseMapTable)[value4] = 0;
      }
      else {
        value3 = (byte *)((int)&DAT_00c47120 + value4 + 1);
        *value3 = *value3 | 0x10;
        value7 = scratchBuffer3[value4];
LAB_004b790e:
        (&g_CrtCaseMapTable)[value4] = value7;
      }
      value4 = value4 + 1;
      bufferCursor2 = bufferCursor2 + 1;
    } while (value4 < 0x100);
  }
  else {
    value4 = 0;
    do {
      if ((value4 < 0x41) || (0x5a < value4)) {
        if ((0x60 < value4) && (value4 < 0x7b)) {
          value3 = (byte *)((int)&DAT_00c47120 + value4 + 1);
          *value3 = *value3 | 0x20;
          resultFlag = (char)value4 + -0x20;
          goto LAB_004b7958;
        }
        (&g_CrtCaseMapTable)[value4] = 0;
      }
      else {
        value3 = (byte *)((int)&DAT_00c47120 + value4 + 1);
        *value3 = *value3 | 0x10;
        resultFlag = (char)value4 + ' ';
LAB_004b7958:
        (&g_CrtCaseMapTable)[value4] = resultFlag;
      }
      value4 = value4 + 1;
    } while (value4 < 0x100);
  }
  return;
}

