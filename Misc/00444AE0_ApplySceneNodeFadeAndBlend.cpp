#include "tarzan_ghidra_types.hpp"

// Address: 0x00444AE0
// Label: ApplySceneNodeFadeAndBlend
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ApplySceneNodeFadeAndBlend(int arg1,int arg2,undefined4 arg3)

{
  if ((*(ushort *)(arg1 + 2) & 1) == 0) {
    g_RenderBlendMode = 0;
  }
  else {
    g_RenderBlendMode = (byte)*(ushort *)(arg1 + 2) >> 5 & 3;
  }
  if (arg2 != 0x1000) {
    if ((*(byte *)(arg1 + 3) & 4) != 0) {
      _g_SceneNodeScaledFadeVectorX = *(int *)(arg1 + 0x14) * arg2 >> 0xc;
      _g_SceneNodeScaledFadeVectorY = *(int *)(arg1 + 0x18) * arg2 >> 0xc;
      _g_SceneNodeScaledFadeVectorZ = *(int *)(arg1 + 0x1c) * arg2 >> 0xc;
      SetFadeBrightnessAndTint
                (*(int *)(arg1 + 0x24) * arg2 >> 0xc,&g_SceneNodeScaledFadeVectorX);
      return;
    }
    SetFadeBrightnessAndTint(arg2,arg3);
    return;
  }
  if ((*(byte *)(arg1 + 3) & 4) != 0) {
    SetFadeBrightnessAndTint(*(undefined4 *)(arg1 + 0x24),arg1 + 0x14);
    return;
  }
  SetFadeBrightnessAndTint(0x1000,0);
  return;
}

