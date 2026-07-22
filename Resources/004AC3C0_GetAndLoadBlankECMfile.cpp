#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC3C0
// Label: GetAndLoadBlankECMfile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

char * GetAndLoadBlankECMfile(int arg1)

{
  int value;
  char *stringCursor;
  
  stringCursor = s_blank_ecm_005179ec;
  if (-1 < arg1) {
    stringCursor = (&g_EcmFilenameTable)[arg1];
  }
  value = _access(stringCursor,0);
  if (value == 0) {
    return stringCursor;
  }
  stringCursor = (char *)LoadECMfile(stringCursor);
  return stringCursor;
}

