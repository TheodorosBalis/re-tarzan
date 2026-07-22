#include "tarzan_ghidra_types.hpp"

// Address: 0x0045E800
// Label: CMenu::LevelComplete_Enter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::LevelComplete_Enter(void)

{
  uint value;
  int menuIndex;
  int menuIndex2;
  uint *dataCursor;
  int *menuEntry;
  
  if (((byte)g_GameplayRuntimeFlags & 1) != 0) {
    g_CollectedTARZANLetterMask6 = 0x3f;
  }
  LoadMenuGraphicBlock(&g_LevelCompleteGraphicBlock);
  BuildLoadGameHeaderGraphics();
  _g_LoadGameMenuEntryFlag = 1;
  g_CurrentMenu = 0;
  g_NextMenu = &g_MenuDescriptor_LevelComplete;
  InitSceneAnchorTransform(&g_CameraFocusX,*(undefined4 *)(g_ActiveMenuContext + 0x1c));
  g_CameraEyeDistanceFromFocus = 900;
  menuEntry = (int *)&g_LevelCompleteSlotLayoutTableA;
  if (g_LevelCompleteInputMode != 0) {
    menuEntry = &g_LevelCompleteSlotLayoutTableB;
  }
  dataCursor = &g_LevelCompleteRewardEntitySceneObjects;
  menuIndex2 = 0x14;
  do {
    InitLoadGamePreviewTransform(dataCursor + -0x15);
    value = menuEntry[4];
    *(short *)((int)dataCursor + -0x46) = (short)menuEntry[5];
    if ((value & 0x7000) == 0x3000) {
      *dataCursor = *dataCursor & 0xff;
      dataCursor[1] = dataCursor[1] & 0xff;
      menuIndex = *menuEntry;
      dataCursor[2] = dataCursor[2] & 0xff;
      dataCursor[-0x10] = dataCursor[-0x10] & 0xff | menuIndex << 8;
      dataCursor[-0xf] = menuEntry[1] << 8 | dataCursor[-0xf] & 0xff;
      dataCursor[-0xe] = menuEntry[2];
    }
    else {
      menuIndex = menuEntry[1];
      value = menuEntry[2];
      *dataCursor = *menuEntry << 8 | *dataCursor & 0xff;
      dataCursor[-0x10] = 0;
      dataCursor[1] = menuIndex << 8 | dataCursor[1] & 0xff;
      dataCursor[2] = dataCursor[2] & 0xff;
      dataCursor[-0xf] = 0;
      dataCursor[-0xe] = value;
    }
    value = menuEntry[3];
    *(short *)(dataCursor + -0x12) = (short)menuEntry[4];
    dataCursor[0x2b] = (uint)&g_CameraFocusX;
    dataCursor[-0x11] = value;
    *(undefined2 *)((int)dataCursor + 0x52) = 0;
    dataCursor[0x18] = 1;
    dataCursor = dataCursor + 0x51;
    menuEntry = menuEntry + 6;
    menuIndex2 = menuIndex2 + -1;
  } while (menuIndex2 != 0);
  menuIndex2 = 0;
  do {
    CMenu::LevelComplete_InitRewardSlot(menuIndex2);
    menuIndex2 = menuIndex2 + 1;
  } while (menuIndex2 < 6);
  g_AllSketchPiecesNewlyCompleted =
       g_AllSketchPiecesNewlyCompleted == '\0' && (g_CollectedSketchPieceMask4 & 0xf) == 0xf;
  CMenu::LevelComplete_SetEntitySceneObjectTripletBatch(&g_LevelCompleteRewardBurstScenes,4,0x800);
  _g_LevelCompleteState = (uint)(g_LevelCompleteInputMode == 0);
  _g_LevelCompleteStartingLevelIndex = (int)*( undefined1 *)((int)&g_LevelTransitionContext + 3);
  g_TotalTokensCollected = (uint)gCurrentTokensCollected;
  g_LevelCompleteStateTimer = 0x20;
  g_LevelCompleteDisplayedScore = 0;
  g_LevelCompleteRewardSlotDoneMask = 0;
  g_LevelCompleteFastForwardRequested = 0;
  _g_LevelCompleteRewardBurstSystem = 0;
  g_LevelCompleteHundredsSfxCounter = _g_LevelCompleteStartingLevelIndex;
  CMenu::LevelComplete_CommitProgressAndAdvanceLevel();
  return;
}

