#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A1B0
// Label: ParseEdlCompressionHeader
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ParseEdlCompressionHeader(int arg1)

{
  if (((**(char **)(arg1 + 4) == 'E') && (*(char *)(*(int *)(arg1 + 4) + 1) == 'D')) &&
     (*(char *)(*(int *)(arg1 + 4) + 2) == 'L')) {
    *(int *)(arg1 + 0x18) = (int)(uint)*(byte *)(*(int *)(arg1 + 4) + 3) >> 7;
    *(uint *)(arg1 + 0x10) = *(byte *)(*(int *)(arg1 + 4) + 3) & 0x7f;
    if ((*(int *)(arg1 + 0x10) < 0) || (1 < *(int *)(arg1 + 0x10))) {
      *(undefined4 *)(arg1 + 0x1c) = 0xfffffffc;
    }
    else {
      *(undefined4 *)(arg1 + 0x1c) = 0;
      *(undefined4 *)(arg1 + 8) = *(undefined4 *)(*(int *)(arg1 + 4) + 4);
      *(undefined4 *)(arg1 + 0xc) = *(undefined4 *)(*(int *)(arg1 + 4) + 8);
    }
  }
  else {
    *(undefined4 *)(arg1 + 0x1c) = 0xfffffffd;
  }
  return;
}

