
void WelcomeToTheJungle__UpdateBird(int param_1)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  
  sVar6 = 0;
  iVar3 = *(int *)(param_1 + 0x38);
  if (iVar3 == 0) goto LAB_0043be90;
  if (g_LevelTransitionContext._2_1_ == '\r') {
    cVar5 = CEntities__IsSceneEntryWithinCameraYawWindow(iVar3,600);
    if (cVar5 == '\0') {
      *(byte *)(iVar3 + 0xf) = *(byte *)(iVar3 + 0xf) | 0x80;
    }
    else {
      *(ushort *)(iVar3 + 0xe) = *(ushort *)(iVar3 + 0xe) & 0x7fff;
    }
  }
  if (*(short *)(param_1 + 0x48) == 6) {
    cVar5 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
    if (cVar5 == '\0') {
      return;
    }
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
    return;
  }
  iVar7 = FindRuntimeEntityAttachmentByFlags(param_1,0x400);
  if (iVar7 == 0) goto LAB_0043be90;
  if ((*(byte *)(param_1 + 0x4a) & 1) == 0) {
    sVar1 = 0;
  }
  else {
    sVar6 = CEntities__UpdateScriptedSceneEntryAttachment(param_1);
    sVar1 = *(short *)(iVar7 + 0x18);
  }
  iVar8 = FindRuntimeEntityAttachmentByFlags(param_1,0x10000000);
  if (iVar8 == 0) goto LAB_0043be90;
  if (sVar6 == 0x10f) {
    uVar9 = RandomModulo(4);
    switch(uVar9) {
    case 0:
      uVar9 = 0x113;
      break;
    case 1:
      uVar9 = 0x114;
      break;
    case 2:
      uVar9 = 0x115;
      break;
    case 3:
      uVar9 = 0x116;
      break;
    default:
      goto switchD_0043ba83_default;
    }
    PlayAudioById(uVar9,0,iVar3 + 0x14);
  }
