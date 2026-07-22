#include "tarzan_ghidra_types.hpp"

// Address: 0x0040A950
// Label: InitSceneAnchorTransform
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitSceneAnchorTransform(undefined4 *arg1,undefined4 arg2)

{
  int entry;
  
  g_CameraBlendTargetPose = 0;
  arg1[0x31] = arg2;
  *(undefined2 *)(arg1 + 0x14) = 0;
  *(undefined2 *)((int)arg1 + 0x52) = 0;
  *(undefined2 *)(arg1 + 0x15) = 0;
  *arg1 = 0;
  arg1[1] = 0;
  arg1[2] = 0;
  arg1[0x16] = 0x1000;
  arg1[0x17] = 0x1000;
  arg1[0x18] = 0x1000;
  arg1[5] = 0x300;
  arg1[8] = 0x140;
  *(undefined2 *)((int)arg1 + 0x56) = 0;
  arg1[0x19] = 0;
  InitSceneAnchorTransformViewportFromRect(arg1);
  entry = arg1[0x16] * 4 * arg1[8];
  arg1[3] = 0;
  arg1[4] = 0;
  arg1[0x2d] = 0;
  arg1[0x2e] = 0;
  arg1[0x2f] = 0;
  *(undefined2 *)(arg1 + 0xc) = 0;
  *(undefined2 *)((int)arg1 + 0x32) = 0;
  *(undefined2 *)(arg1 + 0xd) = 0;
  arg1[0xe] = 0;
  arg1[0xf] = 0;
  arg1[0x10] = 0;
  arg1[5] = (int)(entry + (entry >> 0x1f & 0xfffU)) >> 0xc;
  arg1[0x2c] = 0x1000;
  return;
}

