#include "tarzan_ghidra_types.hpp"

// Address: 0x004462A0
// Label: ResetHudSpriteQuadList
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetHudSpriteQuadList(void)

{
  int value;
  int *intCursor;
  
  value = g_WorldEntitySceneObjectArrayBase + 0x68;
  intCursor = &g_HudSpriteQuadListFirstSceneRef;
  do {
    intCursor[-1] = 0;
    *intCursor = value;
    intCursor[1] = 0x3016;
    intCursor[2] = 0;
    intCursor[3] = 0;
    intCursor[4] = 0;
    intCursor[5] = 0;
    intCursor[8] = 0;
    intCursor[9] = 0;
    intCursor[10] = 0;
    intCursor[0xb] = 0;
    *(undefined2 *)(intCursor + 6) = 0;
    *(undefined2 *)((int)intCursor + 0x1a) = 0;
    *(undefined2 *)(intCursor + 7) = 0;
    *(undefined2 *)((int)intCursor + 0x1e) = 0;
    intCursor[0xc] = 0;
    intCursor = intCursor + 0xe;
  } while ((int)intCursor < 0x53270c);
  return;
}

