#include "tarzan_ghidra_types.hpp"

// Address: 0x00438C00
// Label: CMenu::LoadGame_ReleaseResources
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::LoadGame_ReleaseResources(void)

{
  ReleaseResourceSet(&g_LoadGameIconSet);
  return;
}

