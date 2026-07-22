#include "tarzan_ghidra_types.hpp"

// Address: 0x004987E0
// Label: OpenMenuEgfAndIndexChunks
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int OpenMenuEgfAndIndexChunks(undefined4 menu)

{
  int menuIndex;
  
  ResetMenuEgfState();
  g_MenuEgfHandle = OpenVirtualGameFileByPath(menu,&s_FileModeReadBinary);
  if ((g_MenuEgfHandle != 0) &&
     (ReadVirtualGameFileIntoBuffer(&g_MenuEgfHeader,0x48,1,g_MenuEgfHandle),
     g_MenuEgfHeader == 0x2464745)) {
    g_MenuEgfChunkCount = 0;
    menuIndex = 0x48;
    do {
      if ((&g_MenuEgfChunkSizes)[g_MenuEgfChunkCount] == 0) {
        return g_MenuEgfChunkCount;
      }
      (&g_MenuEgfChunkOffsets)[g_MenuEgfChunkCount] = menuIndex;
      menuIndex = menuIndex + (&g_MenuEgfChunkSizes)[g_MenuEgfChunkCount];
      g_MenuEgfChunkCount = g_MenuEgfChunkCount + 1;
    } while (g_MenuEgfChunkCount < 0x10);
    return g_MenuEgfChunkCount;
  }
  ResetMenuEgfState();
  return 0;
}

