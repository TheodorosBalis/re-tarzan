#include "tarzan_ghidra_types.hpp"

// Address: 0x00438B80
// Label: FinalizeLevelTransitionAndInvokeHook
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FinalizeLevelTransitionAndInvokeHook(void)

{
  _g_RockinTheBoatLevelStateTable = 1;
  CPlayerHero::InitializeForLevel();
  EnterGameplayRuntimeState();
  if (*(code **)(g_CurrentLevelRuntimeHookTable + 0xc) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00438ba0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(g_CurrentLevelRuntimeHookTable + 0xc))();
    return;
  }
  return;
}

