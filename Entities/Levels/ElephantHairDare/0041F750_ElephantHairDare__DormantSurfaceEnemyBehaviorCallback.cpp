#include "tarzan_ghidra_types.hpp"

// Address: 0x0041F750
// Label: ElephantHairDare::DormantSurfaceEnemyBehaviorCallback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::DormantSurfaceEnemyBehaviorCallback
               (int arg1,int arg2,int arg3,undefined4 arg4,byte arg5)

{
  short shortValue;
  int value;
  undefined4 value4;
  int value2;
  uint value5;
  int value3;
  
  shortValue = *(short *)(arg3 + 0x18);
  value = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(arg2 + 0x110) * 4) + 8 +
                   *(int *)(arg2 + 0x110) * 4 + g_CollisionSurfaceTable);
  value3 = *(int *)(arg2 + 0x10c);
  if ((arg5 & 8) == 0) {
    if (((arg5 & 0x10) != 0) &&
       ((*(ushort *)(arg1 + 0x48) < 2 || (3 < *(ushort *)(arg1 + 0x48))))) {
      *(ushort *)(arg1 + 0x4a) = *(ushort *)(arg1 + 0x4a) & 0xfffc;
      *(undefined2 *)(arg1 + 0x48) = 2;
      CEntities::SelectScriptAttachmentSequence(arg3,0x10);
    }
  }
  else {
    *(undefined2 *)(arg1 + 0x48) = 0x10;
    if ((*(byte *)(arg1 + 0x4a) & 8) != 0) {
      CEntities::HandleAnimalScriptEvent(arg1,arg2,0x107);
    }
  }
  switch(*(undefined2 *)(arg1 + 0x48)) {
  case 2:
    value = RandomModulo(0x28);
    *(int *)(arg1 + 0x4c) = value + 0x1e;
    *(undefined2 *)(arg1 + 0x48) = 3;
    return;
  case 3:
    value = *(int *)(arg1 + 0x4c) + -1;
    *(int *)(arg1 + 0x4c) = value;
    if (value == 0) {
      value4 = RandomModulo(8);
      switch(value4) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
        if ((arg5 & 1) == 0) {
          *(undefined2 *)(arg1 + 0x48) = 4;
          return;
        }
        break;
      case 5:
      case 6:
        *(undefined2 *)(arg1 + 0x48) = 9;
        return;
      case 7:
        *(undefined2 *)(arg1 + 0x48) = 10;
        return;
      }
    }
    break;
  case 4:
    value5 = CEntities::ComputeSignedPlayerFacingDistanceXZ(arg2 + 0x14);
    if (*(char *)(arg2 + 0x75) != '\0') {
      value5 = ~value5 + 1;
    }
    if (((int)value5 < 1) || (499 < (int)value5)) {
      value2 = RandomModulo(0x5a);
      *(int *)(arg1 + 0x4c) = value2 + 0x3c;
      if (((800 < value3) || (*(char *)(arg2 + 0x75) == '\0')) &&
         ((800 < value - value3 || (*(char *)(arg2 + 0x75) != '\0')))) {
        *(undefined2 *)(arg1 + 0x48) = 5;
        CEntities::SelectScriptAttachmentSequence(arg3,0x33);
        return;
      }
      *(undefined2 *)(arg1 + 0x48) = 0xb;
      CEntities::SelectScriptAttachmentSequence(arg3,0x39);
      return;
    }
    if (*(char *)(arg2 + 0x75) != '\0') {
      value3 = value - value3;
    }
    if (600 < value3) {
      *(undefined2 *)(arg1 + 0x48) = 0xb;
      CEntities::SelectScriptAttachmentSequence(arg3,0x39);
      return;
    }
    *(undefined2 *)(arg1 + 0x48) = 0;
    return;
  case 5:
    value2 = *(int *)(arg1 + 0x4c) + -1;
    *(int *)(arg1 + 0x4c) = value2;
    if (value2 == 0) {
      *(undefined2 *)(arg1 + 0x48) = 6;
      return;
    }
    if (((value3 < 0x321) && (*(char *)(arg2 + 0x75) != '\0')) ||
       ((value - value3 < 0x321 && (*(char *)(arg2 + 0x75) == '\0')))) {
      *(undefined2 *)(arg1 + 0x48) = 0xb;
      CEntities::SelectScriptAttachmentSequence(arg3,0x38);
      return;
    }
    break;
  case 6:
    if ((arg5 & 4) != 0) {
      CEntities::AdvanceScriptAttachmentSequence(arg3);
      *(undefined2 *)(arg1 + 0x48) = 0x14;
      return;
    }
    break;
  case 9:
    if ((arg5 & 4) != 0) {
      CEntities::SelectScriptAttachmentSequence(arg3,0x11);
      *(undefined2 *)(arg1 + 0x48) = 0x14;
      return;
    }
    break;
  case 10:
    *(undefined2 *)(arg1 + 0x48) = 0xb;
    value5 = RandomModulo(4);
    if ((value5 & 1) != 0) {
      CEntities::SelectScriptAttachmentSequence(arg3,0x20);
      return;
    }
    CEntities::SelectScriptAttachmentSequence(arg3,0x23);
    return;
  case 0xb:
    if (shortValue == 0x34) {
      *(undefined2 *)(arg1 + 0x48) = 5;
      return;
    }
    if (shortValue == 0x10) {
      *(undefined2 *)(arg1 + 0x48) = 2;
    }
    break;
  case 0x10:
    *(ushort *)(arg1 + 0x4a) = *(ushort *)(arg1 + 0x4a) & 0xfffc;
    CEntities::SelectScriptAttachmentSequence(arg3,10);
    *(undefined2 *)(arg1 + 0x48) = 0x14;
    return;
  }
  return;
}

