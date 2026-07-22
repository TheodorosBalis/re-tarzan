#include "tarzan_ghidra_types.hpp"

// Address: 0x0049B220
// Label: GameCrashedLastTime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GameCrashedLastTime(void)

{
  SetOptionsMenu(0xb);
  bShouldNotProcessMore = 1;
  return;
}

