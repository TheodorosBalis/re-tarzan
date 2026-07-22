#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8930
// Label: ReleaseDirectSoundInterfaces
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseDirectSoundInterfaces(void)

{
  if (g_DSound3DListener != (int *)0x0) {
    (**(code **)(*g_DSound3DListener + 8))(g_DSound3DListener);
  }
  if (g_DirectSoundSpeakerConfig != (int *)0x0) {
    (**(code **)(*g_DirectSoundSpeakerConfig + 8))(g_DirectSoundSpeakerConfig);
  }
  if (g_DirectSoundPrimaryCaps != (int *)0x0) {
    (**(code **)(*g_DirectSoundPrimaryCaps + 8))(g_DirectSoundPrimaryCaps);
  }
  g_DirectSoundPrimaryCaps = (int *)0x0;
  g_DirectSoundSpeakerConfig = (int *)0x0;
  g_DSound3DListener = (int *)0x0;
  return;
}

