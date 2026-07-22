#include "tarzan_ghidra_types.hpp"

// Address: 0x00439030
// Label: UpdateJaneMenuIdleScript
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateJaneMenuIdleScript(void)

{
  int menuIndex;
  
  g_CameraEyeDistanceFromFocus = 0x280;
  AdvanceMenuIdleScriptCursor(&DAT_0051d0f8,&g_JaneMenuScene);
  menuIndex = RandomModulo(0x15e);
  if (menuIndex == 0) {
    menuIndex = RandomModulo(8);
    SetMenuIdleScriptOverride(&DAT_0051d0f8,(&g_JaneMenuRandomIdleScriptTable)[menuIndex]);
  }
  if (_g_JaneMenuIdleScript_Field0004 == 0) {
    SetMenuIdleScriptOverride(&DAT_0051d0f8,&DAT_004ed200);
  }
  return;
}

