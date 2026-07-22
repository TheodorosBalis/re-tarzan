#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC730
// Label: RefreshAudioListenerAndChannelMask
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RefreshAudioListenerAndChannelMask(void)

{
  g_ActiveAudioChannelMask = GetPlayingSoundChannelMask();
  UpdateRenderCameraState(&g_CameraFocusX);
  SetTransformBasisFromRef(&DAT_0051c530);
  return;
}

