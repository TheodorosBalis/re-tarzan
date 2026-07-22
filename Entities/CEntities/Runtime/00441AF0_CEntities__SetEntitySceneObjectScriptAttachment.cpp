#include "tarzan_ghidra_types.hpp"

// Address: 0x00441AF0
// Label: CEntities::SetEntitySceneObjectScriptAttachment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::SetEntitySceneObjectScriptAttachment(undefined4 entry,uint *sceneObject)

{
  uint value;
  uint *dataCursor;
  
  value = sceneObject[2];
  if ((value & 0x400) == 0) {
    return (uint *)0x0;
  }
  dataCursor = (uint *)CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if ((dataCursor == (uint *)0x0) &&
     (dataCursor = (uint *)CEntities::CreateEntitySceneObjectScriptAttachment(entry),
     dataCursor == (uint *)0x0)) {
    return (uint *)0x0;
  }
  *dataCursor = *dataCursor ^ (*dataCursor ^ value) & 0xff;
  dataCursor[3] = *sceneObject;
  dataCursor[4] = sceneObject[1];
  CEntities::AdvanceScriptAttachmentSequence(dataCursor);
  return dataCursor;
}

