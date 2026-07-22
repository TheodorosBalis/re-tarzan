#include "tarzan_ghidra_types.hpp"

// Address: 0x00441C80
// Label: CEntities::UpdateScriptedEntitySceneObjectAttachment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::UpdateScriptedEntitySceneObjectAttachment(uint *entry)

{
  uint value;
  uint *dataCursor;
  undefined4 value2;
  
  if (((*entry & 0x500) == 0x500) && (value = entry[0xe], value != 0)) {
    dataCursor = (uint *)CEntities::FindEntityAttachmentByFlags(entry,0x400);
    if (dataCursor != (uint *)0x0) {
      if ((*dataCursor & 0xff) == 1) {
        value2 = CEntities::UpdateEntitySceneObjectScript(entry,value,dataCursor);
        return value2;
      }
      if ((*dataCursor & 0xff) == 2) {
        value2 = CEntities::PlayTimedScriptedEntitySceneObjectEffect(entry,value,dataCursor);
        return value2;
      }
    }
  }
  return 1;
}

