#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0122
// Label: _cinit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _cinit(void)

{
  if (SetupVfTableAndCPUcheck != (undefined *)0x0) {
    (*(code *)SetupVfTableAndCPUcheck)();
  }
  _initterm(&DAT_004bc024,&DAT_004bc030);
  _initterm(&DAT_004bc000,&DAT_004bc020);
  return;
}

