#include "tarzan_ghidra_types.hpp"

// Address: 0x00438630
// Label: UnloadEncodedResourceId
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UnloadEncodedResourceId(uint arg1)

{
  ushort value;
  
  if ((arg1 & 0x1000) == 0) {
    if ((arg1 & 0x2000) == 0) {
      if (((ushort)arg1 != 0) && ((ushort)arg1 < 0x91)) {
        ReleaseResourceSet(&g_ResourceSetDescriptorTable + (arg1 & 0xffff) * 0x68);
      }
    }
    else {
      value = (ushort)(arg1 & 0xfff);
      if ((value != 0) && (value < 0x204b)) {
        ReleaseWorldSceneAuxResourceNoOp
                  (g_CurrentWorldSceneContext,
                   *(undefined4 *)(&g_EncodedWorldSceneAuxResourceIdTable + (arg1 & 0xfff) * 4));
        return;
      }
    }
  }
  else {
    value = (ushort)(arg1 & 0xfff);
    if ((value != 0) && (value < 0x1032)) {
      ReleaseEncodedSceneModelResource(&g_EncodedSceneModelResourceTable + (arg1 & 0xfff) * 0x10)
      ;
      return;
    }
  }
  return;
}

