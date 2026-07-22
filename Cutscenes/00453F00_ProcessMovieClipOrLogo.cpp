#include "tarzan_ghidra_types.hpp"

// Address: 0x00453F00
// Label: ProcessMovieClipOrLogo
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
ProcessMovieClipOrLogo(uint arg1,undefined4 arg2,undefined4 arg3,undefined4 arg4)

{
  if (arg1 != 0xffffffff) {
    if ((arg1 & 0xc000) == 0x4000) {
      SetActiveMenuContext(&g_MenuSceneContext);
      ProcessLevelLogo((&g_LevelLogoPointerTable)[arg1 & 0xffff3fff]);
      WaitForLogoSkipInput(arg2,arg3,arg4);
    }
    else if ((arg1 & 0xc000) == 0x8000) {
      LoadAndHandleECM(arg1 & 0xffff3fff,0);
      return 0;
    }
  }
  return 0;
}

