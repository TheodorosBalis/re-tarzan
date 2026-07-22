#include "tarzan_ghidra_types.hpp"

// Address: 0x004B2EEE
// Label: __sbh_alloc_new_group
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int __sbh_alloc_new_group(int arg1)

{
  int *intCursor;
  char resultFlag;
  int value;
  int value2;
  int value3;
  LPVOID value6;
  int *intCursor2;
  int value4;
  int value5;
  int *lpAddress;
  
  value = *(int *)(arg1 + 0x10);
  value5 = 0;
  for (value2 = *(int *)(arg1 + 8); -1 < value2; value2 = value2 << 1) {
    value5 = value5 + 1;
  }
  value4 = 0x3f;
  value2 = value5 * 0x204 + 0x144 + value;
  value3 = value2;
  do {
    *(int *)(value3 + 8) = value3;
    *(int *)(value3 + 4) = value3;
    value3 = value3 + 8;
    value4 = value4 + -1;
  } while (value4 != 0);
  lpAddress = (int *)(value5 * 0x8000 + *(int *)(arg1 + 0xc));
  value6 = VirtualAlloc(lpAddress,0x8000,0x1000,4);
  if (value6 == (LPVOID)0x0) {
    value5 = -1;
  }
  else {
    if (lpAddress <= lpAddress + 0x1c00) {
      intCursor2 = lpAddress + 4;
      do {
        intCursor2[-2] = -1;
        intCursor2[0x3fb] = -1;
        intCursor2[-1] = 0xff0;
        *intCursor2 = (int)(intCursor2 + 0x3ff);
        intCursor2[1] = (int)(intCursor2 + -0x401);
        intCursor2[0x3fa] = 0xff0;
        intCursor = intCursor2 + 0x3fc;
        intCursor2 = intCursor2 + 0x400;
      } while (intCursor <= lpAddress + 0x1c00);
    }
    *(int **)(value2 + 0x1fc) = lpAddress + 3;
    lpAddress[5] = value2 + 0x1f8;
    *(int **)(value2 + 0x200) = lpAddress + 0x1c03;
    lpAddress[0x1c04] = value2 + 0x1f8;
    *(undefined4 *)(value + 0x44 + value5 * 4) = 0;
    *(undefined4 *)(value + 0xc4 + value5 * 4) = 1;
    resultFlag = *(char *)(value + 0x43);
    *(char *)(value + 0x43) = resultFlag + '\x01';
    if (resultFlag == '\0') {
      *(uint *)(arg1 + 4) = *(uint *)(arg1 + 4) | 1;
    }
    *(uint *)(arg1 + 8) = *(uint *)(arg1 + 8) & ~(0x80000000U >> ((byte)value5 & 0x1f));
  }
  return value5;
}

