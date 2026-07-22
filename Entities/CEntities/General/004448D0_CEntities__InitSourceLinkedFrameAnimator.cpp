#include "tarzan_ghidra_types.hpp"

// Address: 0x004448D0
// Label: CEntities::InitSourceLinkedFrameAnimator
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitSourceLinkedFrameAnimator(int entry)

{
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

