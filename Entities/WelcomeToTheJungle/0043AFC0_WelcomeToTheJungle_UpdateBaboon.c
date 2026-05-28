
void WelcomeToTheJungle__UpdateBaboon(int param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  
  LoadEncodedResourceId(0x1013);
  iVar9 = *(int *)(param_1 + 0x38);
  if ((iVar9 == 0) || (iVar5 = FindRuntimeEntityAttachmentByFlags(param_1,0x400), iVar5 == 0))
  goto switchD_0043b2af_caseD_2;
  sVar4 = CEntities__UpdateScriptedSceneEntryAttachment(param_1);
  iVar8 = (int)sVar4;
  sVar4 = *(short *)(iVar5 + 0x18);
  if (iVar8 == 0x10a) {
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
  }
  else if (iVar8 == 0x10b) {
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + -1;
  }
  else if ((iVar8 == 0x107) && ((*(byte *)(param_1 + 0x4a) & 0x20) == 0)) {
    *(int *)(param_1 + 0x50) = -*(int *)(param_1 + 0x50);
  }
  cVar2 = CEntities__MoveAnimalFromRuntimeFlagsAndCheckCollision(param_1,iVar9,0x26,0x10);
  CEntities__HandleAnimalScriptEvent(param_1,iVar9,iVar8);
  cVar3 = CEntities__CheckPlayerDamageContact(iVar9);
  if (cVar3 != '\0') {
    QueuePlayerDamageEvent(param_1,5);
    g_PlayerDamageContactSceneEntry = iVar9;
  }
  cVar3 = CEntities__CheckEntityHitByPlayerAttackOrThrowable(param_1);
  if (cVar3 != '\0') {
    if ((*(byte *)(param_1 + 0x4a) & 8) != 0) {
      CEntities__HandleAnimalScriptEvent(param_1,iVar9,0x107);
    }
    if ((*(ushort *)(param_1 + 0x4a) & 3) == 0) {
      if ((*(ushort *)(param_1 + 0x4a) & 0x10) == 0) {
        iVar8 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(iVar9 + 0x110) * 4) + 8 +
                         *(int *)(iVar9 + 0x110) * 4 + g_CollisionSurfaceTable);
        iVar1 = *(int *)(iVar9 + 0x10c);
        iVar6 = FUN_00430d40(param_1,g_PlayerRuntimeEntry);
        if (iVar6 == 0) {
          if (-2 < *(int *)(param_1 + 0x50)) {
            iVar6 = FUN_00430c10(param_1,iVar9,0x17c,~*(byte *)(iVar9 + 0x75));
            if (iVar6 == 0) {
              if (*(char *)(iVar9 + 0x75) == '\0') {
LAB_0043b211:
                if (iVar8 - iVar1 < 0x17c) {
                  uVar10 = 10;
                }
                else {
LAB_0043b221:
                  uVar10 = 0x4d;
                }
              }
              else {
                if (0x17b < iVar1) {
                  if (*(char *)(iVar9 + 0x75) == '\0') goto LAB_0043b211;
                  goto LAB_0043b221;
                }
                uVar10 = 10;
              }
              CEntities__SelectScriptAttachmentSequence(iVar5,uVar10);
              *(undefined2 *)(param_1 + 0x48) = 0x14;
            }
            else {
              CEntities__SelectScriptAttachmentSequence(iVar5,0x43);
              *(undefined2 *)(param_1 + 0x48) = 0x17;
              *(byte *)(iVar9 + 0x75) = ~*(byte *)(iVar9 + 0x75);
            }
            sVar4 = -1;
            uVar7 = RandomModulo(7);
            if ((uVar7 & 1) == 0) {
              PlayAudioById(0xf9,0,iVar9 + 0x14);
            }
            else {
              PlayAudioById(0xf8,0,iVar9 + 0x14);
            }
          }
        }
        else if (*(int *)(param_1 + 0x50) < 2) {
          iVar6 = FUN_00430c40(param_1,iVar9,0x17c);
          if (iVar6 == 0) {
            if (*(char *)(iVar9 + 0x75) == '\0') {
LAB_0043b153:
              if (iVar1 < 0x17c) {
                uVar10 = 10;
              }
              else {
LAB_0043b161:
                uVar10 = 0xd;
              }
            }
            else {
              if (0x17b < iVar8 - iVar1) {
                if (*(char *)(iVar9 + 0x75) == '\0') goto LAB_0043b153;
                goto LAB_0043b161;
              }
              uVar10 = 10;
            }
            CEntities__SelectScriptAttachmentSequence(iVar5,uVar10);
            *(undefined2 *)(param_1 + 0x48) = 0x14;
          }
          else {
            CEntities__SelectScriptAttachmentSequence(iVar5,0x43);
            *(undefined2 *)(param_1 + 0x48) = 0x17;
          }
          sVar4 = -1;
          uVar7 = RandomModulo(7);
          if ((uVar7 & 1) == 0) {
            PlayAudioById(0xf9,0,iVar9 + 0x14);
          }
          else {
            PlayAudioById(0xf8,0,iVar9 + 0x14);
          }
        }
      }
      else {
        CEntities__SelectScriptAttachmentSequence(iVar5,10);
        *(undefined2 *)(param_1 + 0x48) = 0x14;
        sVar4 = -1;
      }
    }
  }
  if (*(short *)(param_1 + 0x3e) < 1) {
    CEntities__ProcessRuntimeEntryDeathAndRelease(param_1,1);
    return;
  }
  switch(*(undefined2 *)(param_1 + 0x48)) {
  case 0:
    if (*(int *)(param_1 + 0x4c) < 1) {
      iVar9 = RandomModulo(0x32);
      *(int *)(param_1 + 0x4c) = iVar9 + 0x32;
    }
    *(undefined2 *)(param_1 + 0x48) = 1;
    CEntities__SelectScriptAttachmentSequence(iVar5,0x10);
    break;
  case 1:
    cVar2 = FUN_00430d40(param_1,g_PlayerRuntimeEntry);
    if (cVar2 == '\0') {
      iVar8 = 10000;
    }
    else {
      iVar8 = CEntities__ComputeSceneEntryDataDistance3D(iVar9 + 0xc,g_PlayerSceneEntryData);
      if ((iVar8 < 900) && (0x20 < *(int *)(g_PlayerSceneEntry + 0x58))) {
        *(undefined2 *)(param_1 + 0x48) = 0x14;
        CEntities__SelectScriptAttachmentSequence(iVar5,0x1d);
        break;
      }
    }
    iVar1 = *(int *)(param_1 + 0x50);
    if (iVar1 == 0) {
      if (cVar2 != '\0') {
        if (*(int *)(g_PlayerSceneEntry + 0x110) != *(int *)(iVar9 + 0x110)) break;
        iVar9 = *(int *)(param_1 + 0x4c) + -1;
        *(int *)(param_1 + 0x4c) = iVar9;
        if (iVar8 < 0x44d) {
          if ((700 < iVar8) && (iVar9 < 0x33)) {
            *(undefined2 *)(param_1 + 0x48) = 0x14;
            *(undefined4 *)(param_1 + 0x4c) = 0;
            uVar10 = RandomModulo(4);
            switch(uVar10) {
            case 0:
            case 1:
              goto switchD_0043b400_caseD_0;
            case 2:
            case 3:
              uVar7 = RandomModulo(7);
              if ((uVar7 & 1) != 0) {
                CEntities__SelectScriptAttachmentSequence(iVar5,0x17);
                goto switchD_0043b2af_caseD_2;
              }
              goto LAB_0043b49a;
            default:
              goto switchD_0043b2af_caseD_2;
            }
          }
        }
        else if (iVar9 < 1) {
          *(undefined2 *)(param_1 + 0x48) = 0x14;
          uVar10 = RandomModulo(6);
          switch(uVar10) {
          case 0:
          case 1:
switchD_0043b400_caseD_0:
            CEntities__SelectScriptAttachmentSequence(iVar5,0x14);
            break;
          case 2:
          case 3:
            uVar7 = RandomModulo(7);
            if ((uVar7 & 1) != 0) {
              CEntities__SelectScriptAttachmentSequence(iVar5,0x17);
              break;
            }
LAB_0043b49a:
            CEntities__SelectScriptAttachmentSequence(iVar5,0x1a);
            break;
          case 4:
          case 5:
            CEntities__SelectScriptAttachmentSequence(iVar5,0x11);
          }
          break;
        }
        if (iVar8 < 0x28b) {
          *(undefined2 *)(param_1 + 0x48) = 0x14;
          uVar7 = RandomModulo(7);
          if ((uVar7 & 1) == 0) {
            uVar10 = 0x1a;
          }
          else {
            uVar10 = 0x17;
          }
          CEntities__SelectScriptAttachmentSequence(iVar5,uVar10);
          *(undefined4 *)(param_1 + 0x4c) = 0;
        }
        break;
      }
      *(undefined2 *)(param_1 + 0x48) = 0x14;
      uVar7 = RandomModulo(7);
      if ((uVar7 & 1) != 0) {
        CEntities__SelectScriptAttachmentSequence(iVar5,0x23);
        break;
      }
    }
    else {
      if (-1 < iVar1) {
        if (iVar1 == 1) {
          CEntities__SelectScriptAttachmentSequence(iVar5,0x47);
          *(undefined2 *)(param_1 + 0x48) = 0x19;
        }
        else if (iVar1 == 2) {
          CEntities__SelectScriptAttachmentSequence(iVar5,0x40);
          *(undefined2 *)(param_1 + 0x48) = 0x16;
        }
        break;
      }
      *(undefined2 *)(param_1 + 0x48) = 0x14;
      uVar7 = RandomModulo(7);
      if ((uVar7 & 1) != 0) {
        CEntities__SelectScriptAttachmentSequence(iVar5,0x23);
        break;
      }
    }
    CEntities__SelectScriptAttachmentSequence(iVar5,0x20);
    break;
  case 0x14:
    goto joined_r0x0043b59b;
  case 0x16:
joined_r0x0043b59b:
    if (sVar4 == 0x10) {
      *(undefined2 *)(param_1 + 0x48) = 0;
    }
    break;
  case 0x17:
    if (cVar2 == '\0') {
      *(int *)(iVar9 + 0x18) = *(int *)(iVar9 + 0x18) + 0x40;
    }
    if (((*(uint *)(*(int *)(iVar9 + 0x114) + 0x14) & 0x800) != 0) && (*(int *)(iVar9 + 0x58) < 8))
    {
      if (*(int *)(param_1 + 0x34) == 0) {
        *(undefined4 *)(param_1 + 0x4c) = 0x32;
        *(undefined2 *)(param_1 + 0x48) = 0x18;
      }
      else {
        uVar10 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x34) + 0x10) + 4);
        *(undefined2 *)(param_1 + 0x48) = 0x18;
        *(undefined4 *)(param_1 + 0x4c) = uVar10;
      }
    }
    break;
  case 0x18:
    if (*(int *)(param_1 + 0x4c) < 1) {
      CEntities__ProcessRuntimeEntryDeathAndRelease(param_1,1);
    }
    else {
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
      if (cVar2 == '\0') {
        *(int *)(iVar9 + 0x18) = *(int *)(iVar9 + 0x18) + 0x40;
      }
    }
    break;
  case 0x19:
    if (sVar4 == 0x10) {
      *(undefined2 *)(param_1 + 0x48) = 0x16;
      CEntities__SelectScriptAttachmentSequence(iVar5,0x40);
    }
  }
switchD_0043b2af_caseD_2:
  cVar2 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar2 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

