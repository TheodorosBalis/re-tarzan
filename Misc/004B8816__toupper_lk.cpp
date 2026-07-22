#include "tarzan_ghidra_types.hpp"

// Address: 0x004B8816
// Label: _toupper_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint _toupper_lk(uint arg1)

{
  uint value2;
  uint value3;
  int value;
  undefined4 value4;
  uint localState;
  
  value2 = arg1;
  if (g_CrtMultibyteLocaleActive == 0) {
    if ((0x60 < (int)arg1) && ((int)arg1 < 0x7b)) {
      value2 = arg1 - 0x20;
    }
  }
  else {
    if ((int)arg1 < 0x100) {
      if (g_CrtLocaleEnabled < 2) {
        value3 = (byte)g_CrtCtypeTable[arg1 * 2] & 2;
      }
      else {
        value3 = _isctype(arg1,2);
      }
      if (value3 == 0) {
        return value2;
      }
    }
    if ((g_CrtCtypeTable[((int)value2 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      arg1 = CONCAT31((int3)(arg1 >> 8),(char)value2) & 0xffff00ff;
      value4 = 1;
    }
    else {
      value3 = arg1 >> 0x10;
      *( undefined2 *)((int)&arg1 + 0) = CONCAT11((char)value2,(char)(value2 >> 8));
      arg1 = CONCAT22((short)value3,(undefined2)arg1) & 0xff00ffff;
      value4 = 2;
    }
    value = ReturnLengthOfConvertedString
                      (g_CrtMultibyteLocaleActive,0x200,&arg1,value4,&localState,3,0,1);
    if (value != 0) {
      if (value == 1) {
        value2 = localState & 0xff;
      }
      else {
        value2 = localState & 0xffff;
      }
    }
  }
  return value2;
}

