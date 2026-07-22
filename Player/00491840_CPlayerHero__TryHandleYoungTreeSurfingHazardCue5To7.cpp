#include "tarzan_ghidra_types.hpp"

// Address: 0x00491840
// Label: CPlayerHero::TryHandleYoungTreeSurfingHazardCue5To7
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CPlayerHero::TryHandleYoungTreeSurfingHazardCue5To7(int arg1)

{
  if (arg1 == 5) {
    if (g_PlayerLateralSurfaceOffset < 3) {
      CPlayerHero::TriggerYoungTreeSurfingHazardDamage();
    }
  }
  else if (arg1 == 6) {
    if ((-3 < g_PlayerLateralSurfaceOffset) && (g_PlayerLateralSurfaceOffset < 3)) {
      CPlayerHero::TriggerYoungTreeSurfingHazardDamage();
      return 1;
    }
  }
  else {
    if (arg1 != 7) {
      return 0;
    }
    if (-3 < g_PlayerLateralSurfaceOffset) {
      CPlayerHero::TriggerYoungTreeSurfingHazardDamage();
      return 1;
    }
  }
  return 1;
}

