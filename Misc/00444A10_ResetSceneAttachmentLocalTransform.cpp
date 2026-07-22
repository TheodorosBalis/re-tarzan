#include "tarzan_ghidra_types.hpp"

// Address: 0x00444A10
// Label: ResetSceneAttachmentLocalTransform
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetSceneAttachmentLocalTransform(int arg1)

{
  *(undefined4 *)(arg1 + 0x14) = 0;
  *(undefined4 *)(arg1 + 0x18) = 0;
  *(undefined4 *)(arg1 + 0x1c) = 0;
  *(undefined4 *)(arg1 + 0x24) = 0x1000;
  return;
}

