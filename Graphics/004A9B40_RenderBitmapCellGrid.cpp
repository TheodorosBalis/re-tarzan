#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9B40
// Label: RenderBitmapCellGrid
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderBitmapCellGrid(undefined4 *graphicsObject,uint *source2)

{
  uint value3;
  int value2;
  byte flagByte;
  uint value5;
  uint value6;
  uint value7;
  uint value8;
  uint value9;
  uint value10;
  undefined1 value4;
  int value;
  uint *dataCursor;
  uint *localState4;
  uint localState3;
  int localState2;
  int localState;
  
  if (graphicsObject == (undefined4 *)0x0) {
    return;
  }
  if (source2 == (uint *)0x0) {
    return;
  }
  value5 = 0x1000 - g_FadeBrightnessInverse;
  if (g_FadeBrightnessInverse == 0) {
    value3 = 0xffffff;
  }
  else {
    value3 = ((value5 & 0xfffffff0) << 8 | value5 & 0xfffffff0) << 4 | (int)value5 >> 4;
  }
  localState4 = (uint *)*graphicsObject;
  if (localState4 == (uint *)0x0) {
    return;
  }
  localState3 = source2[1];
  value8 = *(int *)((int)graphicsObject + 0x4e) << 1 | 1;
  flagByte = (char)*(undefined4 *)((int)graphicsObject + 0x3e) + 1;
  if ((int)localState3 < 0) {
    value = (int)-localState3 >> (flagByte & 0x1f);
    if (*(int *)((int)graphicsObject + 0x2e) <= value) {
      return;
    }
    value7 = -localState3 & value8;
    localState3 = -value7;
    localState = (int)(value8 + value7 + 0x1e0) >> (flagByte & 0x1f);
    value2 = *(int *)((int)graphicsObject + 0x2e) - value;
    if (value2 < localState) {
      localState = value2;
    }
    localState4 = (uint *)((int)localState4 + *(int *)((int)graphicsObject + 0x2a) * value * 0xe);
  }
  else {
    localState = (int)((value8 - localState3) + 0x1e0) >> (flagByte & 0x1f);
    if (localState < 1) {
      return;
    }
    if (*(int *)((int)graphicsObject + 0x2e) <= localState) {
      localState = *(int *)((int)graphicsObject + 0x2e);
    }
  }
  if (*(int *)((int)graphicsObject + 0x6a) == 0) {
    value8 = *source2;
    if ((int)value8 < 0) {
      flagByte = (byte)*(undefined4 *)((int)graphicsObject + 0x3a);
      value = (int)-value8 >> (flagByte & 0x1f);
      localState4 = (uint *)((int)localState4 + value * 0xe);
      if (*(int *)((int)graphicsObject + 0x2a) <= value) {
        return;
      }
      value7 = -value8 & *(uint *)((int)graphicsObject + 0x4a);
      value8 = -value7;
      source2 = (uint *)((int)(*(uint *)((int)graphicsObject + 0x4a) + value7 + 0x280) >> (flagByte & 0x1f));
      if ((int)source2 < 1) {
        return;
      }
      value = *(int *)((int)graphicsObject + 0x2a) - value;
      if ((int)source2 <= value) goto LAB_004a9d03;
    }
    else {
      if (0x27f < (int)value8) {
        return;
      }
      source2 = (uint *)((int)((*(int *)((int)graphicsObject + 0x4a) - value8) + 0x280) >>
                        ((byte)*(undefined4 *)((int)graphicsObject + 0x3a) & 0x1f));
      if ((int)source2 < 1) {
        return;
      }
      value = *(int *)((int)graphicsObject + 0x2a);
      if ((int)source2 <= value) goto LAB_004a9d03;
    }
    source2 = (uint *)value;
  }
  else {
    flagByte = (byte)*(undefined4 *)((int)graphicsObject + 0x3a);
    localState4 = (uint *)((int)localState4 + ((int)*source2 >> (flagByte & 0x1f)) * 0xe);
    value7 = *(uint *)((int)graphicsObject + 0x4a) & *source2;
    value8 = -value7;
    source2 = (uint *)((int)(*(uint *)((int)graphicsObject + 0x4a) + value7 + 0x280) >> (flagByte & 0x1f));
    if ((int)source2 < 1) {
      return;
    }
  }
LAB_004a9d03:
  if (0 < localState) {
    do {
      value = (int)(short)value8;
      dataCursor = localState4;
      localState2 = (int)source2;
      if (0 < (int)source2) {
        do {
          value7 = *dataCursor;
          value9 = value7 & 0xc00000;
          if (value9 != 0) {
            value6 = value3 | 0xff000000;
            if (value9 == 0x400000) {
LAB_004a9dac:
              value10 = value7 >> 9 & 0xff;
            }
            else {
              if (value5 == 0x1000) {
                value6 = dataCursor[1] | 0xff000000;
              }
              else {
                value6 = dataCursor[1];
                value6 = ((value6 >> 0x10 & 0xff) * value5 & 0xfffff000 | 0xfff00000) << 4 |
                        ((value6 >> 8 & 0xff) * value5 >> 0xc) << 8 | (value6 & 0xff) * value5 >> 0xc;
              }
              if (value9 == 0x400000) goto LAB_004a9dac;
              value10 = 0;
            }
            if (value9 == 0x400000) {
              value4 = (undefined1)*dataCursor;
            }
            else {
              value4 = 0;
            }
            DrawTexturedQuad(*(short *)((int)dataCursor + 10) + value,localState3 + (short)dataCursor[3] * 2
                             ,value7 & 0x1ff,(value7 >> 9 & 0x1ff) << 1,(ushort)dataCursor[2] & 0xff,
                             (char)((ushort)dataCursor[2] >> 8),value4,value10,value7 >> 0x12 & 0xffffff0f
                             ,value6,0,CONCAT22((short)((uint)value >> 0x10),
                                               (undefined2)g_DrawWindowXOffset),0,1);
          }
          localState2 = localState2 + -1;
          value = value + *(int *)((int)graphicsObject + 0x42);
          dataCursor = (uint *)((int)dataCursor + 0xe);
        } while (localState2 != 0);
      }
      localState4 = (uint *)((int)localState4 + *(int *)((int)graphicsObject + 0x2a) * 0xe);
      localState3 = localState3 + *(int *)((int)graphicsObject + 0x46) * 2;
      localState = localState + -1;
    } while (localState != 0);
  }
  return;
}

