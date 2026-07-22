#include "tarzan_ghidra_types.hpp"

// Address: 0x00444AC0
// Label: CEntities::ReleaseEntitySceneObjectAttachedSound
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::ReleaseEntitySceneObjectAttachedSound(int entry)

{
  DetachEntitySoundHandle(entry + 0x104);
  return;
}

