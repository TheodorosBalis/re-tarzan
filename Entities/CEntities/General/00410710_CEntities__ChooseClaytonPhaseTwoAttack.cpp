#include "tarzan_ghidra_types.hpp"

// Address: 0x00410710
// Label: CEntities::ChooseClaytonPhaseTwoAttack
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::ChooseClaytonPhaseTwoAttack(int entry)

{
  char resultFlag;
  uint value;
  
  if ((_g_PlayerSequenceFlags & 0x8000) != 0) {
switchD_004107ca_caseD_4:
    *(undefined2 *)(entry + 0x48) = 0x33;
    CEntities::SelectEntityAnimationAttachmentState(entry,0x11);
    return;
  }
  if ((g_PlayerDamageInvulnerabilityTicks != 0) ||
     (499 < *(int *)(g_PlayerEntitySceneObjectData + 8) -
            *(int *)(*(int *)(g_ClaytonEntity + 0x38) + 0x14))) {
    value = *(int *)(entry + 0x50) + 1;
    *(uint *)(entry + 0x50) = value;
    switch(*(undefined4 *)(&g_ClaytonPhaseTwoAttackDecisionTable + (value & 0x1f) * 4)) {
    case 1:
      *(undefined2 *)(entry + 0x48) = 0xf;
      CEntities::SelectEntityAnimationAttachmentState(entry,0x12);
      return;
    case 2:
      *(undefined2 *)(entry + 0x48) = 0x32;
      CEntities::SelectEntityAnimationAttachmentState(entry,0x13);
      return;
    case 3:
      *(undefined2 *)(entry + 0x48) = 0x25;
      CEntities::SelectEntityAnimationAttachmentState(entry,0x10);
      return;
    case 4:
      goto switchD_004107ca_caseD_4;
    default:
      *(undefined2 *)(entry + 0x48) = 0;
      CEntities::SelectEntityAnimationAttachmentState(entry,0);
      return;
    }
  }
  if (-0xfb < *(int *)(g_PlayerEntitySceneObjectData + 0xc) -
              *(int *)(*(int *)(g_ClaytonEntity + 0x38) + 0x18)) {
    *(undefined2 *)(entry + 0x48) = 0x31;
    CEntities::SelectEntityAnimationAttachmentState(entry,0xd);
    return;
  }
  resultFlag = *(char *)(g_PlayerMotionState + 0xd);
  *(undefined2 *)(entry + 0x48) = 0x30;
  if (resultFlag != '\0') {
    CEntities::SelectEntityAnimationAttachmentState(entry,0xf);
    return;
  }
  CEntities::SelectEntityAnimationAttachmentState(entry,0xe);
  return;
}

