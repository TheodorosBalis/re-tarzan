#include "tarzan_ghidra_types.hpp"

// Address: 0x00453FA0
// Label: LoadFonts
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadFonts(int arg1)

{
  g_ActiveTransitionPayload = 0;
  InitModelLoadHeap(&g_ModelLoadHeapState,&DAT_00a43a24,0x200000);
  ResetModelLoadQueue();
  ResetMenuTextureAtlasAndFontState_stub(*(undefined4 *)(arg1 + 4));
  ResetMenuInputState();
  ResetEntitySoundSlotLists();
  LoadLanguageFontAssetSet();
  return;
}

