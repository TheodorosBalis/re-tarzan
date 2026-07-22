#include "tarzan_ghidra_types.hpp"

// Address: 0x0049CE70
// Label: ForceSoftwareGraphicsMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ForceSoftwareGraphicsMode(void)

{
  RequestGraphicsModeChange(5);
  ApplyRequestedGraphicsModeWithFallback();
  DoReconfigurationStuffOnWindow();
  ShutdownDirect3DGraphicsMode();
  ShutdownDirectDrawGraphicsMode();
  g_CurrentGraphicsMode = 0;
  return;
}

