#include "tarzan_ghidra_types.hpp"

// Address: 0x0043FB70
// Label: CMenu::EnterSelectMovieMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::EnterSelectMovieMenu(void)

{
  RemoveMainMenuSelections();
  RemoveOptionsGraphicsBlocks();
  HideMenuGraphicBlock(&LoadGame_SelectLevelLabels);
  func_0x0043f790();
  _g_SelectMovieState = 0;
  _g_SelectedMovieIndex = 0;
  InitLoadGamePreviewTransform(0x531320);
  _g_SelectMoviePreviewScene_Field00A8 = 0x400;
  _g_SelectMoviePreviewScene_Field00AC = 0x400;
  _g_SelectMoviePreviewScene_Field00B0 = 0x400;
  _g_SelectMoviePreviewScene_Field005C = _g_SelectMoviePreviewScene_Field005C & 0xff;
  _g_SelectMoviePreviewScene_Field0058 =
       (uint)CONCAT11(0x5c,(char)_g_SelectMoviePreviewScene_Field0058);
  _g_SelectMoviePreviewScene_Field0010 = &g_SelectMovieIconSet;
  _g_SelectMoviePreviewScene_Field0054 =
       ((uint)(((int)(_g_SelectMoviePreviewScene_Field0054 & 0xff | 0x19400) >> 8) << 9) / 0x280) *
       0x100 | _g_SelectMoviePreviewScene_Field0054 & 0xff;
  _g_SelectMoviePreviewScene_Field000E = 0x9521;
  _g_SelectMoviePreviewScene_Field0030 = 0x990;
  _g_SelectMoviePreviewScene_Field0100 = &g_CameraFocusX;
  _g_SelectMoviePreviewScene_Field0014 = 0;
  _g_SelectMoviePreviewScene_Field001C = 900;
  _g_SelectMoviePreviewScene_Field00B4 = 1;
  _g_SelectMoviePreviewScene_Field0018 = 0;
  InitSceneAnchorTransform(&g_CameraFocusX,*(undefined4 *)(g_ActiveMenuContext + 0x1c));
  InitMenuIdleScriptCursor(&DAT_0051d0f8,&DAT_004ed200);
  return;
}

