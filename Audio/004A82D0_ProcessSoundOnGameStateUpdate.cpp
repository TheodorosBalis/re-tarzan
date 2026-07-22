#include "tarzan_ghidra_types.hpp"

// Address: 0x004A82D0
// Label: ProcessSoundOnGameStateUpdate
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ProcessSoundOnGameStateUpdate(ushort soundId,byte position,byte outParams)

{
  short state;
  int *intCursor;
  int *intCursor2;
  int value;
  
  if (100 < outParams) {
    outParams = 100;
  }
  if (soundId < 2000) {
    value = 4;
    intCursor2 = &g_LoadedSoundBufferTable + (short)soundId * 0xb;
    do {
      intCursor = (int *)*intCursor2;
      if (intCursor != (int *)0x0) {
        (**(code **)(*intCursor + 0x3c))(intCursor,(int)(short)(&g_DSoundVolumeCurve)[(char)outParams]);
      }
      intCursor2 = intCursor2 + 1;
      value = value + -1;
    } while (value != 0);
  }
  else if (position < 0x10) {
    state = (&g_ActiveSoundChannelMap)[(char)position * 2];
    if (((state != -1) && ((&g_LoadedSoundBufferTable)[state * 0xb] != 0)) &&
       (intCursor2 = (int *)(&g_LoadedSoundBufferTable)
                        [(int)(short)(&g_ActiveSoundChannelVariantIndex)[(char)position * 2] +
                         state * 0xb], intCursor2 != (int *)0x0)) {
      (**(code **)(*intCursor2 + 0x3c))(intCursor2,(int)(short)(&g_DSoundVolumeCurve)[(char)outParams]);
      return;
    }
  }
  return;
}

