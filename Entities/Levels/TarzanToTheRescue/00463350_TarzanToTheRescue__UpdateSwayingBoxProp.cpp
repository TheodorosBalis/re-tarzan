#include "tarzan_ghidra_types.hpp"

// Address: 0x00463350
// Label: TarzanToTheRescue::UpdateSwayingBoxProp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateSwayingBoxProp(int entry)

{
  Entity *entity = (Entity *)entry;
  if (*(int *)(entry + 0x50) == 0) {
    *(short *)(entity->sceneObjects + 0xa4) =
         (short)((short)(&g_SinCosTable12Bit)[*(int *)(entry + 0x4c) - 0x400U & 0xfff] * 200 >>
                0xc);
  }
  if (*(int *)(entry + 0x50) == 1) {
    *(short *)(entity->sceneObjects + 0xa2) =
         (short)(((int)(short)(&g_SinCosTable12Bit)[*(int *)(entry + 0x4c) - 0x400U & 0xfff] << 7)
                >> 0xc);
    *(short *)(entity->sceneObjects + 0xa4) =
         (short)((short)(&g_SinCosTable12Bit)[*(uint *)(entry + 0x4c) & 0xfff] * 200 >> 0xc);
  }
  if (*(short *)(entity->sceneObjects + 0xa4) == 0) {
    PlayAudioById(0x388,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
  }
  *(uint *)(entry + 0x4c) = *(int *)(entry + 0x4c) + 0x20U & 0xfff;
  return;
}

