#include "tarzan_ghidra_types.hpp"

// Address: 0x004405C0
// Label: CEntities::FindEntityAttachmentByFlags
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::FindEntityAttachmentByFlags(int entry,uint sceneObject)

{
  uint *stateFlags;
  
  stateFlags = *(uint **)(entry + 8);
  do {
    if (stateFlags == (uint *)0x0) {
      return (uint *)0x0;
    }
    if ((sceneObject & 0xffffff00 & *stateFlags) != 0) {
      if ((sceneObject & 0xff) == 0) {
        return stateFlags;
      }
      if ((*stateFlags & 0xff) == (sceneObject & 0xff)) {
        return stateFlags;
      }
    }
    stateFlags = (uint *)stateFlags[2];
  } while( true );
}

