#include "tarzan_ghidra_types.hpp"

// Address: 0x00494620
// Label: LoadECMinChunks
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 LoadECMinChunks(void)

{
  int value;
  int value2;
  int value3;
  uint value4;
  bool flagByte;
  char *incomingStackArg;
  
  SafeCheckStackPtr();
  if ((incomingStackArg == (char *)0x0) || (*incomingStackArg == '\0')) {
    return 0xfffffffd;
  }
  value = fopen(incomingStackArg,&s_FileModeReadBinary);
  if (value == 0) {
    return 0xfffffffe;
  }
  rewind(value);
  g_EcmChunkPayloadOffset = 0;
  g_EcmLoadedChunkCount = 0;
  g_EcmExpectedChunkCount = 0;
  value2 = fread(&stack0x00000000,1,0x4010,value);
  do {
    if (value2 < 1) {
      g_EcmLoadedChunkCount = g_EcmLoadedChunkCount ^ g_EcmChunkMarkerLo;
      g_EcmExpectedChunkCount = g_EcmExpectedChunkCount ^ g_EcmChunkMarkerHi;
      fclose(value);
      return 0;
    }
    fseek(value,1,0xfffffff0);
    value4 = value2 - 0x10;
    flagByte = CARRY4(g_EcmLoadedChunkCount,value4);
    g_EcmLoadedChunkCount = g_EcmLoadedChunkCount + value4;
    g_EcmExpectedChunkCount = g_EcmExpectedChunkCount + ((int)value4 >> 0x1f) + (uint)flagByte;
    value2 = 0;
    if (0 < (int)value4) {
      do {
        if ((*(uint *)(&stack0x00000000 + value2) == g_EcmChunkMarkerLo) &&
           (*(uint *)(&stack0x00000004 + value2) == g_EcmChunkMarkerHi)) {
          if (g_EcmChunkPayloadOffset != 0) {
            return 0xfffffffb;
          }
          value3 = ftell(value);
          g_EcmChunkPayloadOffset = value3 + -8 + (value2 - value4);
          fseek(value,0,g_EcmChunkPayloadOffset + 8);
          break;
        }
        flagByte = CARRY4(g_EcmLoadedChunkCount,*(uint *)(&stack0x00000000 + value2));
        g_EcmLoadedChunkCount = g_EcmLoadedChunkCount + *(uint *)(&stack0x00000000 + value2);
        g_EcmExpectedChunkCount = g_EcmExpectedChunkCount + flagByte;
        value2 = value2 + 1;
      } while (value2 < (int)value4);
    }
    value2 = fread(&stack0x00000000,1,0x4010,value);
  } while( true );
}

