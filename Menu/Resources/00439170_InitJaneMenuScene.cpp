#include "tarzan_ghidra_types.hpp"

// Address: 0x00439170
// Label: InitJaneMenuScene
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitJaneMenuScene(void)

{
  InitMenuSceneRoot(&g_JaneMenuScene);
  g_JaneMenuScene_Field0050 = (uint)CONCAT11(0xbe,(char)g_JaneMenuScene_Field0050);
  g_JaneMenuScene_Field0054 = g_JaneMenuScene_Field0054 & 0xff;
  _g_JaneMenuScene_Field0008 = &ModelJane;
  _g_JaneMenuScene_Field0004 = 0;
  _g_JaneMenuScene_Field009E = 0;
  _g_JaneMenuScene_Field0010 = 0x80;
  _g_JaneMenuScene_Field0014 = 0x40;
  _g_JaneMenuScene_Field009A = 0;
  InitMenuIdleScriptCursor(&DAT_0051d0f8,&DAT_004ed280);
  g_CameraEyeDistanceFromFocus = 0x280;
  return;
}

