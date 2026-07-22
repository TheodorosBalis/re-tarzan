#include "tarzan_ghidra_types.hpp"

// Address: 0x004AB1B0
// Label: LoadingScreen
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadingScreen(char *arg1)

{
  char resultFlag;
  int value;
  uint value4;
  uint value5;
  char *stringCursor;
  int value2;
  char *stringCursor2;
  int value3;
  char scratchBuffer [256];
  
  value4 = 0xffffffff;
  do {
    stringCursor = arg1;
    if (value4 == 0) break;
    value4 = value4 - 1;
    stringCursor = arg1 + 1;
    resultFlag = *arg1;
    arg1 = stringCursor;
  } while (resultFlag != '\0');
  value4 = ~value4;
  stringCursor = stringCursor + -value4;
  stringCursor2 = scratchBuffer;
  for (value5 = value4 >> 2; value5 != 0; value5 = value5 - 1) {
    *(undefined4 *)stringCursor2 = *(undefined4 *)stringCursor;
    stringCursor = stringCursor + 4;
    stringCursor2 = stringCursor2 + 4;
  }
  for (value4 = value4 & 3; value4 != 0; value4 = value4 - 1) {
    *stringCursor2 = *stringCursor;
    stringCursor = stringCursor + 1;
    stringCursor2 = stringCursor2 + 1;
  }
  value4 = 0xffffffff;
  stringCursor = scratchBuffer;
  do {
    if (value4 == 0) break;
    value4 = value4 - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  scratchBuffer[~value4 - 4] = 'e';
  value4 = 0xffffffff;
  stringCursor = scratchBuffer;
  do {
    if (value4 == 0) break;
    value4 = value4 - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  scratchBuffer[~value4 - 3] = 'g';
  value4 = 0xffffffff;
  stringCursor = scratchBuffer;
  do {
    if (value4 == 0) break;
    value4 = value4 - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  scratchBuffer[~value4 - 2] = 'f';
  value = OpenMenuEgfAndIndexChunks(scratchBuffer);
  value2 = 0;
  if (0 < value) {
    value3 = 0xe;
    do {
      LoadMenuEgfChunkToTextureAtlas(value2,&g_MenuTextureAtlasPixels);
      UpdateTexturesReference(value3,0,0,0x100,0x100);
      value2 = value2 + 1;
      value3 = value3 + -1;
    } while (value2 < value);
  }
  ResetMenuEgfState();
  return;
}

