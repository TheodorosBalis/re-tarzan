#include "tarzan_ghidra_types.hpp"

// Address: 0x00445E30
// Label: InitPorterMenuScene
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitPorterMenuScene(void)

{
  InitMenuSceneRoot(&g_PorterMenuScene);
  _g_PorterMenuScene_Field0010 = &ModelPorter;
  _g_PorterMenuScene_Field000C = 0;
  InitMenuIdleScriptCursor(&g_SelectMovieIdleScriptCursor,&g_SelectMovieIdleScript);
  _g_PorterMenuScene_Field001C = 0xffffffe0;
  g_PorterMenuScene_Field0058 = (uint)CONCAT11(4,(char)g_PorterMenuScene_Field0058);
  return;
}

