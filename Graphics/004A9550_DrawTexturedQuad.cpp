#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9550
// Label: DrawTexturedQuad
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DrawTexturedQuad(int graphicsObject,int source2,int dest,int width,byte height,ushort flags,
                     undefined2 arg7,undefined2 arg8,byte arg9,undefined4 arg10,
                     byte arg11,ushort arg12,byte arg13,byte arg14)

{
  float floatValue;
  int value;
  float localState12;
  float localState11;
  float localState10;
  float localState9;
  float localState8;
  float localState7;
  float localState6;
  float localState5;
  float localState4;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  undefined2 localState17;
  undefined2 localState16;
  ushort localState15;
  ushort localState14;
  undefined4 localState13;
  
  if ((0 < dest) && (0 < width)) {
    localState14 = arg12;
    localState6 = (float)arg12;
    localState12 = (float)graphicsObject;
    localState9 = (float)source2;
    *( undefined2 *)((int)&localState13 + 0) =
         arg9 & 0xff1f |
         (((short)(char)(arg14 & 1) | (short)(char)(arg11 & 3) << 5) << 1 |
         (short)(char)(arg13 & 1)) << 5;
    localState = arg10;
    localState2 = arg10;
    localState3 = arg10;
    localState17 = (ushort)height << 8 | flags;
    localState11 = localState12;
    localState10 = localState12;
    localState8 = localState9;
    localState7 = localState9;
    localState5 = localState6;
    localState4 = localState6;
    localState16 = localState17;
    localState15 = localState17;
    value = IsHardware3DGraphicsMode();
    floatValue = (float)dest;
    if (value == 0) {
      localState11 = floatValue + localState11;
      localState16 = arg7;
      localState15 = arg8;
      localState7 = (float)width;
      localState8 = localState7 + localState8;
      localState13 = CONCAT22(*( undefined2 *)((int)&localState13 + 2),(ushort)localState13) & 0xfffffbff | 0x200;
      localState10 = floatValue;
      QueueRenderPacket(&localState12);
      return;
    }
    localState11 = floatValue + localState11;
    localState15 = CONCAT11(*( undefined1 *)((int)&localState15 + 1),(char)localState15 + (char)arg8);
    localState7 = (float)width + localState7;
    *( undefined1 *)((int)&localState16 + 1) = *( undefined1 *)((int)&localState16 + 1) + (char)arg7;
    QueueRenderPacket(&localState12);
    localState9 = localState7;
    localState12 = localState11;
    localState17 = CONCAT11(*( undefined1 *)((int)&localState16 + 1),(char)localState15);
    QueueRenderPacket(&localState12);
  }
  return;
}

