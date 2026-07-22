#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8410
// Label: SetDirectSoundBufferVolumePercent
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetDirectSoundBufferVolumePercent(undefined4 *volumePercent,byte soundId)

{
  int value;
  int *intCursor;
  undefined4 *scratchRect2;
  undefined *scratchRect4;
  undefined1 *scratchRect3;
  int *scratchRect;
  
  if (g_DSound3DListener != 0) {
    if (100 < soundId) {
      soundId = 100;
    }
    value = (int)(char)soundId;
    _param_2 = 0;
    scratchRect = (int *)((float)value * _g_DSoundVolumePercentScale);
    if (volumePercent != (undefined4 *)0x0) {
      scratchRect3 = &soundId;
      scratchRect4 = &DAT_004ba420;
      scratchRect2 = volumePercent;
      (**(code **)*volumePercent)();
      if (scratchRect != (int *)0x0) {
        intCursor = (int *)0x0;
        (**(code **)(*scratchRect + 0x10))(scratchRect,&DAT_004ba440,1,0,0,&scratchRect2,4);
        if (intCursor != (int *)0x0) {
          (**(code **)(*intCursor + 8))(intCursor);
        }
      }
    }
  }
  return;
}

