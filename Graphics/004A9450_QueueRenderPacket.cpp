#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9450
// Label: QueueRenderPacket
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void QueueRenderPacket(float *graphicsObject)

{
  float value;
  float value2;
  int value3;
  int value4;
  float *floatCursor;
  float *floatCursor2;
  
  floatCursor = graphicsObject;
  if (g_RenderPacketCount < 3000) {
    value = *graphicsObject;
    if (value <= graphicsObject[1]) {
      value2 = graphicsObject[1];
      graphicsObject = (float *)value;
    }
    else {
      graphicsObject = (float *)graphicsObject[1];
      value2 = value;
    }
    if (floatCursor[2] < (float)graphicsObject) {
      graphicsObject = (float *)floatCursor[2];
    }
    if (value2 < floatCursor[2]) {
      value2 = floatCursor[2];
    }
    if ((_g_FloatZero <= value2) && ((float)graphicsObject <= _g_RenderPacketViewportMaxX)) {
      value = floatCursor[3];
      if (value <= floatCursor[4]) {
        value2 = floatCursor[4];
        graphicsObject = (float *)value;
      }
      else {
        graphicsObject = (float *)floatCursor[4];
        value2 = value;
      }
      if (floatCursor[5] < (float)graphicsObject) {
        graphicsObject = (float *)floatCursor[5];
      }
      if (value2 < floatCursor[5]) {
        value2 = floatCursor[5];
      }
      if ((_g_FloatZero <= value2) && ((float)graphicsObject <= _g_RenderPacketViewportMaxY)) {
        value4 = g_RenderPacketCount + 1;
        floatCursor2 = (float *)(&g_RenderPacketQueueTail + g_RenderPacketCount * 0x3c);
        for (value3 = 0xf; g_RenderPacketCount = value4, value3 != 0; value3 = value3 + -1) {
          *floatCursor2 = *floatCursor;
          floatCursor = floatCursor + 1;
          floatCursor2 = floatCursor2 + 1;
        }
      }
    }
  }
  return;
}

