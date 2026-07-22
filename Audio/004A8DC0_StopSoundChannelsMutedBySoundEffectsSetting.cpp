#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8DC0
// Label: StopSoundChannelsMutedBySoundEffectsSetting
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StopSoundChannelsMutedBySoundEffectsSetting(void)

{
  int channelIndex;
  char resultFlag;
  
  resultFlag = '\0';
  do {
    channelIndex = IsSoundAllowedWhenSoundEffectsMuted(0xffffffff,resultFlag);
    if (channelIndex == 0) {
      StopSoundChannelByIndex(0xffffffff,resultFlag);
    }
    resultFlag = resultFlag + '\x01';
  } while (resultFlag < '\x10');
  return;
}

