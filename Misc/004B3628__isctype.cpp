#include "tarzan_ghidra_types.hpp"

// Address: 0x004B3628
// Label: _isctype
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint __thiscall _isctype(undefined4 arg1,int arg2,uint arg3)

{
  int value;
  undefined4 value2;
  undefined4 localState;
  
  if (arg2 + 1U < 0x101) {
    *( undefined2 *)((int)&arg2 + 2) = *(ushort *)(g_CrtCtypeTable + arg2 * 2);
  }
  else {
    if ((g_CrtCtypeTable[(arg2 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      localState = CONCAT31((int3)((uint)arg1 >> 8),(char)arg2) & 0xffff00ff;
      value2 = 1;
    }
    else {
      *( undefined2 *)((int)&localState + 0) = CONCAT11((char)arg2,(char)((uint)arg2 >> 8));
      localState = CONCAT22((short)((uint)arg1 >> 0x10),(undefined2)localState) & 0xff00ffff;
      value2 = 2;
    }
    value = ConvertCPandUpdateBuffer(1,&localState,value2,(int)&arg2 + 2,0,0,1);
    if (value == 0) {
      return 0;
    }
  }
  return *( undefined2 *)((int)&arg2 + 2) & arg3;
}

