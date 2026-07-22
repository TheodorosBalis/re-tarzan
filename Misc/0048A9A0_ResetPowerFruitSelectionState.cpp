#include "tarzan_ghidra_types.hpp"

// Address: 0x0048A9A0
// Label: ResetPowerFruitSelectionState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ResetPowerFruitSelectionState(void)

{
  g_PowerFruitSelectionReturnTicks = 0x1e;
  _g_PlayerPowerFruitInventoryFlags = 0;
  g_SelectedPowerFruitType = 0;
  g_PowerFruitSelectionRepeatCooldown = 0;
  *( undefined2 *)((int)&g_PowerFruitAmmoType2 + 2) = 0;
  *( undefined2 *)((int)&g_PowerFruitAmmoType2 + 0) = 0;
  g_PowerFruitAmmoType1 = 0;
  return;
}

