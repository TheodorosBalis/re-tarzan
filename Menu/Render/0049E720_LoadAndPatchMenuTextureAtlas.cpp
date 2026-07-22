#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E720
// Label: LoadAndPatchMenuTextureAtlas
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __fastcall LoadAndPatchMenuTextureAtlas(undefined4 menu)

{
  float value;
  short *value2;
  int menuIndex;
  
  OpenMenuEgfAndIndexChunks(s_t__win_grafix_menu_egf_00517588,menu);
  LoadMenuEgfChunkToTextureAtlas(0,&g_MenuTextureAtlasPixels);
  ResetMenuEgfState();
  value2 = &g_MenuTextureAtlasPixels;
  do {
    if ((*value2 == 0x3e0) || (*value2 == 0x1f)) {
      *value2 = 0;
    }
    value2 = value2 + 1;
  } while ((int)value2 < 0x79e7b0);
  UpdateTexturesReference(0xf,0,0,0x100,0x100);
  menuIndex = 0;
  do {
    value = (float)menuIndex;
    menuIndex = menuIndex + 1;
    FillMenuTextureColorRampSpan(menuIndex,0xda,0,8,0,0,0,0,value,0);
    FillMenuTextureColorRampSpan(menuIndex,0xe1,0,8,0,value,0,0,0,0);
  } while (menuIndex < 0x20);
  UpdateTexturesReference(0xf,0,0,0x100,0x100);
  return;
}

