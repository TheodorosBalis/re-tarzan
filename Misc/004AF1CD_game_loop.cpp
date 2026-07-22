#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF1CD
// Label: game_loop
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void game_loop(void)

{
  do {
    ProcessGameLogic();
    ProcessGameLogic();
    WinMessageLoop();
  } while( true );
}

