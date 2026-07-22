#include "tarzan_ghidra_types.hpp"

// Address: 0x0047F110
// Label: AdvanceMenuIdleScriptCursor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void AdvanceMenuIdleScriptCursor(int *menu,int menuItem)

{
  uint value;
  uint value2;
  uint *dataCursor;
  uint *dataCursor2;
  
  dataCursor2 = (uint *)*menu;
  if (dataCursor2 == (uint *)0x0) {
    *menu = menu[1];
    return;
  }
  value = *dataCursor2;
  if ((value & 0x80000000) == 0) {
    *menu = (int)(dataCursor2 + 1);
    *(short *)(menuItem + 0xc) = (short)value;
    return;
  }
  do {
    if (value == 0x80000001) {
      dataCursor = dataCursor2 + 2;
      PlayAudioById(dataCursor2[1],(int *)0,(undefined4 *)0);
LAB_0047f168:
      value2 = *dataCursor;
      dataCursor2 = dataCursor + 1;
    }
    else {
      if (value == 0xc0000002) {
        dataCursor = (uint *)dataCursor2[1];
        goto LAB_0047f168;
      }
      value2 = value;
      if (value == 0xc0000003) {
        value2 = (uint)*(ushort *)(menuItem + 0xc);
      }
    }
    if (((value & 0x40000000) != 0) && (dataCursor = (uint *)menu[1], dataCursor != (uint *)0x0)) {
      menu[1] = 0;
      value2 = *dataCursor;
      dataCursor2 = dataCursor;
    }
    value = value2;
    if ((value2 & 0x80000000) == 0) {
      *menu = (int)dataCursor2;
      *(short *)(menuItem + 0xc) = (short)value2;
      return;
    }
  } while( true );
}

