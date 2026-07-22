#include "tarzan_ghidra_types.hpp"

// Address: 0x00454000
// Label: CMenu::PauseMenu_RequestExitToWorldMap
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::PauseMenu_RequestExitToWorldMap(void)

{
  *( undefined1 *)((int)&g_GameplayStateFlags + 0) = (byte)g_GameplayStateFlags | 8;
  *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = (ushort)g_LevelTransitionRequestFlags | 0x8002;
  return;
}

