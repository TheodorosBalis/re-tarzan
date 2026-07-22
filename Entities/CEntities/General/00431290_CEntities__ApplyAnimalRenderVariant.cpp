#include "tarzan_ghidra_types.hpp"

// Address: 0x00431290
// Label: CEntities::ApplyAnimalRenderVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::ApplyAnimalRenderVariant(undefined4 entry,int sceneObject,int attachment)

{
  if (attachment == 99) {
    attachment = RandomModulo(3);
  }
  if (attachment == 1) {
    *(byte *)(sceneObject + 0xf) = *(byte *)(sceneObject + 0xf) | 2;
    *(undefined4 *)(sceneObject + 0x70) = 1;
  }
  else if (attachment == 2) {
    *(byte *)(sceneObject + 0xf) = *(byte *)(sceneObject + 0xf) | 2;
    *(undefined4 *)(sceneObject + 0x70) = 2;
    return;
  }
  return;
}

