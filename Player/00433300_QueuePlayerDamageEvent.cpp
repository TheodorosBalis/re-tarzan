#include "tarzan_ghidra_types.hpp"

// Address: 0x00433300
// Label: QueuePlayerDamageEvent
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int QueuePlayerDamageEvent(undefined4 arg1,uint arg2)

{
  uint value;
  
  if (g_HudHealthBarEnabled != '\0') {
    if ((arg2 & 0x100) == 0) {
      value = (uint)*(ushort *)
                     (&g_PlayerDamageAmountByLevelAndTypeTable +
                     ((arg2 & 0xf) * 3 + (int)*( undefined1 *)((int)&g_LevelTransitionContext + 1)) * 2);
    }
    else {
      value = arg2 & 0xff;
    }
    if ((arg2 & 0x200) != 0) {
      value = 0x7ff;
      g_PlayerDamageInvulnerabilityTicks = 0;
    }
    if ((_g_PendingPlayerDamage & 0xffff) < value) {
      _g_PendingPlayerDamage = CONCAT22(g_PendingPlayerDamage_2,(short)value);
      *( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) = (undefined2)arg2;
      g_PendingPlayerDamageSourceEntity = arg1;
    }
  }
  return 0;
}

