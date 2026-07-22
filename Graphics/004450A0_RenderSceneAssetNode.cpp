#include "tarzan_ghidra_types.hpp"

// Address: 0x004450A0
// Label: RenderSceneAssetNode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderSceneAssetNode(ushort *graphicsObject)

{
  uint value;
  int entry;
  
  value = (uint)*graphicsObject;
  if ((value & 0x7000) == 0x5000) {
    entry = *(int *)(*(int *)(graphicsObject + 2) + 0xc);
    entry = ResolveSceneAssetRelativePointerEntry
                      (*(int *)(entry + 0x10) + (value & 0xfff) * 8 + 0x14 + entry);
    if (entry != 0) {
      RenderSceneAssetIfVisible(entry,graphicsObject[1]);
      return;
    }
  }
  else {
    entry = *(int *)(*(int *)(graphicsObject + 2) + 0xc);
    if ((int)(value & 0xfff) < *(int *)(entry + 0x30)) {
      RenderSceneAssetIfVisible((value & 0xfff) * 0x30 + 0x34 + entry,graphicsObject[1]);
    }
  }
  return;
}

