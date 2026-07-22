#include "tarzan_ghidra_types.hpp"

// Address: 0x0047EDF7
// Label: LoadAndLaunchTarzanIntroCutscene
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 LoadAndLaunchTarzanIntroCutscene(void)

{
  RemoveOptionsGraphicsBlocks();
  RemoveMainMenuSelections();
  HideLoadGameHeaderGraphics();
  LoadAndHandleECM(0x8010,0);
  SetActiveMenuContext(&g_MenuSceneContext);
  BuildLoadGameHeaderGraphics();
  BuildMainMenuSelections();
  BuildOptionsGraphicsBlocks();
  SelectBackgroundMusicTrackForLevel(0);
  InitiateFade(1,0x200);
  Empty_menu_stub(&DAT_00c46070);
  MenuState = 0;
  return 1;
}

