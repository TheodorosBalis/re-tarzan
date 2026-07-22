#include "tarzan_ghidra_types.hpp"

// Address: 0x00441940
// Label: BuildDefaultRuntimeActivationBounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildDefaultRuntimeActivationBounds(int *arg1,int *arg2)

{
  *arg1 = g_CameraFocusX + -0x1c00;
  arg1[1] = g_CameraFocusY + -0x1c00;
  arg1[2] = g_CameraFocusZ + -0x1c00;
  arg1[3] = g_CameraFocusX + 0x1c00;
  arg1[4] = g_CameraFocusY + 0x1c00;
  arg1[5] = g_CameraFocusZ + 0x1c00;
  *arg2 = g_CameraFocusX + -0x2100;
  arg2[1] = g_CameraFocusY + -0x2100;
  arg2[2] = g_CameraFocusZ + -0x2100;
  arg2[3] = g_CameraFocusX + 0x2100;
  arg2[4] = g_CameraFocusY + 0x2100;
  arg2[5] = g_CameraFocusZ + 0x2100;
  return;
}

