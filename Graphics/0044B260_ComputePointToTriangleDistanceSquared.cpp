#include "tarzan_ghidra_types.hpp"

// Address: 0x0044B260
// Label: ComputePointToTriangleDistanceSquared
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ComputePointToTriangleDistanceSquared(int *arg1,short *arg2)

{
  int value;
  uint value16;
  int value10;
  int value11;
  int value12;
  uint value17;
  int value13;
  int value14;
  int value15;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value7;
  int value8;
  int value9;
  int localState;
  
  value3 = (int)*arg2;
  value7 = (int)arg2[2];
  value13 = (int)arg2[1];
  value10 = arg2[6] - value7;
  value12 = arg2[4] - value3;
  value8 = arg2[8] - value3;
  value2 = arg2[5] - value13;
  value4 = arg2[9] - value13;
  value = arg2[10] - value7;
  value3 = value3 - *arg1;
  value13 = value13 - arg1[1];
  value7 = value7 - arg1[2];
  value14 = value * value + value4 * value4 + value8 * value8;
  value5 = value * value10 + value4 * value2 + value8 * value12;
  value11 = value10 * value10 + value2 * value2 + value12 * value12;
  value4 = value7 * value + value13 * value4 + value3 * value8;
  value9 = value4 >> 2;
  value15 = value14 >> 2;
  value6 = value5 >> 2;
  value8 = value11 >> 2;
  value10 = value7 * value10 + value13 * value2 + value3 * value12;
  value = value10 >> 2;
  localState = (value11 >> 10) * (value14 >> 10) - (value5 >> 10) * (value5 >> 10);
  value5 = value5 >> 6;
  if (localState == 0) {
    localState = (value11 >> 6) * (value14 >> 6) - value5 * value5;
    if (localState == 0) {
      return 0x7ffffff;
    }
    value11 = (value * value6 - value9 * value8) / localState;
    value10 = value * value15;
    value4 = value9 * value6;
  }
  else {
    value10 = value10 >> 6;
    value4 = value4 >> 6;
    value11 = (value10 * value5 - (value11 >> 6) * value4) / localState;
    value10 = (value14 >> 6) * value10;
    value4 = value4 * value5;
  }
  localState = (value4 - value10) / localState;
  if (0xff < localState + value11) {
    if (value11 < 0) {
      value4 = ((value9 - value) - value8) + value6;
      if (-1 < value4) {
        if (value + value8 < 1) {
          value11 = 0;
          localState = 0xff;
          goto LAB_0044b640;
        }
        value11 = 0;
        localState = -((value << 8) / value8);
        if (localState < 0) {
          localState = 0;
          goto LAB_0044b640;
        }
        goto LAB_0044b4d1;
      }
      value11 = (value4 * -0x100) / (value8 + value6 * -2 + value15);
      if (value11 < 0) {
        value11 = 0;
      }
      else {
joined_r0x0044b632:
        if (0xff < value11) {
          value11 = 0xff;
        }
      }
    }
    else {
      if (localState < 0) {
        value4 = ((value9 - value) - value6) + value15;
        if (0 < value4) {
          localState = (value4 * 0x100) / (value8 + value6 * -2 + value15);
          if (localState < 0) {
            localState = 0;
            value11 = 0xff;
          }
          else {
            if (0xff < localState) {
              localState = 0xff;
            }
            value11 = 0xff - localState;
          }
          goto LAB_0044b640;
        }
        if (value9 + value15 < 1) {
          value11 = 0xff;
          localState = 0;
          goto LAB_0044b640;
        }
        goto LAB_0044b5e8;
      }
      value11 = ((((value - value9) - value6) + value8) * 0x100) / (value8 + value6 * -2 + value15);
      if (-1 < value11) goto joined_r0x0044b632;
      value11 = 0;
    }
    localState = 0xff - value11;
    goto LAB_0044b640;
  }
  if (value11 < 0) {
    if (localState < 0) {
      if (value9 < 0) {
        value11 = -((value9 << 8) / value15);
        goto LAB_0044b466;
      }
      if (-1 < value) {
        value11 = 0;
        localState = 0;
        goto LAB_0044b640;
      }
      localState = -((value << 8) / value8);
    }
    else {
      value11 = 0;
      localState = -((value << 8) / value8);
      if (localState < 0) {
        localState = 0;
        goto LAB_0044b640;
      }
    }
LAB_0044b4d1:
    value11 = 0;
    if (0xff < localState) {
      localState = 0xff;
    }
  }
  else {
    if (-1 < localState) goto LAB_0044b640;
LAB_0044b5e8:
    localState = 0;
    value11 = -((value9 << 8) / value15);
    if (value11 < 0) {
      value11 = 0;
      goto LAB_0044b640;
    }
LAB_0044b466:
    localState = 0;
    if (0xff < value11) {
      value11 = 0xff;
    }
  }
LAB_0044b640:
  value16 = (((localState * value6 >> 8) + (value11 * value15 >> 8) + value9 * 2) * value11 >> 8) +
          (value7 * value7 + value13 * value13 + value3 * value3 >> 2) +
          (((localState * value8 >> 8) + (value11 * value6 >> 8) + value * 2) * localState >> 8);
  value17 = (int)value16 >> 0x1f;
  return ((value16 ^ value17) - value17) * 4;
}

