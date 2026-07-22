#include "tarzan_ghidra_types.hpp"

// Address: 0x00415D60
// Label: ComingOfAge::UpdateAmbientSoundCue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateAmbientSoundCue(void)

{
  int value;
  int value2;
  
  g_RandomAmbientSoundCountdownTicks = g_RandomAmbientSoundCountdownTicks + -1;
  if (g_RandomAmbientSoundCountdownTicks < 1) {
    value = RandomModulo(0x58);
    g_RandomAmbientSoundCountdownTicks = value + 0x1e;
    NextRandomValue();
    value = RandomModulo(0x14);
    value2 = RandomModulo(0xb);
    value2 = RandomModulo(0xb,(float)(value2 - 5));
    value2 = RandomModulo(0xb,(float)(value2 - 5));
    PlaySoundID(CONCAT22((short)(value2 - 5U >> 0x10),
                         *(undefined2 *)(&g_RandomAmbientSoundCueIdTable + value * 4)),100,
                (float)(value2 - 5U));
  }
  return;
}

