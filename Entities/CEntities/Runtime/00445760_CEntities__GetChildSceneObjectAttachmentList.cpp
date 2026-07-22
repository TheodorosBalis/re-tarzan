#include "tarzan_ghidra_types.hpp"

// Address: 0x00445760
// Label: CEntities::GetChildSceneObjectAttachmentList
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::GetChildSceneObjectAttachmentList(undefined4 entry,int *sceneObject)

{
  short *value;
  
  value = (short *)CEntities::ResolveChildSceneObjectArrayFromRef(entry);
  if ((value != (short *)0x0) && (value[1] != 0)) {
    *sceneObject = (int)(value + *value * 4 + 2);
    return (int)value[1];
  }
  return 0;
}

