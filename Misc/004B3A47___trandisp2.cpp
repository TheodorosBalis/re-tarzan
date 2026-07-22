#include "tarzan_ghidra_types.hpp"

// Address: 0x004B3A47
// Label: __trandisp2
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __trandisp2
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */

void __fastcall __trandisp2(undefined4 arg1,int arg2)

{
  float10 value;
  char resultFlag;
  byte flagByte;
  undefined2 value2;
  int callerFrameBase;
  float10 fpuValue;
  float10 fpuValue2;
  
  if (*(char *)(arg2 + 0xe) == '\x05') {
    value2 = (undefined2)
            CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(callerFrameBase + -0xa4) >> 8) & 0xfe | 2),
                     0x3f);
  }
  else {
    value2 = 0x133f;
  }
  *(undefined2 *)(callerFrameBase + -0xa2) = value2;
  value = (float10)0;
  *(int *)(callerFrameBase + -0x94) = arg2;
  *(ushort *)(callerFrameBase + -0xa0) =
       (ushort)NAN(fpuValue) << 8 | (ushort)(fpuValue < value) << 9 | (ushort)(fpuValue != value) << 10 |
       (ushort)(fpuValue == value) << 0xe;
  *(undefined1 *)(callerFrameBase + -0x90) = 0;
  value = (float10)0;
  *(ushort *)(callerFrameBase + -0xa0) =
       (ushort)NAN(fpuValue2) << 8 | (ushort)(fpuValue2 < value) << 9 | (ushort)(fpuValue2 != value) << 10 |
       (ushort)(fpuValue2 == value) << 0xe;
  flagByte = (char)(*(char *)(callerFrameBase + -0x9f) << 1) >> 1;
  resultFlag = (char)(*(char *)(callerFrameBase + -0x9f) << 1) >> 1;
                    /* WARNING: Could not recover jumptable at 0x004b3ad1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(arg2 + (char)((&g_CrtFxamClassToDispatchOffsetTable)
                                [(byte)(resultFlag << 1 | resultFlag < '\0') & 0xf] |
                               (&g_CrtFxamClassToDispatchOffsetTable)
                               [(byte)((flagByte & 7) << 1 | (char)flagByte < '\0')] << 2) + 0x10))();
  return;
}

