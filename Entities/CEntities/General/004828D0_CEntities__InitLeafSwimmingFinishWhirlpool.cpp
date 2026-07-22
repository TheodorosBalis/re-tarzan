#include "tarzan_ghidra_types.hpp"

// Address: 0x004828D0
// Label: CEntities::InitLeafSwimmingFinishWhirlpool
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitLeafSwimmingFinishWhirlpool(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value = CEntities::CreateEntityAttachment(entry,0x40,0x10000000);
  if (value != 0) {
    *(undefined4 *)(value + 0xc) = 0;
    *(undefined4 *)(value + 0x10) = 0;
    *(undefined4 *)(value + 0x14) = 500;
    *(undefined4 *)(value + 0x2c) = 0x60;
    *(undefined4 *)(value + 0x30) = 0;
    *(undefined4 *)(value + 0x34) = 0;
    *(undefined4 *)(value + 0x38) = 0;
    *(undefined4 *)(value + 0x3c) = 0;
  }
  g_LeafSwimmingWhirlpoolSoundVariant = g_LeafSwimmingWhirlpoolSoundVariant + 1;
  if (2 < g_LeafSwimmingWhirlpoolSoundVariant) {
    g_LeafSwimmingWhirlpoolSoundVariant = 0;
  }
  PlayAudioById((&g_LeafSwimmingWhirlpoolSoundIdTable)[g_LeafSwimmingWhirlpoolSoundVariant],(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
  return;
}

