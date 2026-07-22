#include "tarzan_ghidra_types.hpp"

// Address: 0x0044DCF0
// Label: RestoreCameraAfterSaborBattle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RestoreCameraAfterSaborBattle(void)

{
  int value;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  
  g_CameraFollowMode = g_SavedCameraFollowModeBeforeSaborBattle;
  SelectBackgroundMusicTrackForLevel(0);
  dataCursor = &g_CameraFocusX;
  dataCursor2 = &g_CameraUpdateTargetPose;
  for (value = 0x32; value != 0; value = value + -1) {
    *dataCursor2 = *dataCursor;
    dataCursor = dataCursor + 1;
    dataCursor2 = dataCursor2 + 1;
  }
  g_OptionalHudMeterScene = 0;
  CCamera::ProjectForwardPoint(&g_CameraUpdateTargetPose,&g_CameraUpdateEyePoint);
  return;
}

