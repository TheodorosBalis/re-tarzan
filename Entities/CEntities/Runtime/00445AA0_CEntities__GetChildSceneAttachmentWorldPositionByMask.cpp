#include "tarzan_ghidra_types.hpp"

// Address: 0x00445AA0
// Label: CEntities::GetChildSceneAttachmentWorldPositionByMask
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::GetChildSceneAttachmentWorldPositionByMask
              (undefined4 entry2,undefined4 sceneObject,undefined4 attachment)

{
  int entry;
  
  entry = CEntities::ResolveChildSceneObjectArrayFromRef(entry2);
  if (entry != 0) {
    entry = FindSceneAttachmentByMask(entry,sceneObject);
    if (entry != 0) {
      CEntities::TransformChildSceneObjectLocalPointToWorld(entry,entry2,attachment);
      return entry;
    }
  }
  return 0;
}

