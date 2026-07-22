#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8810
// Label: DoDsoundSetupStuff
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DoDsoundSetupStuff(void)

{
  uint localState10;
  undefined2 localState9;
  undefined2 localState8;
  undefined4 localState7;
  undefined4 localState6;
  undefined2 localState5;
  undefined2 localState4;
  undefined2 localState3;
  undefined4 localState2;
  undefined4 localState;
  undefined4 localState13;
  undefined4 localState12;
  undefined2 *localState11;
  
  localState9 = 1;
  localState8 = 1;
  localState11 = &localState9;
  localState10 = 0;
  g_DirectSoundPrimaryCaps = (undefined4 *)0x0;
  localState12 = 0;
  g_DirectSoundSpeakerConfig = (undefined4 *)0x0;
  g_DSound3DListener = (int *)0x0;
  localState3 = 0;
  localState7 = 0x5622;
  localState4 = 0x10;
  localState5 = 2;
  localState6 = 0xac44;
  localState2 = 0x14;
  localState = 0x12;
  localState13 = 0x80;
  if ((((g_DirectSound != (int *)0x0) &&
       ((**(code **)(*g_DirectSound + 0xc))(g_DirectSound,&localState2,&g_DirectSoundPrimaryCaps,0),
       g_DirectSoundPrimaryCaps != (undefined4 *)0x0)) &&
      ((**(code **)*g_DirectSoundPrimaryCaps)
                 (g_DirectSoundPrimaryCaps,&DAT_004ba3e0,&g_DirectSoundSpeakerConfig),
      g_DirectSoundSpeakerConfig != (undefined4 *)0x0)) &&
     (((**(code **)*g_DirectSoundSpeakerConfig)
                 (g_DirectSoundSpeakerConfig,&DAT_004ba420,&g_DSound3DListener),
      g_DSound3DListener != (int *)0x0 &&
      ((**(code **)(*g_DSound3DListener + 0x14))(g_DSound3DListener,&DAT_004ba430,0,&localState10),
      (localState10 & 2) != 0)))) {
    if (g_DSound3DListener != (int *)0x0) {
      (**(code **)(*g_DSound3DListener + 0x14))(g_DSound3DListener,&DAT_004ba440,0,&localState10);
    }
    if ((localState10 & 2) != 0) {
      return;
    }
  }
  ReleaseDirectSoundInterfaces();
  return;
}

