#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8EF0
// Label: SetAudioLineVolumePercent
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetAudioLineVolumePercent(undefined4 *volumePercent,undefined4 soundId)

{
  int *localState;
  
  localState = (int *)0x0;
  if (volumePercent != (undefined4 *)0x0) {
    (**(code **)*volumePercent)(volumePercent,&DAT_004ba3e0,&localState);
  }
  SetDirectSoundBufferVolumePercent(localState,soundId);
  if (localState != (int *)0x0) {
    (**(code **)(*localState + 8))(localState);
  }
  return;
}

