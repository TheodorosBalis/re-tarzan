#include "tarzan_ghidra_types.hpp"

// Address: 0x0049AD70
// Label: DrawGraphicsText
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int DrawGraphicsText(int graphicsObject,int source2,int dest,int width,int height,int flags,
                    int arg7,int arg8,byte *arg9,undefined4 arg10)

{
  int value;
  uint value3;
  byte flagByte;
  uint value4;
  int value2;
  
  flagByte = *arg9;
  value2 = graphicsObject;
  if (flagByte == 0) {
    *( undefined1 *)((int)&g_GraphicsTextScratchBuffer + 0) = 0;
    return graphicsObject;
  }
  do {
    value = isalpha(flagByte);
    if (value != 0) {
      flagByte = flagByte - 0x20;
    }
    if (flagByte == 10) {
      value2 = graphicsObject - dest;
      source2 = source2 + width;
    }
    else if ((0x20 < flagByte) && (flagByte < 0x61)) {
      value3 = (0x100 - height) / arg7;
      value4 = flagByte - 0x21 & 0xff;
      DrawTexturedQuad(value2,source2,(short)dest + -1,(short)width + -1,
                       (value4 % value3) * arg7 + height,(value4 / value3) * arg8 + flags,
                       arg7 + -1,arg8 + -1,0xf,arg10,0,0,1,1);
    }
    arg9 = arg9 + 1;
    value2 = value2 + dest;
    flagByte = *arg9;
  } while (flagByte != 0);
  *( undefined1 *)((int)&g_GraphicsTextScratchBuffer + 0) = flagByte;
  return value2;
}

