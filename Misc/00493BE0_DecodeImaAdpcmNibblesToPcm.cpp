#include "tarzan_ghidra_types.hpp"

// Address: 0x00493BE0
// Label: DecodeImaAdpcmNibblesToPcm
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DecodeImaAdpcmNibblesToPcm(char *arg1,char *arg2,uint arg3,uint *arg4)

{
  bool flagByte;
  uint value4;
  uint value5;
  int value;
  int value2;
  int value3;
  undefined2 *localState;
  
  localState = (undefined2 *)arg2;
  value4 = *arg4 & 0xff;
  value3 = (&g_DecodeImaAdpcmNibblesToPcm_Global_00515554)[value4];
  flagByte = false;
  value2 = (int)*arg4 >> 8;
  arg2 = arg1;
  arg1 = (char *)((int)arg3 >> 1);
  if (0 < (int)arg3 >> 1) {
    do {
      value5 = arg3;
      if (!flagByte) {
        arg3 = (uint)*arg2;
        arg2 = arg2 + 1;
        value5 = (int)arg3 >> 4;
      }
      flagByte = !flagByte;
      value4 = value4 + *(int *)(&g_ImaAdpcmIndexAdjustTable + (value5 & 0xf) * 4);
      if ((int)value4 < 0) {
        value4 = 0;
      }
      else if (0x58 < (int)value4) {
        value4 = 0x58;
      }
      value = value3 >> 3;
      if ((value5 & 4) != 0) {
        value = value + value3;
      }
      if ((value5 & 2) != 0) {
        value = value + (value3 >> 1);
      }
      if ((value5 & 1) != 0) {
        value = value + (value3 >> 2);
      }
      if ((value5 & 8) != 0) {
        value = -value;
      }
      value2 = value2 + value;
      if (value2 < 0x8000) {
        if (value2 < -0x8000) {
          value2 = -0x8000;
        }
      }
      else {
        value2 = 0x7fff;
      }
      value3 = (&g_DecodeImaAdpcmNibblesToPcm_Global_00515554)[value4];
      *localState = (short)value2;
      localState = localState + 1;
      arg1 = (char *)((int)arg1 + -1);
    } while (arg1 != (char *)0x0);
  }
  *arg4 = value4 & 0xff | value2 << 8;
  return;
}

