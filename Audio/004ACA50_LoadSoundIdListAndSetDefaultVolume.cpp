#include "tarzan_ghidra_types.hpp"

// Address: 0x004ACA50
// Label: LoadSoundIdListAndSetDefaultVolume
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadSoundIdListAndSetDefaultVolume(short *volumePercent)

{
  short *value;
  short shortValue;
  undefined2 upperWord;
  undefined2 upperWord2;
  
  shortValue = *volumePercent;
  while (shortValue != -1) {
    InitSoundAndNewGameStateFile(shortValue);
    ProcessSoundOnGameStateUpdate(CONCAT22(upperWord,*volumePercent),0,100);
    SetSoundPlaybackVolume(CONCAT22(upperWord2,*volumePercent),0,0x32);
    value = volumePercent + 1;
    volumePercent = volumePercent + 1;
    shortValue = *value;
  }
  return;
}

