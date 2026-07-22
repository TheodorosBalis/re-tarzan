#include "tarzan_ghidra_types.hpp"

// Address: 0x004B39E0
// Label: __trandisp1
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __trandisp1
   
   Library: Visual Studio */

void __fastcall __trandisp1(undefined4 arg1,int arg2)

{
  float10 value;
  byte flagByte;
  undefined2 value2;
  int callerFrameBase;
  float10 fpuValue;
  
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
  flagByte = (char)(*(char *)(callerFrameBase + -0x9f) << 1) >> 1;
                    /* WARNING: Could not recover jumptable at 0x004b3a45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(arg2 + (char)(&g_CrtFxamClassToDispatchOffsetTable)
                               [(byte)((flagByte & 7) << 1 | (char)flagByte < '\0')] + 0x10))();
  return;
}

