#include "tarzan_ghidra_types.hpp"

// Address: 0x0049CC60
// Label: RefreshDirtyTexturePage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RefreshDirtyTexturePage(undefined4 graphicsObject,undefined4 source2)

{
  undefined4 value;
  
  value = CurrentGraphicsMode();
  switch(value) {
  case 1:
    UploadGlideTexturePage(graphicsObject,source2);
    return;
  case 2:
    CreateOrUploadDirect3DTexturePage(graphicsObject,source2);
    return;
  case 3:
  case 4:
    RefreshDirectDrawDirtyTexturePage_NoOp(graphicsObject,source2);
    return;
  case 5:
    GraphicsPresentCallbackNoOp(graphicsObject,source2);
  }
  return;
}

