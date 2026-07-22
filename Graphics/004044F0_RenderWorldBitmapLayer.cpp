#include "tarzan_ghidra_types.hpp"

// Address: 0x004044F0
// Label: RenderWorldBitmapLayer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderWorldBitmapLayer(int graphicsObject,int source2,int dest)

{
  int value;
  uint value2;
  int localState2;
  int localState;
  
  SetFadeBrightnessAndTint(*(undefined4 *)(source2 + 0xb0),source2 + 0xb4);
  if (*(int *)(graphicsObject + 0x6a) < 1) {
    localState2 = (*(int *)(graphicsObject + 0x56) * 0x1000) / 0x168 + (*(ushort *)(source2 + 0x52) & 0xfff);
    if (0x7ff < localState2) {
      localState2 = localState2 + -0x1000;
    }
    localState2 = localState2 + *(int *)(source2 + 0x18);
  }
  else {
    localState2 = *(int *)(graphicsObject + 0x32);
    value = (-(uint)*(ushort *)(source2 + 0x52) & 0xfff) * localState2 * *(int *)(graphicsObject + 0x6a);
    localState2 = ((*(int *)(graphicsObject + 0x56) * localState2) / 0x168 +
               ((int)(value + (value >> 0x1f & 0xfffU)) >> 0xc) + *(int *)(source2 + 0x18)) %
              localState2;
  }
  value2 = *(ushort *)(source2 + 0x50) & 0xfff;
  if (0x7ff < value2) {
    value2 = value2 - 0x1000;
  }
  value = ((int)*(short *)(dest + 6) - (int)*(short *)(dest + 2)) * *(int *)(graphicsObject + 0x66) *
          value2;
  localState = (*(int *)(source2 + 0x1c) - ((int)(value + (value >> 0x1f & 0xfffffU)) >> 0x14)) +
            *(int *)(graphicsObject + 0x5a) * -2;
  SetDrawWindow(dest,*(undefined4 *)(graphicsObject + 0x5e));
  RenderBitmapCellGrid(graphicsObject,&localState2);
  return;
}

