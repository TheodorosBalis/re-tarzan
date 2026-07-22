#include "tarzan_ghidra_types.hpp"

// Address: 0x00438F96
// Label: FadeAfterAudioLineEnded
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FadeAfterAudioLineEnded(void)

{
  CMenu::RequestMenuChangeWithFade(&g_MainMenuMainFontMenuEntry);
  return;
}

