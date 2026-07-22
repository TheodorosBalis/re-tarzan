#include "tarzan_ghidra_types.hpp"

// Address: 0x004385A0
// Label: LoadEncodedResourceId
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadEncodedResourceId(uint arg1)

{
  ushort value;
  
  if ((arg1 & 0x1000) == 0) {
    if ((arg1 & 0x2000) == 0) {
      if (((ushort)arg1 != 0) && ((ushort)arg1 < 0x91)) {
        RequestResourceSetLoad(&g_ResourceSetDescriptorTable + (arg1 & 0xffff) * 0x68);
      }
    }
    else {
      value = (ushort)(arg1 & 0xfff);
      if ((value != 0) && (value < 0x1032)) {
        RequestWorldSceneAuxResourceLoadNoOp
                  (g_CurrentWorldSceneContext,g_CurrentWorldSceneAuxResourceContext,
                   *(undefined4 *)(&g_EncodedWorldSceneAuxResourceIdTable + (arg1 & 0xfff) * 4));
        return;
      }
    }
  }
  else {
    value = (ushort)(arg1 & 0xfff);
    if ((value != 0) && (value < 0x1032)) {
      RequestEncodedSceneModelResourceLoad
                (&g_EncodedSceneModelResourceTable + (arg1 & 0xfff) * 0x10);
      return;
    }
  }
  return;
}

