#include "tarzan_ghidra_types.hpp"

// Address: 0x0043FA20
// Label: CMenu::SelectMovie_Render
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::SelectMovie_Render(undefined4 menu)

{
  int menuIndex;
  
  ReleasePalettedTextureBlockIfUnused(0x50df3c,0);
  ReleasePalettedTextureBlockIfUnused(0x4ef1a4,0);
  if ((-1 < _g_SelectMovieState) && (_g_SelectMovieState < 3)) {
    menuIndex = _g_SelectedMovieIndex * 0x1c;
    if ((*(int *)(&g_SelectMovieEntryRequiredFlagIndex + menuIndex) == -1) ||
       (((g_GameplayRuntimeFlags & 0x10000) != 0 ||
        (((&g_SelectMovieEntryRequiredFlagMask)[menuIndex] &
         *(byte *)((int)&g_RuntimeCompletionFlagsByLevel +
                  *(int *)(&g_SelectMovieEntryRequiredFlagIndex + menuIndex))) != 0)))) {
      _g_SelectMoviePreviewCurrentPoseId =
           *(undefined2 *)(&g_SelectMovieEntryUnlockedPreviewPoseTable + menuIndex);
    }
    else {
      _g_SelectMoviePreviewCurrentPoseId =
           *(undefined2 *)(&g_SelectMovieEntryLockedPreviewPoseTable + menuIndex);
    }
    RenderSceneHierarchy(0x531320);
    g_CameraEyeDistanceFromFocus = 0x280;
    RenderSceneHierarchy(&g_JaneMenuScene);
    RenderMenuUiBlockEntry(0x4ef1a4,&DAT_00533bd8,3,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
    RenderMenuUiBlockEntry(0x4ef1a4,&DAT_00533bd8,1,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
    RenderMenuUiBlockEntry
              (0x50df3c,&DAT_00533bd8,
               *(undefined4 *)(&g_SelectMovieEntryPrimaryImageIndexTable + menuIndex),
               *(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
    if (*(int *)(&g_SelectMovieEntrySecondaryImageIndexTable + menuIndex) != -1) {
      RenderMenuUiBlockEntry
                (0x50df3c,&DAT_00533bd8,
                 *(int *)(&g_SelectMovieEntrySecondaryImageIndexTable + menuIndex),
                 *(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
    }
    RenderMenuFontBlockAndChildText(menu);
  }
  return;
}

