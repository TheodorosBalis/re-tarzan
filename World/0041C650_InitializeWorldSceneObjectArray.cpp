#include "tarzan_ghidra_types.hpp"

// Address: 0x0041C650
// Label: InitializeWorldSceneObjectArray
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitializeWorldSceneObjectArray(int arg1,int arg2)

{
  _g_WorldSceneObjectArrayInitState_Field0008 = 0;
  _g_WorldSceneObjectArrayInitState_Field0004 = arg2;
  g_WorldEntitySceneObjectArrayBase = arg1;
  for (; arg2 != 0; arg2 = arg2 + -1) {
    ResetMenuModelSet(arg1);
    arg1 = arg1 + 0x68;
  }
  return;
}

