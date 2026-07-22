#include "tarzan_ghidra_types.hpp"

// Address: 0x00479E00
// Label: CPlayerHero::EnterTerkEdgeBalance
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkEdgeBalance(void)

{
  int value;
  
  if (g_CurrentSwingEntity != 0) {
    value = CEntities::FindEntityAttachmentByFlags(g_CurrentSwingEntity,0x8000000);
    if (value != 0) {
      *(undefined2 *)(value + 0xe) = 8;
    }
  }
  *g_PlayerEntitySceneObjectData = 0;
  g_PlayerBalanceWobbleTimer = 0;
  g_PlayerBalanceWobbleAmount = 0x20;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x100;
  return;
}

