#include "tarzan_ghidra_types.hpp"

// Address: 0x00485EB0
// Label: TrashingTheCamp::UpdateMonkey
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateMonkey(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  int value2;
  bool flagByte;
  char resultFlag;
  char resultFlag2;
  short shortValue2;
  int value3;
  int value4;
  
  LoadEncodedResourceId(0x1015);
  value4 = entity->sceneObjects;
  if ((value4 == 0) ||
     (value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value3 == 0))
  goto switchD_00485fbd_caseD_4;
  shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  shortValue = *(short *)(value3 + 0x18);
  CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value4,0x24,0x14);
  resultFlag = CEntities::HandleAnimalScriptEvent(entry,value4,(int)shortValue2);
  value = ((EntitySceneObject *)value4)->surfaceIndex;
  value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value4)->surfacePathIndex * 4) + 8 +
                   ((EntitySceneObject *)value4)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
  resultFlag2 = CEntities::CheckPlayerDamageContact(value4);
  if (resultFlag2 != '\0') {
    g_PlayerDamageContactEntitySceneObject = value4;
    QueuePlayerDamageEvent(entry,0x1006);
  }
  flagByte = false;
  resultFlag2 = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag2 != '\0') {
    if (*(short *)(entry + 0x3e) < 1) goto LAB_00485f8b;
    PlayAudioById(0x112,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
    flagByte = true;
  }
  if (*(short *)(entry + 0x3e) < 1) {
LAB_00485f8b:
    PlayAudioById(0x158,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
    CEntities::ProcessEntityDeathAndRelease(entry,1);
    return;
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    if (flagByte) {
      *(undefined2 *)(entry + 0x48) = 9;
    }
    else {
      CEntities::SelectScriptAttachmentSequence(value3,0);
      *(undefined2 *)(entry + 0x48) = 1;
    }
    break;
  case 1:
    if (flagByte) {
      *(undefined2 *)(entry + 0x48) = 9;
      break;
    }
    if ((*(ushort *)(entry + 0x4a) & 0x80) == 0) {
      value4 = CEntities::ComputeEntitySceneObjectDataDistance3D
                        (value4 + 0xc,g_PlayerEntitySceneObjectData);
      if (0x419 < value4) break;
    }
    else if ((*(ushort *)(entry + 0x4a) & 0x800) != 0) {
LAB_004860d6:
      CEntities::SelectScriptAttachmentSequence(value3,10);
      *(undefined2 *)(entry + 0x48) = 0xf;
      break;
    }
    *(undefined2 *)(entry + 0x48) = 2;
    break;
  case 2:
    if (flagByte) {
      *(undefined2 *)(entry + 0x48) = 10;
    }
    else {
      CEntities::SelectScriptAttachmentSequence(value3,1);
      *(undefined2 *)(entry + 0x48) = 3;
    }
    break;
  case 3:
    if (flagByte) {
      *(undefined2 *)(entry + 0x48) = 10;
      break;
    }
    if (resultFlag == '\0') break;
    if (*(char *)(value4 + 0x75) == '\0') {
      if (0x400 < value2 - value) goto LAB_004860c2;
      if ((*(byte *)(entry + 0x4b) & 4) != 0) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
    }
    else if (0x400 < value) {
LAB_004860c2:
      if ((((*(char *)(value4 + 0x75) == '\0') || ((*(byte *)(entry + 0x4b) & 1) == 0)) ||
          (value < 0x601)) &&
         ((((*(byte *)(entry + 0x4b) & 2) == 0 ||
           (value4 = CEntities::ComputeEntitySceneObjectDataDistance3D
                              (value4 + 0xc,g_PlayerEntitySceneObjectData), 799 < value4)) ||
          (value4 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity), value4 == 0)))) break;
      goto LAB_004860d6;
    }
    CEntities::SelectScriptAttachmentSequence(value3,6);
    *(undefined2 *)(entry + 0x48) = 0xc;
    break;
  case 9:
    if ((*(byte *)(entry + 0x4a) & 8) != 0) {
      CEntities::HandleAnimalScriptEvent(entry,value4,0x107);
    }
    *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
    CEntities::SelectScriptAttachmentSequence(value3,0x12);
    *(undefined2 *)(entry + 0x48) = 0xc;
    break;
  case 10:
    *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
    CEntities::SelectScriptAttachmentSequence(value3,0x18);
    *(undefined2 *)(entry + 0x48) = 0xe;
    break;
  case 0xc:
    if (shortValue == 0) {
      *(undefined2 *)(entry + 0x48) = 0;
    }
    break;
  case 0xe:
    if (shortValue == 2) {
      *(undefined2 *)(entry + 0x48) = 3;
    }
    break;
  case 0xf:
    if (*(char *)(value4 + 0x75) == '\0') {
      if (value2 - value < 0x601) {
        CEntities::AdvanceScriptAttachmentSequence(value3);
        *(undefined2 *)(entry + 0x48) = 3;
      }
    }
    else if (value < 0x601) {
      CEntities::AdvanceScriptAttachmentSequence(value3);
      *(undefined2 *)(entry + 0x48) = 3;
    }
  }
switchD_00485fbd_caseD_4:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

