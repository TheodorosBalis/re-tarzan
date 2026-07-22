#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8980
// Label: SetupAudioBuffers
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetupAudioBuffers(void)

{
  int value;
  undefined4 *bufferCursor;
  
  bufferCursor = &g_LoadedSoundBufferTable;
  for (value = 22000; value != 0; value = value + -1) {
    *bufferCursor = 0;
    bufferCursor = bufferCursor + 1;
  }
  bufferCursor = (undefined4 *)&g_ActiveSoundChannelMap;
  for (value = 0x10; value != 0; value = value + -1) {
    *bufferCursor = 0xffffffff;
    bufferCursor = bufferCursor + 1;
  }
  g_DSoundCoInitializeResult = 0;
  _g_DSoundCreateResult = 0;
  g_DSoundListenerCaps = 0;
  g_SoundEffectsPlaybackMuted = 0;
  g_AllSoundPlaybackSuspended = 0;
  g_SoundMixBufferWriteCursor = 0;
  g_SoundMixBufferByteSize = 0;
  g_NextFreeSoundChannelIndex = 0;
  g_PrimarySoundBuffer = 0;
  g_DSound3DListener = 0;
  g_IsDSoundInitialized = 0;
  return;
}

