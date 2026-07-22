#include "tarzan_ghidra_types.hpp"

// Address: 0x00440510
// Label: CEntities::CreateEntitySceneObjectScriptAttachment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::CreateEntitySceneObjectScriptAttachment(uint *entry2)

{
  undefined4 *dataCursor;
  int entry;
  undefined4 *dataCursor2;
  
  dataCursor = (undefined4 *)
           CEntities::AllocEntityAttachment(entry2,0x20,0x400,&g_EntityScriptAttachmentTemplate);
  if (dataCursor != (undefined4 *)0x0) {
    *entry2 = *entry2 | 0x400;
    dataCursor2 = &g_EntityScriptAttachmentTemplate;
    for (entry = 8; entry != 0; entry = entry + -1) {
      *dataCursor = *dataCursor2;
      dataCursor2 = dataCursor2 + 1;
      dataCursor = dataCursor + 1;
    }
  }
  return 0;
}

