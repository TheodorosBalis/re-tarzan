#include "tarzan_ghidra_types.hpp"

// Address: 0x00493D00
// Label: WriteScreenshotBmp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void WriteScreenshotBmp(int arg1,byte *arg2,int arg3,int arg4,int arg5,int arg6)

{
  byte flagByte;
  int value;
  byte *value4;
  int value2;
  byte *value5;
  int value3;
  int localState19;
  undefined2 localState18;
  int localState17;
  undefined2 localState16;
  undefined2 localState15;
  undefined4 localState14;
  undefined4 localState13;
  int localState12;
  int localState11;
  undefined2 localState10;
  undefined2 localState9;
  undefined4 localState8;
  int localState7;
  undefined4 localState6;
  undefined4 localState5;
  undefined4 localState4;
  undefined4 localState3;
  undefined1 localState2;
  byte localState [3071];
  
  localState18 = 0x4d42;
  localState17 = arg4 * arg5 * 3 + 0x36;
  localState7 = arg4 * arg5 * 3;
  localState14 = 0x36;
  localState16 = 0;
  localState15 = 0;
  localState13 = 0x28;
  localState12 = arg4;
  localState11 = arg5;
  localState10 = 1;
  localState9 = 0x18;
  localState8 = 0;
  localState6 = 0;
  localState5 = 0;
  localState4 = 0;
  localState3 = 0;
  if ((((arg1 != 0) && (arg2 != (byte *)0x0)) && (0 < arg3)) &&
     (((arg4 < 0x401 && (0 < arg5)) &&
      (value = fopen(arg1,&s_FileModeWriteBinary), value != 0)))) {
    fwrite(&localState18,0xe,1,value);
    fwrite(&localState13,0x28,1,value);
    arg3 = arg3 / 2;
    arg2 = (byte *)((int)arg2 + (arg5 + -1) * arg3 * 2);
    if (0 < arg5) {
      localState19 = arg5;
      do {
        if (arg6 == 0) {
          if (0 < arg4) {
            value4 = localState;
            value2 = arg4;
            value5 = arg2;
            value3 = arg3;
            do {
              value3 = CONCAT22((short)((uint)value3 >> 0x10),*(undefined2 *)value5);
              value4[1] = -((value3 >> 10 & 1U) != 0) & 7U | (char)(value3 >> 10) << 3;
              flagByte = *value5;
              *value4 = -((value3 >> 5 & 1U) != 0) & 7U | (char)(value3 >> 5) << 3;
              value5 = value5 + 2;
              value2 = value2 + -1;
              value4[-1] = -((flagByte & 1) != 0) & 7U | flagByte << 3;
              value4 = value4 + 3;
            } while (value2 != 0);
          }
        }
        else if (0 < arg4) {
          value4 = localState;
          value2 = arg4;
          value5 = arg2;
          value3 = arg3;
          do {
            value3 = CONCAT22((short)((uint)value3 >> 0x10),*(undefined2 *)value5);
            value4[1] = -((value3 >> 0xb & 1U) != 0) & 7U | (char)(value3 >> 0xb) << 3;
            flagByte = *value5;
            *value4 = -((value3 >> 5 & 1U) != 0) & 3U | (char)(value3 >> 5) << 2;
            value5 = value5 + 2;
            value2 = value2 + -1;
            value4[-1] = -((flagByte & 1) != 0) & 7U | flagByte << 3;
            value4 = value4 + 3;
          } while (value2 != 0);
        }
        fwrite(&localState2,arg4 * 3,1,value);
        arg2 = arg2 + arg3 * -2;
        localState19 = localState19 + -1;
      } while (localState19 != 0);
    }
    fclose(value);
  }
  return;
}

