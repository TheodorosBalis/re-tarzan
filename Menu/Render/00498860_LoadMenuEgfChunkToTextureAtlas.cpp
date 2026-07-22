#include "tarzan_ghidra_types.hpp"

// Address: 0x00498860
// Label: LoadMenuEgfChunkToTextureAtlas
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadMenuEgfChunkToTextureAtlas(int menu,int menuItem)

{
  int menuIndex;
  
  if (((g_MenuEgfHandle != 0) && (-1 < menu)) && (menu < g_MenuEgfChunkCount)) {
    menuIndex = (menuItem - (&g_MenuEgfChunkSizes)[menu]) + 0x20000;
    SeekVirtualGameFileHandle(g_MenuEgfHandle,(&g_MenuEgfChunkOffsets)[menu],0);
    ReadVirtualGameFileIntoBuffer(menuIndex,(&g_MenuEgfChunkSizes)[menu],1,g_MenuEgfHandle);
    DecodeMenuEgfRleTexture256x256(menuItem,menuIndex);
  }
  return;
}

