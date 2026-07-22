#include "tarzan_ghidra_types.hpp"

// Address: 0x00440350
// Label: CreateEntityEntitySceneObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CreateEntityEntitySceneObject(uint *arg1,uint arg2)

{
  uint *dataCursor;
  undefined4 *dataCursor2;
  int entry;
  uint *dataCursor3;
  undefined4 *dataCursor4;
  undefined4 *dataCursor5;
  
  dataCursor2 = (undefined4 *)
           CEntities::AllocEntityAttachment
                     (arg1,0x144,arg2 | 0x100,&g_HudEntitySceneObjectTemplate);
  if (dataCursor2 != (undefined4 *)0x0) {
    *arg1 = *arg1 | 0x100;
    dataCursor4 = &g_HudEntitySceneObjectTemplate;
    dataCursor5 = dataCursor2;
    for (entry = 0x51; entry != 0; entry = entry + -1) {
      *dataCursor5 = *dataCursor4;
      dataCursor4 = dataCursor4 + 1;
      dataCursor5 = dataCursor5 + 1;
    }
    dataCursor3 = (uint *)arg1[0xe];
    if (dataCursor3 == (uint *)0x0) {
      arg1[0xe] = (uint)dataCursor2;
      return 0;
    }
    for (dataCursor = (uint *)dataCursor3[2]; dataCursor != (uint *)0x0; dataCursor = (uint *)dataCursor[2]) {
      if ((*dataCursor & 0x100) != 0) {
        dataCursor3[0xd] = (uint)dataCursor;
        dataCursor3 = dataCursor;
      }
    }
  }
  return 0;
}

