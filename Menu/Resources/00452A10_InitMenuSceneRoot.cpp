#include "tarzan_ghidra_types.hpp"

// Address: 0x00452A10
// Label: InitMenuSceneRoot
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitMenuSceneRoot(int menu)

{
  InitLoadGamePreviewTransform(menu);
  *(undefined4 *)(menu + 0x14) = 0;
  *(undefined4 *)(menu + 0x1c) = 0;
  *(uint *)(menu + 0x54) = (uint)CONCAT11(0x82,(char)*(undefined4 *)(menu + 0x54));
  *(undefined2 *)(menu + 0xe) = 0x8100;
  *(undefined4 **)(menu + 0x100) = &g_CameraFocusX;
  *(uint *)(menu + 0x58) = *(uint *)(menu + 0x58) & 0xff;
  *(uint *)(menu + 0x5c) = *(uint *)(menu + 0x5c) & 0xff;
  *(undefined4 *)(menu + 0x18) = 0x1ec;
  return;
}

