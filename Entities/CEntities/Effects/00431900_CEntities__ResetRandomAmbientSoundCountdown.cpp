#include "tarzan_ghidra_types.hpp"

// Address: 0x00431900
// Label: CEntities::ResetRandomAmbientSoundCountdown
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::ResetRandomAmbientSoundCountdown(void)

{
  uint soundMask;
  
  soundMask = NextRandomValue();
  g_RandomAmbientSoundCountdownTicks = soundMask & 0x7f;
  return;
}

