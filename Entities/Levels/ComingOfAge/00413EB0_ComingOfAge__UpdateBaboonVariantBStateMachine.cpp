#include "tarzan_ghidra_types.hpp"

// Address: 0x00413EB0
// Label: ComingOfAge::UpdateBaboonVariantBStateMachine
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateBaboonVariantBStateMachine
               (int entry,int sceneObject,int attachment,undefined4 flags,byte arg5)

{
  short state;
  int value;
  undefined4 stateFlags;
  int value2;
  uint stateFlags2;
  int value3;
  
  state = *(short *)(attachment + 0x18);
  value = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(sceneObject + 0x110) * 4) + 8 +
                   *(int *)(sceneObject + 0x110) * 4 + g_CollisionSurfaceTable);
  value3 = *(int *)(sceneObject + 0x10c);
  if ((arg5 & 8) == 0) {
    if (((arg5 & 0x10) != 0) &&
       ((*(ushort *)(entry + 0x48) < 2 || (3 < *(ushort *)(entry + 0x48))))) {
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
      *(undefined2 *)(entry + 0x48) = 2;
      CEntities::SelectScriptAttachmentSequence(attachment,0x10);
    }
  }
  else {
    *(undefined2 *)(entry + 0x48) = 0x10;
    if ((*(byte *)(entry + 0x4a) & 8) != 0) {
      CEntities::HandleAnimalScriptEvent(entry,sceneObject,0x107);
    }
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 2:
    value = RandomModulo(0x28);
    *(int *)(entry + 0x4c) = value + 0x1e;
    *(undefined2 *)(entry + 0x48) = 3;
    return;
  case 3:
    value = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value;
    if (value == 0) {
      stateFlags = RandomModulo(8);
      switch(stateFlags) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
        if ((arg5 & 1) == 0) {
          *(undefined2 *)(entry + 0x48) = 4;
          return;
        }
        break;
      case 5:
      case 6:
        *(undefined2 *)(entry + 0x48) = 9;
        return;
      case 7:
        *(undefined2 *)(entry + 0x48) = 10;
        return;
      }
    }
    break;
  case 4:
    stateFlags2 = CEntities::ComputeSignedPlayerFacingDistanceXZ(sceneObject + 0x14);
    if (*(char *)(sceneObject + 0x75) != '\0') {
      stateFlags2 = ~stateFlags2 + 1;
    }
    if (((int)stateFlags2 < 1) || (499 < (int)stateFlags2)) {
      value2 = RandomModulo(0x5a);
      *(int *)(entry + 0x4c) = value2 + 0x3c;
      if (((800 < value3) || (*(char *)(sceneObject + 0x75) == '\0')) &&
         ((800 < value - value3 || (*(char *)(sceneObject + 0x75) != '\0')))) {
        *(undefined2 *)(entry + 0x48) = 5;
        CEntities::SelectScriptAttachmentSequence(attachment,0x33);
        return;
      }
      *(undefined2 *)(entry + 0x48) = 0xb;
      CEntities::SelectScriptAttachmentSequence(attachment,0x39);
      return;
    }
    if (*(char *)(sceneObject + 0x75) != '\0') {
      value3 = value - value3;
    }
    if (600 < value3) {
      *(undefined2 *)(entry + 0x48) = 0xb;
      CEntities::SelectScriptAttachmentSequence(attachment,0x39);
      return;
    }
    *(undefined2 *)(entry + 0x48) = 0;
    return;
  case 5:
    value2 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value2;
    if (value2 == 0) {
      *(undefined2 *)(entry + 0x48) = 6;
      return;
    }
    if (((value3 < 0x321) && (*(char *)(sceneObject + 0x75) != '\0')) ||
       ((value - value3 < 0x321 && (*(char *)(sceneObject + 0x75) == '\0')))) {
      *(undefined2 *)(entry + 0x48) = 0xb;
      CEntities::SelectScriptAttachmentSequence(attachment,0x38);
      return;
    }
    break;
  case 6:
    if ((arg5 & 4) != 0) {
      CEntities::AdvanceScriptAttachmentSequence(attachment);
      *(undefined2 *)(entry + 0x48) = 0x14;
      return;
    }
    break;
  case 9:
    if ((arg5 & 4) != 0) {
      CEntities::SelectScriptAttachmentSequence(attachment,0x11);
      *(undefined2 *)(entry + 0x48) = 0x14;
      return;
    }
    break;
  case 10:
    *(undefined2 *)(entry + 0x48) = 0xb;
    stateFlags2 = RandomModulo(4);
    if ((stateFlags2 & 1) != 0) {
      CEntities::SelectScriptAttachmentSequence(attachment,0x20);
      return;
    }
    CEntities::SelectScriptAttachmentSequence(attachment,0x23);
    return;
  case 0xb:
    if (state == 0x34) {
      *(undefined2 *)(entry + 0x48) = 5;
      return;
    }
    if (state == 0x10) {
      *(undefined2 *)(entry + 0x48) = 2;
    }
    break;
  case 0x10:
    *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
    CEntities::SelectScriptAttachmentSequence(attachment,10);
    *(undefined2 *)(entry + 0x48) = 0x14;
    return;
  }
  return;
}