switchD_0043ba83_default:
  if (*(code **)(iVar8 + 0xc) != (code *)0x0) {
    (**(code **)(iVar8 + 0xc))(param_1,iVar3);
  }
  if (((*(byte *)(param_1 + 0x4a) & 0x10) != 0) &&
     (cVar5 = CEntities__CheckPlayerDamageContact(iVar3), cVar5 != '\0')) {
    QueuePlayerDamageEvent(param_1,0x2006);
    g_PlayerDamageContactSceneEntry = iVar3;
  }
  iVar4 = *(int *)(iVar3 + 0x114);
  if (iVar4 == 0) {
    return;
  }
  if ((*(byte *)(iVar4 + 0x14) & 4) != 0) {
    *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 0x80;
  }
  if (*(ushort *)(iVar8 + 0x10) < *(ushort *)(iVar8 + 0x14)) {
    *(ushort *)(iVar3 + 0xa0) =
         ~((*(ushort *)(iVar8 + 0x14) - *(ushort *)(iVar8 + 0x10)) * 8) & 0xfff;
  }
  switch(*(undefined2 *)(param_1 + 0x48)) {
  case 0:
    iVar8 = *(int *)(param_1 + 0x4c) + -1;
    *(int *)(param_1 + 0x4c) = iVar8;
    if (-1 < iVar8) break;
    uVar9 = RandomModulo(4);
    switch(uVar9) {
    case 0:
    case 1:
      uVar9 = 7;
      break;
    case 2:
    case 3:
      uVar9 = 4;
      break;
    default:
      goto switchD_0043bb67_default;
    }
    CEntities__SelectScriptAttachmentSequence(iVar7,uVar9);
switchD_0043bb67_default:
    *(undefined2 *)(param_1 + 0x48) = 4;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    break;
  case 1:
    if (*(short *)(iVar4 + 0x12) == 0) {
      uVar2 = *(undefined2 *)(iVar8 + 0x10);
LAB_0043bcdb:
      WelcomeToTheJungle__MoveBirdAndEaseFacingAngles(param_1,uVar2);
    }
    else {
      iVar7 = (int)*(short *)(iVar4 + 0x12);
      if (*(short *)(iVar8 + 0x16) == 0) {
        uVar2 = *(undefined2 *)(iVar8 + 0x10);
        goto LAB_0043bcdb;
      }
      if (0 < *(int *)(iVar3 + 0x40)) {
        *(int *)(iVar8 + 0x24) = -*(int *)(iVar8 + 0x24);
        *(undefined4 *)(iVar3 + 0x40) = 0;
      }
      if (-iVar7 != *(int *)(iVar3 + 0x40) && iVar7 <= -*(int *)(iVar3 + 0x40)) {
        *(int *)(iVar8 + 0x24) = -*(int *)(iVar8 + 0x24);
        if ((*(byte *)(param_1 + 0x4b) & 2) != 0) {
          *(undefined2 *)(iVar8 + 0x16) = 0;
          *(undefined4 *)(iVar8 + 0x24) = 0;
        }
        *(int *)(iVar3 + 0x40) = -iVar7;
      }
      WelcomeToTheJungle__MoveBirdAndEaseFacingAngles(param_1,*(undefined2 *)(iVar8 + 0x10));
      *(int *)(iVar3 + 0x40) = *(int *)(iVar3 + 0x40) + *(int *)(iVar8 + 0x24);
      *(short *)(iVar8 + 0x22) = *(short *)(iVar8 + 0x22) + -1;
      if (*(short *)(iVar8 + 0x22) == 0) {
        if (*(int *)(iVar8 + 0x24) == 0) {
          iVar7 = RandomModulo((uint)*(ushort *)(iVar8 + 0x16) << 1);
          *(uint *)(iVar8 + 0x24) = (uint)*(ushort *)(iVar8 + 0x16) - iVar7;
          sVar6 = RandomModulo(100);
          *(short *)(iVar8 + 0x22) = sVar6 + 0x32;
        }
        else {
          *(undefined4 *)(iVar8 + 0x24) = 0;
          sVar6 = RandomModulo(200);
          *(short *)(iVar8 + 0x22) = sVar6 + 0x32;
        }
      }
    }
    if (((*(byte *)(param_1 + 0x4a) & 8) == 0) &&
       (iVar7 = *(int *)(param_1 + 0x4c) + -1, *(int *)(param_1 + 0x4c) = iVar7, iVar7 < 0)) {
      iVar7 = RandomModulo(200);
      *(int *)(param_1 + 0x4c) = iVar7 + 0xb4;
      *(undefined2 *)(param_1 + 0x48) = 2;
    }
    break;
  case 2:
    if (*(short *)(iVar8 + 0x10) == 0) {
      WelcomeToTheJungle__MoveBirdAndEaseFacingAngles(param_1,0);
      *(undefined2 *)(param_1 + 0x48) = 3;
    }
    else {
      sVar6 = *(short *)(iVar8 + 0x10) + -1;
LAB_0043bd22:
      *(short *)(iVar8 + 0x10) = sVar6;
      WelcomeToTheJungle__MoveBirdAndEaseFacingAngles(param_1,sVar6);
    }
    break;
  case 3:
    *(byte *)(iVar3 + 0x75) = ~*(byte *)(iVar3 + 0x75);
    WelcomeToTheJungle__MoveBirdAndEaseFacingAngles(param_1,0);
    *(undefined2 *)(param_1 + 0x48) = 5;
    break;
  case 4:
    if ((sVar6 == 0x100) && (*(int *)(param_1 + 0x4c) == 0)) {
      iVar8 = RandomModulo(0x14);
      *(int *)(param_1 + 0x4c) = iVar8 + 0xf;
      *(int *)(param_1 + 0x50) = *(short *)(iVar7 + 0x16) + -3;
    }
    else if (1 < *(int *)(param_1 + 0x4c)) {
      *(undefined2 *)(iVar7 + 0x16) = *(undefined2 *)(param_1 + 0x50);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
    }
    if (sVar1 == 1) {
      *(undefined2 *)(param_1 + 0x48) = 0;
      iVar7 = RandomModulo(0x1e);
      *(int *)(param_1 + 0x4c) = iVar7 + 0x28;
    }
    break;
  case 5:
    if (*(ushort *)(iVar8 + 0x10) < *(ushort *)(iVar8 + 0x14)) {
      sVar6 = *(short *)(iVar8 + 0x12) + *(ushort *)(iVar8 + 0x10);
      goto LAB_0043bd22;
    }
    WelcomeToTheJungle__MoveBirdAndEaseFacingAngles(param_1,*(ushort *)(iVar8 + 0x14));
    *(undefined2 *)(param_1 + 0x48) = 1;
  }
  if (((*(ushort *)(param_1 + 0x4a) & 2) != 0) && ((*(byte *)(iVar3 + 0x13c) & 2) != 0)) {
    if ((*(ushort *)(param_1 + 0x4a) & 4) != 0) {
      CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed();
      return;
    }
    goto LAB_0043be9e;
  }
  uVar10 = *(uint *)(iVar4 + 0x14);
  if (*(char *)(iVar3 + 0x75) == '\0') {
    if ((((uVar10 & 0xc000) != 0) &&
        (uVar11 = (uint)*(ushort *)(iVar4 + 0x18), uVar11 != *(uint *)(iVar3 + 0x110))) &&
       (((uVar10 & 1) != 0 && (uVar10 = RandomModulo(0x40), (uVar10 & 7) == 0)))) {
      iVar7 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + uVar11 * 4) + 0x40 +
                       ((uint)*(ushort *)(iVar4 + 0x1a) * 7 + uVar11) * 4 + g_CollisionSurfaceTable)
      ;
      iVar8 = *(int *)(iVar4 + 0xc);
LAB_0043be7a:
      *(uint *)(iVar3 + 0x110) = uVar11;
      *(int *)(iVar3 + 0x10c) = *(int *)(iVar3 + 0x10c) + (iVar7 - iVar8);
    }
  }
  else if (((((uVar10 & 0x2000) == 0) && ((*(uint *)(iVar4 + 0x30) & 0xc000) != 0)) &&
           ((*(uint *)(iVar4 + 0x30) & 2) != 0)) &&
          ((uVar11 = (uint)*(ushort *)(iVar4 + 0x34), uVar11 != *(uint *)(iVar3 + 0x110) &&
           (uVar10 = RandomModulo(0x40), (uVar10 & 7) == 0)))) {
    iVar7 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + uVar11 * 4) + 0x40 +
                     ((uint)*(ushort *)(iVar4 + 0x36) * 7 + uVar11) * 4 + g_CollisionSurfaceTable);
    iVar8 = *(int *)(iVar4 + 0x28);
    goto LAB_0043be7a;
  }
LAB_0043be90:
  cVar5 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar5 == '\0') {
    return;
  }
LAB_0043be9e:
  CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  return;
}

