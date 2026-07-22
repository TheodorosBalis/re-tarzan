#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A450
// Label: ReleaseTarzanFsdArchive
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseTarzanFsdArchive(void)

{
  if (g_TarzanFsdArchiveHandle != 0) {
    fclose(g_TarzanFsdArchiveHandle);
  }
  g_TarzanFsdArchiveHandle = 0;
  g_TarzanFsdInitAttempted = 0;
  return;
}

