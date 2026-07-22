#include "tarzan_ghidra_types.hpp"

// Address: 0x0047AE60
// Label: JourneyToTheTreeHouse::UpdateBaboon
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateBaboon(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  char resultFlag2;
  short shortValue;
  int value2;
  int value3;
  uint value7;
  int value4;
  int value5;
  undefined4 value6;
  
  LoadEncodedResourceId(0x1013);
  value5 = entity->sceneObjects;
  if ((value5 == 0) ||
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value2 == 0))
  goto switchD_0047b14f_caseD_2;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  value4 = (int)shortValue;
  shortValue = *(short *)(value2 + 0x18);
  if (value4 == 0x10a) {
    *(int *)(entry + 0x50) = *(int *)(entry + 0x50) + 1;
  }
  else if (value4 == 0x10b) {
    *(int *)(entry + 0x50) = *(int *)(entry + 0x50) + -1;
  }
  else if ((value4 == 0x107) && ((*(byte *)(entry + 0x4a) & 0x20) == 0)) {
    *(int *)(entry + 0x50) = -*(int *)(entry + 0x50);
  }
  resultFlag = CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value5,0x26,0x10);
  CEntities::HandleAnimalScriptEvent(entry,value5,value4);
  resultFlag2 = CEntities::CheckPlayerDamageContact(value5);
  if (resultFlag2 != '\0') {
    QueuePlayerDamageEvent(entry,5);
    g_PlayerDamageContactEntitySceneObject = value5;
  }
  resultFlag2 = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag2 != '\0') {
    if ((*(byte *)(entry + 0x4a) & 8) != 0) {
      CEntities::HandleAnimalScriptEvent(entry,value5,0x107);
    }
    if ((*(ushort *)(entry + 0x4a) & 3) == 0) {
      if ((*(ushort *)(entry + 0x4a) & 0x10) == 0) {
        value4 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value5)->surfacePathIndex * 4) + 8 +
                         ((EntitySceneObject *)value5)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
        value = ((EntitySceneObject *)value5)->surfaceIndex;
        value3 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity);
        if (value3 == 0) {
          if (-2 < *(int *)(entry + 0x50)) {
            value3 = CEntities::CanAnimalTraverseJungleSurfaceDistanceWithFacingOverride
                              (entry,value5,0x17c,~*(byte *)(value5 + 0x75));
            if (value3 == 0) {
              if (*(char *)(value5 + 0x75) == '\0') {
LAB_0047b0b1:
                if (value4 - value < 0x17c) {
                  value6 = 10;
                }
                else {
LAB_0047b0c1:
                  value6 = 0x4d;
                }
              }
              else {
                if (0x17b < value) {
                  if (*(char *)(value5 + 0x75) == '\0') goto LAB_0047b0b1;
                  goto LAB_0047b0c1;
                }
                value6 = 10;
              }
              CEntities::SelectScriptAttachmentSequence(value2,value6);
              *(undefined2 *)(entry + 0x48) = 0x14;
            }
            else {
              CEntities::SelectScriptAttachmentSequence(value2,0x43);
              *(undefined2 *)(entry + 0x48) = 0x17;
              *(byte *)(value5 + 0x75) = ~*(byte *)(value5 + 0x75);
            }
            shortValue = -1;
            value7 = RandomModulo(7);
            if ((value7 & 1) == 0) {
              PlayAudioById(0xf9,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
            }
            else {
              PlayAudioById(0xf8,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
            }
          }
        }
        else if (*(int *)(entry + 0x50) < 2) {
          value3 = CEntities::CanAnimalTraverseJungleSurfaceDistance(entry,value5,0x17c);
          if (value3 == 0) {
            if (*(char *)(value5 + 0x75) == '\0') {
LAB_0047aff3:
              if (value < 0x17c) {
                value6 = 10;
              }
              else {
LAB_0047b001:
                value6 = 0xd;
              }
            }
            else {
              if (0x17b < value4 - value) {
                if (*(char *)(value5 + 0x75) == '\0') goto LAB_0047aff3;
                goto LAB_0047b001;
              }
              value6 = 10;
            }
            CEntities::SelectScriptAttachmentSequence(value2,value6);
            *(undefined2 *)(entry + 0x48) = 0x14;
          }
          else {
            CEntities::SelectScriptAttachmentSequence(value2,0x43);
            *(undefined2 *)(entry + 0x48) = 0x17;
          }
          shortValue = -1;
          value7 = RandomModulo(7);
          if ((value7 & 1) == 0) {
            PlayAudioById(0xf9,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
          }
          else {
            PlayAudioById(0xf8,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
          }
        }
      }
      else {
        CEntities::SelectScriptAttachmentSequence(value2,10);
        *(undefined2 *)(entry + 0x48) = 0x14;
        shortValue = -1;
      }
    }
  }
  if (*(short *)(entry + 0x3e) < 1) {
    CEntities::ProcessEntityDeathAndRelease(entry,1);
    return;
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    if (*(int *)(entry + 0x4c) < 1) {
      value5 = RandomModulo(0x32);
      *(int *)(entry + 0x4c) = value5 + 0x32;
    }
    *(undefined2 *)(entry + 0x48) = 1;
    CEntities::SelectScriptAttachmentSequence(value2,0x10);
    break;
  case 1:
    resultFlag = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity);
    if (resultFlag == '\0') {
      value4 = 10000;
    }
    else {
      value4 = CEntities::ComputeEntitySceneObjectDataDistance3D
                        (value5 + 0xc,g_PlayerEntitySceneObjectData);
      if ((value4 < 900) && (0x20 < *(int *)(g_PlayerEntitySceneObject + 0x58))) {
        *(undefined2 *)(entry + 0x48) = 0x14;
        CEntities::SelectScriptAttachmentSequence(value2,0x1d);
        break;
      }
    }
    value = *(int *)(entry + 0x50);
    if (value == 0) {
      if (resultFlag != '\0') {
        if (*(int *)(g_PlayerEntitySceneObject + 0x110) != ((EntitySceneObject *)value5)->surfacePathIndex) break;
        value5 = *(int *)(entry + 0x4c) + -1;
        *(int *)(entry + 0x4c) = value5;
        if (value4 < 0x44d) {
          if ((700 < value4) && (value5 < 0x33)) {
            *(undefined2 *)(entry + 0x48) = 0x14;
            *(undefined4 *)(entry + 0x4c) = 0;
            value6 = RandomModulo(4);
            switch(value6) {
            case 0:
            case 1:
              goto switchD_0047b2a0_caseD_0;
            case 2:
            case 3:
              value7 = RandomModulo(7);
              if ((value7 & 1) != 0) {
                CEntities::SelectScriptAttachmentSequence(value2,0x17);
                goto switchD_0047b14f_caseD_2;
              }
              goto LAB_0047b33a;
            default:
              goto switchD_0047b14f_caseD_2;
            }
          }
        }
        else if (value5 < 1) {
          *(undefined2 *)(entry + 0x48) = 0x14;
          value6 = RandomModulo(6);
          switch(value6) {
          case 0:
          case 1:
switchD_0047b2a0_caseD_0:
            CEntities::SelectScriptAttachmentSequence(value2,0x14);
            break;
          case 2:
          case 3:
            value7 = RandomModulo(7);
            if ((value7 & 1) != 0) {
              CEntities::SelectScriptAttachmentSequence(value2,0x17);
              break;
            }
LAB_0047b33a:
            CEntities::SelectScriptAttachmentSequence(value2,0x1a);
            break;
          case 4:
          case 5:
            CEntities::SelectScriptAttachmentSequence(value2,0x11);
          }
          break;
        }
        if (value4 < 0x28b) {
          *(undefined2 *)(entry + 0x48) = 0x14;
          value7 = RandomModulo(7);
          if ((value7 & 1) == 0) {
            value6 = 0x1a;
          }
          else {
            value6 = 0x17;
          }
          CEntities::SelectScriptAttachmentSequence(value2,value6);
          *(undefined4 *)(entry + 0x4c) = 0;
        }
        break;
      }
      *(undefined2 *)(entry + 0x48) = 0x14;
      value7 = RandomModulo(7);
      if ((value7 & 1) != 0) {
        CEntities::SelectScriptAttachmentSequence(value2,0x23);
        break;
      }
    }
    else {
      if (-1 < value) {
        if (value == 1) {
          CEntities::SelectScriptAttachmentSequence(value2,0x47);
          *(undefined2 *)(entry + 0x48) = 0x19;
        }
        else if (value == 2) {
          CEntities::SelectScriptAttachmentSequence(value2,0x40);
          *(undefined2 *)(entry + 0x48) = 0x16;
        }
        break;
      }
      *(undefined2 *)(entry + 0x48) = 0x14;
      value7 = RandomModulo(7);
      if ((value7 & 1) != 0) {
        CEntities::SelectScriptAttachmentSequence(value2,0x23);
        break;
      }
    }
    CEntities::SelectScriptAttachmentSequence(value2,0x20);
    break;
  case 0x14:
    goto joined_r0x0047b43b;
  case 0x16:
joined_r0x0047b43b:
    if (shortValue == 0x10) {
      *(undefined2 *)(entry + 0x48) = 0;
    }
    break;
  case 0x17:
    if (resultFlag == '\0') {
      ((EntitySceneObject *)value5)->y = ((EntitySceneObject *)value5)->y + 0x40;
    }
    if (((*(uint *)(((EntitySceneObject *)value5)->surface + 0x14) & 0x800) != 0) && (*(int *)(value5 + 0x58) < 8))
    {
      if (entity->descriptor == 0) {
        *(undefined4 *)(entry + 0x4c) = 0x32;
        *(undefined2 *)(entry + 0x48) = 0x18;
      }
      else {
        value6 = *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4);
        *(undefined2 *)(entry + 0x48) = 0x18;
        *(undefined4 *)(entry + 0x4c) = value6;
      }
    }
    break;
  case 0x18:
    if (*(int *)(entry + 0x4c) < 1) {
      CEntities::ProcessEntityDeathAndRelease(entry,1);
    }
    else {
      *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -1;
      if (resultFlag == '\0') {
        ((EntitySceneObject *)value5)->y = ((EntitySceneObject *)value5)->y + 0x40;
      }
    }
    break;
  case 0x19:
    if (shortValue == 0x10) {
      *(undefined2 *)(entry + 0x48) = 0x16;
      CEntities::SelectScriptAttachmentSequence(value2,0x40);
    }
  }
switchD_0047b14f_caseD_2:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

