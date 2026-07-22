#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9FF0
// Label: SetProjectionTranslationFromTransform
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetProjectionTranslationFromTransform(int arg1)

{
  _g_ProjectTranslateX = (float)*(int *)(arg1 + 0x14);
  _g_ProjectTranslateY = (float)*(int *)(arg1 + 0x18);
  _g_ProjectTranslateZ = (float)*(int *)(arg1 + 0x1c);
  return;
}

