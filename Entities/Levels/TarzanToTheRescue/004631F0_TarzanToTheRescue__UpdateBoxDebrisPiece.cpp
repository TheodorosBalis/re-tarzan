#include "tarzan_ghidra_types.hpp"

// Address: 0x004631F0
// Label: TarzanToTheRescue::UpdateBoxDebrisPiece
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateBoxDebrisPiece(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    *(short *)(entity->sceneObjects + 0xa2) = *(short *)(value + 0x18) + 0xc00;
    if (*(int *)(value + 0xc) == 0) {
      *(int *)(entity->sceneObjects + 0x30) = *(int *)(entity->sceneObjects + 0x30) + 0x100;
      if (0x800 < *(int *)(entity->sceneObjects + 0x30)) {
        *(undefined4 *)(value + 0xc) = 1;
      }
    }
    else if (*(int *)(value + 0xc) == 1) {
      *(int *)(entity->sceneObjects + 0x14) =
           *(int *)(entity->sceneObjects + 0x14) +
           ((int)(short)(&g_SinCosTable12Bit)[*(int *)(value + 0x18) - 0x400U & 0xfff] *
            *(int *)(value + 0x14) >> 0xc);
      *(int *)(entity->sceneObjects + 0x1c) =
           *(int *)(entity->sceneObjects + 0x1c) +
           ((int)(short)(&g_SinCosTable12Bit)[*(uint *)(value + 0x18) & 0xfff] *
            *(int *)(value + 0x14) >> 0xc);
      *(int *)(entity->sceneObjects + 0xa8) = *(int *)(entity->sceneObjects + 0xa8) + 0x20;
      *(int *)(entity->sceneObjects + 0xac) = *(int *)(entity->sceneObjects + 0xac) + 0x20;
      *(int *)(entity->sceneObjects + 0xb0) = *(int *)(entity->sceneObjects + 0xb0) + 0x20;
      *(int *)(entity->sceneObjects + 0x30) = *(int *)(entity->sceneObjects + 0x30) + -100;
      if (*(int *)(entity->sceneObjects + 0x30) < 0) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
    }
  }
  return;
}

