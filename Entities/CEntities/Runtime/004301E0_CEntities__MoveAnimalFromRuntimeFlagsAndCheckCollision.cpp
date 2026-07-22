#include "tarzan_ghidra_types.hpp"

// Address: 0x004301E0
// Label: CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined1
CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision
          (int entry,undefined4 sceneObject,int attachment,int flags)

{
  ushort stateFlags;
  undefined1 stateFlags2;
  
  stateFlags = *(ushort *)(entry + 0x4a);
  if ((stateFlags & 0x20) == 0) {
    if (((stateFlags & 2) != 0) || (attachment = flags, (stateFlags & 1) != 0)) goto LAB_0043021e;
  }
  else {
    if ((stateFlags & 2) != 0) {
      attachment = -attachment;
      goto LAB_0043021e;
    }
    if ((stateFlags & 1) != 0) {
      attachment = -flags;
      goto LAB_0043021e;
    }
  }
  attachment = 0;
LAB_0043021e:
  CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,attachment);
  stateFlags2 = CEntities::CheckEntitySceneObjectCollisionDelta(sceneObject);
  return stateFlags2;
}

