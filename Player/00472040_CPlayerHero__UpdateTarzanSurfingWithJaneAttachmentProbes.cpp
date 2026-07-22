#include "tarzan_ghidra_types.hpp"

// Address: 0x00472040
// Label: CPlayerHero::UpdateTarzanSurfingWithJaneAttachmentProbes
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTarzanSurfingWithJaneAttachmentProbes(void)

{
  int value;
  short *localState;
  
  g_TarzanSurfingWithJaneAttachmentProbeARadiusSquared = 0;
  g_TarzanSurfingWithJaneAttachmentProbeBRadiusSquared = 0;
  value = GetEntitySceneObjectAttachmentList(g_PlayerEntitySceneObject,&localState);
  if ((value != 0) && (0 < value)) {
    do {
      if ((*(uint *)(localState + 6) & 0x200) != 0) {
        g_TarzanSurfingWithJaneAttachmentProbeAX =
             *(int *)(g_PlayerEntitySceneObjectData + 8) + (int)*localState;
        _g_TarzanSurfingWithJaneAttachmentProbeAY =
             (int)localState[1] + *(int *)(g_PlayerEntitySceneObjectData + 0xc);
        g_TarzanSurfingWithJaneAttachmentProbeAZ =
             (int)localState[2] + *(int *)(g_PlayerEntitySceneObjectData + 0x10);
        g_TarzanSurfingWithJaneAttachmentProbeARadiusSquared = (int)localState[3] * (int)localState[3];
      }
      if ((*(uint *)(localState + 6) & 0x400) != 0) {
        g_TarzanSurfingWithJaneAttachmentProbeBX =
             *(int *)(g_PlayerEntitySceneObjectData + 8) + (int)*localState;
        _g_TarzanSurfingWithJaneAttachmentProbeBY =
             (int)localState[1] + *(int *)(g_PlayerEntitySceneObjectData + 0xc);
        g_TarzanSurfingWithJaneAttachmentProbeBZ =
             (int)localState[2] + *(int *)(g_PlayerEntitySceneObjectData + 0x10);
        g_TarzanSurfingWithJaneAttachmentProbeBRadiusSquared = (int)localState[3] * (int)localState[3];
      }
      localState = localState + 8;
      value = value + -1;
    } while (value != 0);
  }
  return;
}

