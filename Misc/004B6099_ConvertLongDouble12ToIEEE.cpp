#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6099
// Label: ConvertLongDouble12ToIEEE
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 ConvertLongDouble12ToIEEE(ushort *arg1,uint *arg2,int *arg3)

{
  ushort value3;
  int value;
  uint value4;
  int value2;
  undefined4 value5;
  undefined1 localState2 [12];
  uint localState;
  uint localState4;
  int localState3;
  
  value3 = arg1[5];
  localState = *(uint *)(arg1 + 3);
  localState4 = *(uint *)(arg1 + 1);
  value4 = value3 & 0x7fff;
  value2 = value4 - 0x3fff;
  localState3 = (uint)*arg1 << 0x10;
  if (value2 == -0x3fff) {
    value2 = 0;
    value = IsUInt96Zero(&localState);
    if (value != 0) {
LAB_004b61c5:
      value5 = 0;
      goto LAB_004b61c7;
    }
    ZeroUInt96(&localState);
  }
  else {
    CopyUInt96(localState2,&localState);
    value = RoundAndTruncateUInt96(&localState,arg3[2]);
    if (value != 0) {
      value2 = value4 - 0x3ffe;
    }
    value = arg3[1];
    if (value2 < value - arg3[2]) {
      ZeroUInt96(&localState);
    }
    else {
      if (value < value2) {
        if (*arg3 <= value2) {
          ZeroUInt96(&localState);
          localState = localState | 0x80000000;
          ShiftUInt96Right(&localState,arg3[3]);
          value2 = arg3[5] + *arg3;
          value5 = 1;
          goto LAB_004b61c7;
        }
        localState = localState & 0x7fffffff;
        value2 = arg3[5] + value2;
        ShiftUInt96Right(&localState,arg3[3]);
        goto LAB_004b61c5;
      }
      CopyUInt96(&localState,localState2);
      ShiftUInt96Right(&localState,value - value2);
      RoundAndTruncateUInt96(&localState,arg3[2]);
      ShiftUInt96Right(&localState,arg3[3] + 1);
    }
  }
  value2 = 0;
  value5 = 2;
LAB_004b61c7:
  localState = value2 << (0x1fU - (char)arg3[3] & 0x1f) |
             -(uint)((value3 & 0x8000) != 0) & 0x80000000 | localState;
  if (arg3[4] == 0x40) {
    arg2[1] = localState;
    *arg2 = localState4;
  }
  else if (arg3[4] == 0x20) {
    *arg2 = localState;
  }
  return value5;
}

