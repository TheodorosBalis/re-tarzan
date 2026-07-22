#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8010
// Label: GetPlayingSoundChannelMask
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint GetPlayingSoundChannelMask(void)

{
  uint mask;
  byte flagByte;
  uint mask2;
  short *value;
  
  flagByte = 0;
  mask = 0;
  value = &g_ActiveSoundChannelMap;
  do {
    if (*value == -1) {
      mask2 = 0;
    }
    else {
      mask2 = 1 << (flagByte & 0x1f);
    }
    mask = mask | mask2;
    value = value + 2;
    flagByte = flagByte + 1;
  } while ((int)value < 0x9e4a20);
  return mask;
}

