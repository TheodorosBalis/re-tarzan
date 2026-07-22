#include "tarzan_ghidra_types.hpp"

// Address: 0x0049AE80
// Label: DrawGraphicsTextinMem
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DrawGraphicsTextinMem
               (undefined4 graphicsObject,undefined4 source2,undefined4 dest,undefined4 width,
               undefined4 height)

{
  undefined4 value;
  
  value = Return6(dest,width,height);
  value = Return6_2(value);
  value = Return6(1,1,value);
  value = Return6_2(value);
  DrawGraphicsText(graphicsObject,source2,value);
  return;
}

