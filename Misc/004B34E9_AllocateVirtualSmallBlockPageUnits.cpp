#include "tarzan_ghidra_types.hpp"

// Address: 0x004B34E9
// Label: AllocateVirtualSmallBlockPageUnits
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int AllocateVirtualSmallBlockPageUnits(int *arg1,uint arg2,uint arg3)

{
  byte *value2;
  byte *value3;
  byte flagByte;
  byte *value4;
  uint value;
  byte *value5;
  
  value3 = (byte *)*arg1;
  value2 = (byte *)(arg1 + 0x3e);
  flagByte = (byte)arg3;
  if ((uint)arg1[1] < arg3) {
    value5 = value3;
    if (value3[arg1[1]] != 0) {
      value5 = value3 + arg1[1];
    }
    while( true ) {
      while( true ) {
        if (value2 <= value5 + arg3) {
          value5 = (byte *)(arg1 + 2);
          while( true ) {
            while( true ) {
              if (value3 <= value5) {
                return 0;
              }
              if (value2 <= value5 + arg3) {
                return 0;
              }
              if (*value5 == 0) break;
              value5 = value5 + *value5;
            }
            value = 1;
            value4 = value5;
            while (value4 = value4 + 1, *value4 == 0) {
              value = value + 1;
            }
            if (arg3 <= value) break;
            arg2 = arg2 - value;
            value5 = value4;
            if (arg2 < arg3) {
              return 0;
            }
          }
          if (value5 + arg3 < value2) {
            *arg1 = (int)(value5 + arg3);
            arg1[1] = value - arg3;
          }
          else {
            arg1[1] = 0;
            *arg1 = (int)(arg1 + 2);
          }
          *value5 = flagByte;
          value3 = value5 + 8;
          goto LAB_004b35fc;
        }
        if (*value5 == 0) break;
        value5 = value5 + *value5;
      }
      value = 1;
      value4 = value5;
      while (value4 = value4 + 1, *value4 == 0) {
        value = value + 1;
      }
      if (arg3 <= value) break;
      if (value5 == value3) {
        arg1[1] = value;
        value5 = value4;
      }
      else {
        arg2 = arg2 - value;
        value5 = value4;
        if (arg2 < arg3) {
          return 0;
        }
      }
    }
    if (value5 + arg3 < value2) {
      *arg1 = (int)(value5 + arg3);
      arg1[1] = value - arg3;
    }
    else {
      arg1[1] = 0;
      *arg1 = (int)(arg1 + 2);
    }
    *value5 = flagByte;
    value3 = value5 + 8;
  }
  else {
    *value3 = flagByte;
    if (value3 + arg3 < value2) {
      *arg1 = *arg1 + arg3;
      arg1[1] = arg1[1] - arg3;
    }
    else {
      arg1[1] = 0;
      *arg1 = (int)(arg1 + 2);
    }
    value3 = value3 + 8;
  }
LAB_004b35fc:
  return (int)value3 * 0x10 + (int)arg1 * -0xf;
}

