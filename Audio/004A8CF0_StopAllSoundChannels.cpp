#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8CF0
// Label: StopAllSoundChannels
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StopAllSoundChannels(void)

{
  char resultFlag;
  
  resultFlag = '\0';
  do {
    StopSoundChannelByIndex(0xffffffff,resultFlag);
    resultFlag = resultFlag + '\x01';
  } while (resultFlag < '\x10');
  return;
}

