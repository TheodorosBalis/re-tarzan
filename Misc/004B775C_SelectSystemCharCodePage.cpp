#include "tarzan_ghidra_types.hpp"

// Address: 0x004B775C
// Label: SelectSystemCharCodePage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int SelectSystemCharCodePage(int arg1)

{
  int value;
  bool flagByte;
  
  if (arg1 == -2) {
    g_CrtCodePageAutoSelectMode = 1;
                    /* WARNING: Could not recover jumptable at 0x004b7776. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    value = GetOEMCP();
    return value;
  }
  if (arg1 == -3) {
    g_CrtCodePageAutoSelectMode = 1;
                    /* WARNING: Could not recover jumptable at 0x004b778b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    value = GetACP();
    return value;
  }
  flagByte = arg1 == -4;
  if (flagByte) {
    arg1 = g_CrtLocaleCodePage;
  }
  g_CrtCodePageAutoSelectMode = (uint)flagByte;
  return arg1;
}

