#include "tarzan_ghidra_types.hpp"

// Address: 0x004B8F40
// Label: strpbrk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

byte * strpbrk(byte *arg1,byte *arg2)

{
  byte flagByte;
  byte *value;
  byte localState [32];
  
  localState[0x1c] = 0;
  localState[0x1d] = 0;
  localState[0x1e] = 0;
  localState[0x1f] = 0;
  localState[0x18] = 0;
  localState[0x19] = 0;
  localState[0x1a] = 0;
  localState[0x1b] = 0;
  localState[0x14] = 0;
  localState[0x15] = 0;
  localState[0x16] = 0;
  localState[0x17] = 0;
  localState[0x10] = 0;
  localState[0x11] = 0;
  localState[0x12] = 0;
  localState[0x13] = 0;
  localState[0xc] = 0;
  localState[0xd] = 0;
  localState[0xe] = 0;
  localState[0xf] = 0;
  localState[8] = 0;
  localState[9] = 0;
  localState[10] = 0;
  localState[0xb] = 0;
  localState[4] = 0;
  localState[5] = 0;
  localState[6] = 0;
  localState[7] = 0;
  localState[0] = 0;
  localState[1] = 0;
  localState[2] = 0;
  localState[3] = 0;
  while( true ) {
    flagByte = *arg2;
    if (flagByte == 0) break;
    arg2 = arg2 + 1;
    localState[(int)(uint)flagByte >> 3] = localState[(int)(uint)flagByte >> 3] | '\x01' << (flagByte & 7);
  }
  do {
    value = arg1;
    flagByte = *value;
    if (flagByte == 0) {
      return (byte *)0x0;
    }
    arg1 = value + 1;
  } while ((localState[(int)(uint)flagByte >> 3] >> (flagByte & 7) & 1) == 0);
  return value;
}

