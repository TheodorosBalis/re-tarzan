#include "tarzan_ghidra_types.hpp"

// Address: 0x004A81B0
// Label: FindNextFreeSoundChannel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint FindNextFreeSoundChannel(void)

{
  short channelIndex;
  uint soundMask;
  int foundIndex;
  
  soundMask = (int)g_NextFreeSoundChannelIndex + 1U & 0x8000000f;
  if ((int)soundMask < 0) {
    soundMask = (soundMask - 1 | 0xfffffff0) + 1;
  }
  foundIndex = (int)(char)soundMask;
  channelIndex = (&g_ActiveSoundChannelMap)[foundIndex * 2];
  while( true ) {
    if (channelIndex == -1) {
      g_NextFreeSoundChannelIndex = (char)soundMask;
      return soundMask;
    }
    if ((char)soundMask == g_NextFreeSoundChannelIndex) break;
    soundMask = foundIndex + 1U & 0x8000000f;
    if ((int)soundMask < 0) {
      soundMask = (soundMask - 1 | 0xfffffff0) + 1;
    }
    foundIndex = (int)(char)soundMask;
    channelIndex = (&g_ActiveSoundChannelMap)[foundIndex * 2];
  }
  return CONCAT31((int3)(soundMask >> 8),0xff);
}

