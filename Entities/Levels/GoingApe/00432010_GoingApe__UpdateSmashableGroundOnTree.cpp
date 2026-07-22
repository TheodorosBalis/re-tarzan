#include "tarzan_ghidra_types.hpp"

// Address: 0x00432010
// Label: GoingApe::UpdateSmashableGroundOnTree
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::UpdateSmashableGroundOnTree(int entry)

{
  uint *dataCursor;
  int *intCursor;
  uint value3;
  char resultFlag;
  int value;
  int value2;
  uint *dataCursor2;
  undefined4 value4;
  undefined4 value5;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (value != 0) {
    if ((*(byte *)(entry + 0x42) & 0x10) != 0) {
      CEntities::SpawnEntityByTypeAtPosition
                (*(undefined4 *)(g_PlayerEntitySceneObjectData + 8),
                 *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
                 *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10),0x13,0x11);
      value2 = *(int *)(entry + 0x4c) + -1;
      *(int *)(entry + 0x4c) = value2;
      if (value2 < 1) {
        if (*(char *)(entry + 0x3d) == '\a') {
          value4 = *(undefined4 *)(value + 0x18);
          value5 = 0x2003;
        }
        else {
          value4 = *(undefined4 *)(value + 0x18);
          value5 = 0x2001;
        }
        DecodeEncodedEntitySceneObjectIdToSourceRef(value4,value5);
        value3 = *(uint *)(g_PlayerContactSurfaceThisFrame + -8);
        value2 = g_PlayerContactSurfaceThisFrame;
        while ((value3 & 0x200) != 0) {
          value3 = *(uint *)(value2 + -0x24);
          value2 = value2 + -0x1c;
        }
        dataCursor2 = (uint *)(value2 + 0x14);
        value3 = *(uint *)(value2 + 0x14);
        while ((value3 & 0x200) != 0) {
          *dataCursor2 = value3 | 0x100;
          dataCursor = dataCursor2 + 7;
          dataCursor2 = dataCursor2 + 7;
          value3 = *dataCursor;
        }
        intCursor = (int *)(value + 0xc);
        PlayAudioById(0xcf,(int *)0,(undefined4 *)intCursor);
        CEntities::UnlinkEntityFromProcessingList(entry);
        PlayForceFeedbackEffect_Stub(0,2,0x14);
        CEntities::SpawnSmashableFlyingDebris
                  (*intCursor,*(undefined4 *)(value + 0x10),*(undefined4 *)(value + 0x14),0x29,0x2006,
                   0x400);
        CEntities::SpawnSmashableDustEmitter
                  (*intCursor,*(undefined4 *)(value + 0x10),*(undefined4 *)(value + 0x14));
        CEntities::SpawnSmashableDebrisShardBurst
                  (*intCursor + 0x1e,*(int *)(value + 0x10) + -0x32,*(undefined4 *)(value + 0x14),0x2a,
                   0x2012,4,8,0x400);
      }
    }
    *(ushort *)(entry + 0x42) = *(ushort *)(entry + 0x42) & 0xffef;
  }
  resultFlag = IsEntitySourceRefOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

