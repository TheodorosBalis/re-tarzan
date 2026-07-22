#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A580
// Label: NormalizeVirtualGamePath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined1 * NormalizeVirtualGamePath(byte *arg1)

{
  byte *value3;
  byte flagByte;
  uint value2;
  int value;
  
  if ((arg1 == (byte *)0x0) || (*arg1 == 0)) {
    return (undefined1 *)0x0;
  }
  value2 = 0;
  value = (int)&g_NormalizedVirtualPath - (int)arg1;
  do {
    if (0x3fe < value2) break;
    flagByte = *arg1;
    if ((0x60 < flagByte) && (flagByte < 0x7b)) {
      flagByte = flagByte - 0x20;
    }
    arg1[value] = flagByte;
    value3 = arg1 + 1;
    value2 = value2 + 1;
    arg1 = arg1 + 1;
  } while (*value3 != 0);
  (&g_NormalizedVirtualPath)[value2] = 0;
  if ((((g_NormalizedVirtualPath == '\0') || (g_NormalizedVirtualPathChar0 != ':')) ||
      (g_NormalizedVirtualPathChar1 != '\\')) || (g_NormalizedVirtualPathChar2 == '\0')) {
    InternalError(s_Partial_filename_00515c1c);
  }
  return &g_NormalizedVirtualPath;
}

