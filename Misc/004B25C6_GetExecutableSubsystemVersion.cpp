#include "tarzan_ghidra_types.hpp"

// Address: 0x004B25C6
// Label: GetExecutableSubsystemVersion
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GetExecutableSubsystemVersion(undefined4 *arg1)

{
  int value;
  HMODULE value2;
  
  *arg1 = 0;
  value2 = GetModuleHandleA((LPCSTR)0x0);
  if (((short)value2->unused == 0x5a4d) && (value = value2[0xf].unused, value != 0)) {
    *(undefined1 *)arg1 = *(undefined1 *)((int)&value2[6].unused + value + 2);
    *(undefined1 *)((int)arg1 + 1) = *(undefined1 *)((int)&value2[6].unused + value + 3);
  }
  return;
}

