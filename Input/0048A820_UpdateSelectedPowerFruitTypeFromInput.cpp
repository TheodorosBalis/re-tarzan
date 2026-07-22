#include "tarzan_ghidra_types.hpp"

// Address: 0x0048A820
// Label: UpdateSelectedPowerFruitTypeFromInput
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateSelectedPowerFruitTypeFromInput(void)

{
  if (g_HudPowerFruitSelectorScene != 0) {
    if ((g_GameplayRuntimeFlags & 0x200) == 0) {
      g_PlayerEdgeBalanceInputMask = 0;
      g_PowerFruitNextInputMask = 0x20000;
    }
    else {
      g_PlayerEdgeBalanceInputMask = 0x10000;
      g_PowerFruitNextInputMask = 0;
    }
    if ((g_GameplayRuntimeFlags & 0x400) != 0) {
      g_PlayerPowerFruitInventoryFlags = g_PlayerPowerFruitInventoryFlags | 0x10;
      *( undefined2 *)((int)&g_PowerFruitAmmoType2 + 2) = 99;
      *( undefined2 *)((int)&g_PowerFruitAmmoType2 + 0) = 99;
      g_PowerFruitAmmoType1 = 99;
    }
    if (g_PowerFruitSelectionRepeatCooldown != 0) {
      g_PowerFruitSelectionRepeatCooldown = g_PowerFruitSelectionRepeatCooldown + -1;
      g_InputPreviousMask = g_InputPreviousMask & ~(g_PowerFruitNextInputMask | 0x40000);
    }
    if (((g_PlayerInputPressedMask & 0x40000) != 0) && (g_PowerFruitSelectionRepeatCooldown == 0)) {
      g_SelectedPowerFruitType = g_SelectedPowerFruitType + -1;
      g_PowerFruitSelectionRepeatCooldown = 7;
      g_PowerFruitPickupFlashTicks = 0;
      if (g_SelectedPowerFruitType < 0) {
        g_SelectedPowerFruitType = 3;
      }
      g_PowerFruitSelectionReturnTicks = 0x1e;
      PlayAudioById(0xc0,(int *)0,(undefined4 *)0);
    }
    if (((g_PlayerInputPressedMask & g_PowerFruitNextInputMask) != 0) &&
       (g_PowerFruitSelectionRepeatCooldown == 0)) {
      g_PowerFruitSelectionRepeatCooldown = 7;
      g_SelectedPowerFruitType = g_SelectedPowerFruitType + 1;
      g_PowerFruitPickupFlashTicks = 0;
      if (3 < g_SelectedPowerFruitType) {
        g_SelectedPowerFruitType = 0;
      }
      g_PowerFruitSelectionReturnTicks = 0x1e;
      PlayAudioById(0xc0,(int *)0,(undefined4 *)0);
    }
    if (g_SelectedPowerFruitType != 0) {
      if ((&g_PowerFruitAmmoType0)[g_SelectedPowerFruitType] != 0) {
        g_SelectedThrowablePowerFruitType = (int)g_SelectedPowerFruitType;
        return;
      }
      g_SelectedThrowablePowerFruitType = 0;
      if (g_PowerFruitSelectionReturnTicks != 0) {
        g_PowerFruitSelectionReturnTicks = g_PowerFruitSelectionReturnTicks + -1;
        return;
      }
      g_SelectedPowerFruitType = 0;
      return;
    }
    g_SelectedThrowablePowerFruitType = 0;
  }
  return;
}

