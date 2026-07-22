#include "tarzan_ghidra_types.hpp"

// Address: 0x004ACB00
// Label: ReleaseSoundIdList
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseSoundIdList(short *soundIdList)

{
  short *value;
  short shortValue;
  
  shortValue = *soundIdList;
  while (shortValue != -1) {
    ReleaseLoadedSoundById(shortValue);
    value = soundIdList + 1;
    soundIdList = soundIdList + 1;
    shortValue = *value;
  }
  return;
}

