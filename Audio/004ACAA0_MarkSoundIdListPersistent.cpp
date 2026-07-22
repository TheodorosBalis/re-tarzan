#include "tarzan_ghidra_types.hpp"

// Address: 0x004ACAA0
// Label: MarkSoundIdListPersistent
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void MarkSoundIdListPersistent(short *soundIdList)

{
  short *value;
  short shortValue;
  
  shortValue = *soundIdList;
  while (shortValue != -1) {
    MarkLoadedSoundPersistent(shortValue);
    value = soundIdList + 1;
    soundIdList = soundIdList + 1;
    shortValue = *value;
  }
  return;
}

