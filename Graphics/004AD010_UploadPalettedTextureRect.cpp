#include "tarzan_ghidra_types.hpp"

// Address: 0x004AD010
// Label: UploadPalettedTextureRect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UploadPalettedTextureRect
               (undefined4 graphicsObject,int source2,int dest,int width,int height,int flags,
               int arg7,int arg8)

{
  byte *value3;
  undefined1 *dataCursor3;
  ushort value5;
  undefined2 value6;
  int value;
  uint value7;
  undefined2 *dataCursor4;
  int value2;
  short *value4;
  undefined2 *dataCursor;
  undefined4 *dataCursor2;
  int scratchRect4;
  int scratchRect3;
  short scratchRect2;
  undefined4 scratchRect [127];
  
  if ((((source2 < 0x100) && (dest < 0x100)) && (width < 0x101)) &&
     (((height < 0x101 && (source2 + width < 0x101)) && (dest + height < 0x101)))) {
    scratchRect2 = 0;
    dataCursor2 = scratchRect;
    for (value = 0x7f; value != 0; value = value + -1) {
      *dataCursor2 = 0;
      dataCursor2 = dataCursor2 + 1;
    }
    value2 = ((0x10 < arg7) - 1 & 0xfffffffc) + 8;
    *(undefined2 *)dataCursor2 = 0;
    value = 1 << ((byte)value2 & 0x1f);
    if (0 < value) {
      value4 = &scratchRect2;
      do {
        value5 = *(ushort *)((arg8 - (int)&scratchRect2) + (int)value4);
        if ((value5 & 0x8000) != 0) {
          value7 = (uint)(short)value5;
          _g_TextureColorConvertScratch = value7 >> 10 & 0x1f | (value7 & 0x1f) << 10 | value7 & 0x3e0;
          *value4 = (short)_g_TextureColorConvertScratch;
          if ((short)_g_TextureColorConvertScratch == 0) {
            *value4 = 1;
          }
        }
        value4 = value4 + 1;
        value = value + -1;
      } while (value != 0);
    }
    if (value2 == 8) {
      scratchRect3 = width;
    }
    else {
      scratchRect3 = width / 2;
    }
    if (0 < height) {
      dataCursor = &DAT_0077e7b2;
      scratchRect4 = height;
      do {
        if (value2 == 8) {
          value = 0;
          if (0 < width) {
            dataCursor4 = dataCursor + -1;
            do {
              value3 = (byte *)(value + flags);
              value = value + 1;
              *dataCursor4 = *(undefined2 *)((int)scratchRect + (uint)*value3 * 2 + -2);
              dataCursor4 = dataCursor4 + 1;
            } while (value < width);
          }
        }
        else {
          value = 0;
          dataCursor4 = dataCursor;
          if (0 < width / 2) {
            do {
              value6 = *(undefined2 *)((int)scratchRect + (*(byte *)(value + flags) & 0xf) * 2 + -2);
              dataCursor4[-1] = value6;
              dataCursor3 = (undefined1 *)(value + flags);
              value = value + 1;
              *dataCursor4 = *(undefined2 *)
                         ((int)scratchRect +
                         ((int)(uint)CONCAT11((char)((ushort)value6 >> 8),*dataCursor3) >> 4 & 0xfU) * 2 +
                         -2);
              dataCursor4 = dataCursor4 + 2;
            } while (value < width / 2);
          }
        }
        dataCursor = dataCursor + 0x100;
        flags = flags + scratchRect3;
        scratchRect4 = scratchRect4 + -1;
      } while (scratchRect4 != 0);
    }
    UpdateTexturesReference(graphicsObject,source2,dest,width,height);
  }
  return;
}

