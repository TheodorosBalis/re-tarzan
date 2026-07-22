#include "tarzan_ghidra_types.hpp"

// Address: 0x00438E00
// Label: InitLoadGamePreviewScene
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitLoadGamePreviewScene(void)

{
  ResetMenuModelSet(&g_LoadGameIconSet);
  LoadNecessaryGSXFontsAndModels(&g_LoadGameIconSet);
  _g_LoadGameSelectionState = 0;
  _CurrentSelectedLevel = 0;
  InitLoadGamePreviewTransform(&g_LoadGamePreviewState);
  _g_LoadGamePreviewScene_Field00A0 = 0x400;
  _g_LoadGamePreviewScene_Field00A4 = 0x400;
  _g_LoadGamePreviewScene_Field00A8 = 0x400;
  _g_LoadGamePreviewScene_Field0054 = _g_LoadGamePreviewScene_Field0054 & 0xff;
  _g_LoadGamePreviewScene_Field0050 = (uint)CONCAT11(100,(char)_g_LoadGamePreviewScene_Field0050);
  _g_LoadGamePreviewScene_Field000C = 0;
  _g_LoadGamePreviewScene_Field0010 = 0;
  _g_LoadGamePreviewScene_Field0008 = &g_LoadGameIconSet;
  _g_LoadGamePreviewScene_Field0006 = 0x9521;
  _g_LoadGamePreviewScene_Field0028 = 0x990;
  _g_LoadGamePreviewScene_Field00F8 = &g_CameraFocusX;
  _g_LoadGamePreviewScene_Field0014 = 900;
  _g_LoadGamePreviewScene_Field00AC = 1;
  _g_LoadGamePreviewScene_Field004C =
       ((uint)(((int)(_g_LoadGamePreviewScene_Field004C & 0xff | 0x19400) >> 8) << 9) / 0x280) *
       0x100 | _g_LoadGamePreviewScene_Field004C & 0xff;
  return;
}

