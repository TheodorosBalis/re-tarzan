#include "tarzan_ghidra_types.hpp"

// Address: 0x004ACAD0
// Label: ClearSoundIdListPersistent
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ClearSoundIdListPersistent(short *soundIdList)

{
  short *value;
  short shortValue;
  
  shortValue = *soundIdList;
  while (shortValue != -1) {
    ClearLoadedSoundPersistent(shortValue);
    value = soundIdList + 1;
    soundIdList = soundIdList + 1;
    shortValue = *value;
  }
  return;
}

