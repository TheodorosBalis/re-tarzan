
void CEntities__UpdateThrowableFromPlayer(int param_1)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  
  iVar3 = *(int *)(param_1 + 0x38);
  if ((iVar3 == 0) || (iVar8 = FindRuntimeEntityAttachmentByFlags(param_1,0x800), iVar8 == 0))
  goto LAB_0048b34a;
  switch(*(undefined2 *)(param_1 + 0x48)) {
  case 2:
  case 3:
    goto switchD_0048af20_caseD_2;
  default:
    goto switchD_0048af20_caseD_4;
  case 5:
    *(short *)(iVar3 + 0xa0) = *(short *)(iVar3 + 0xa0) + -0xb6;
    iVar8 = GetSceneAttachmentWorldPositionByMask
                      (g_PlayerSceneEntry,0x100,(undefined4 *)(iVar3 + 0x14));
    if (iVar8 != 0) {
      iVar8 = *(int *)(iVar3 + 0x34);
      if (iVar8 != 0) {
        *(undefined4 *)(iVar8 + 0x14) = *(undefined4 *)(iVar3 + 0x14);
        *(undefined4 *)(iVar8 + 0x18) = *(undefined4 *)(iVar3 + 0x18);
        *(undefined4 *)(iVar8 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
        *(undefined4 *)(iVar8 + 0x3c) = *(undefined4 *)(iVar3 + 0x3c);
        *(undefined4 *)(iVar8 + 0x40) = *(undefined4 *)(iVar3 + 0x40);
        *(undefined4 *)(iVar8 + 0x44) = *(undefined4 *)(iVar3 + 0x44);
      }
      goto LAB_0048b34a;
    }
    goto switchD_0048b2e9_caseD_2027;
  case 6:
    goto switchD_0048af20_caseD_6;
  case 7:
    break;
  }
  *(undefined2 *)(param_1 + 0x48) = 2;
  GetSceneAttachmentWorldPositionByMask(g_PlayerSceneEntry,0x100,iVar3 + 0x14);
  *(undefined4 *)(iVar3 + 0x110) = *(undefined4 *)(g_PlayerSceneEntry + 0x110);
  *(undefined4 *)(iVar3 + 0x10c) = *(undefined4 *)(g_PlayerSceneEntry + 0x10c);
  uVar4 = *(undefined4 *)(g_PlayerSceneEntry + 0x108);
  *(undefined4 *)(iVar3 + 0x6c) = 0xffffffe2;
  *(undefined4 *)(iVar3 + 0x108) = uVar4;
  MoveSceneEntryWithCollision
            ((-(uint)(*(char *)(iVar3 + 0x75) != '\0') & 0xfffffec0) + 0xa0,0,iVar3);
switchD_0048af20_caseD_2:
  iVar13 = *(int *)(iVar8 + 0x1c);
  if ((*(int *)(iVar8 + 0x10) != iVar13) &&
     (iVar9 = *(int *)(iVar8 + 0x10) - *(int *)(iVar8 + 0x18), *(int *)(iVar8 + 0x10) = iVar9,
     iVar9 < iVar13)) {
    *(int *)(iVar8 + 0x10) = iVar13;
  }
  iVar9 = *(int *)(iVar8 + 0x20) + *(int *)(iVar8 + 0x28);
  *(int *)(iVar8 + 0x20) = iVar9;
  iVar13 = *(int *)(iVar8 + 0x2c);
  if (iVar13 < iVar9) {
    *(int *)(iVar8 + 0x20) = iVar13;
  }
  if (*(int *)(iVar8 + 0x20) < -iVar13) {
    *(int *)(iVar8 + 0x20) = -iVar13;
  }
  *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + *(int *)(iVar8 + 0x20);
  if (-0x40 < *(int *)(iVar3 + 0x40)) {
    *(int *)(iVar3 + 0x40) = *(int *)(iVar3 + 0x40) + -4;
  }
  if (((*(byte *)(param_1 + 0x4a) & 1) != 0) &&
     (pbVar5 = *(byte **)(param_1 + 0x50), pbVar5 != (byte *)0x0)) {
    if ((*pbVar5 & 1) == 0) {
      *(undefined4 *)(param_1 + 0x50) = 0;
    }
    else {
      iVar13 = *(int *)(pbVar5 + 0x38);
      if (iVar13 != 0) {
        iVar9 = *(int *)(iVar3 + 0x18);
        iVar6 = *(int *)(iVar13 + 0x18);
        uVar11 = (iVar9 - iVar6) + 0x40;
        uVar10 = (*(int *)(iVar3 + 0x14) - *(int *)(iVar13 + 0x14)) + 0x40;
        uVar12 = (int)uVar10 >> 0x1f;
        if ((int)((uVar11 ^ (int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f)) <
            (int)((uVar10 ^ uVar12) - uVar12)) {
          if ((int)uVar11 < 0) {
LAB_0048b0aa:
            *(int *)(iVar3 + 0x18) = iVar9 + 2;
          }
          else {
            *(int *)(iVar3 + 0x18) = iVar9 + -8;
          }
        }
        else if ((int)uVar11 < 0) {
          if ((~uVar11 + 1 & 0xfffffff0) != 0) goto LAB_0048b0aa;
          *(int *)(iVar3 + 0x18) = iVar6 + -0x40;
        }
        else if ((int)uVar11 >> 4 == 0) {
          *(int *)(iVar3 + 0x18) = iVar6 + -0x40;
        }
        else {
          *(int *)(iVar3 + 0x18) = iVar9 - ((int)uVar11 >> 4);
        }
      }
    }
  }
  if (*(char *)(iVar3 + 0x74) == '\0') {
    *(undefined2 *)(param_1 + 0x48) = 6;
  }
  else {
    *(char *)(iVar3 + 0x74) = *(char *)(iVar3 + 0x74) + -1;
  }
  cVar7 = CEntities__CheckSceneEntryVerticalImpact(iVar3);
  if (cVar7 != '\0') {
    if ((*(byte *)(param_1 + 0x4a) & 8) == 0) {
      iVar13 = *(int *)(iVar8 + 0x10) >> 1;
      *(int *)(iVar8 + 0x20) = -(*(int *)(iVar8 + 0x20) >> 1);
      *(int *)(iVar8 + 0x10) = iVar13;
      *(ushort *)(param_1 + 0x48) = ((1 < iVar13) - 1 & 3) + 3;
    }
    else {
      *(undefined2 *)(param_1 + 0x48) = 6;
    }
  }
  uVar10 = *(uint *)(iVar8 + 0x10);
  if (*(char *)(iVar3 + 0x75) != '\0') {
    uVar10 = ~uVar10 + 1;
  }
  MoveSceneEntryWithCollision(uVar10,0,iVar3);
  piVar1 = (int *)(iVar3 + 0x14);
  *piVar1 = *(int *)(iVar3 + 0x14) + *(int *)(iVar3 + 0x54);
  *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + *(int *)(iVar3 + 0x5c);
  if ((*(byte *)(param_1 + 0x4a) & 2) != 0) {
    iVar13 = *(int *)(iVar3 + 0x34);
    if (iVar13 != 0) {
      *(int *)(iVar13 + 0x14) = *piVar1;
      *(undefined4 *)(iVar13 + 0x18) = *(undefined4 *)(iVar3 + 0x18);
      *(undefined4 *)(iVar13 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
      *(undefined4 *)(iVar13 + 0x3c) = *(undefined4 *)(iVar3 + 0x3c);
      *(undefined4 *)(iVar13 + 0x40) = *(undefined4 *)(iVar3 + 0x40);
      *(undefined4 *)(iVar13 + 0x44) = *(undefined4 *)(iVar3 + 0x44);
    }
    CEntities__SpawnRuntimeEntryByTypeAtPosition
              (*piVar1,*(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 0x1c),0x18,0x11);
  }
  if (*(int *)(iVar3 + 0x108) == 2) {
    sVar2 = *(short *)(iVar3 + 0xa2);
    *(int *)(param_1 + 0x4c) = (int)sVar2;
    if (*(char *)(iVar3 + 0x75) == '\0') {
      *(uint *)(param_1 + 0x4c) = (int)sVar2 ^ 0x800;
    }
    *(undefined2 *)(param_1 + 0x46) = 0x10;
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(g_RuntimeEntityTypeCallbackTable + 0x80);
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(g_RuntimeEntityTypeCallbackTable + 0x84);
    goto LAB_0048b34a;
  }
  *(undefined2 *)(iVar3 + 0xa2) = *(undefined2 *)(iVar3 + 0x132);
  if (*(short *)(param_1 + 0x48) == 3) {
    *(short *)(iVar3 + 0xa0) = *(short *)(iVar3 + 0xa0) + 0x200;
  }
  if ((*(byte *)(iVar3 + 0x13c) & 2) == 0) goto LAB_0048b34a;
switchD_0048af20_caseD_6:
  if (((*(ushort *)(param_1 + 0x4a) & 8) != 0) && (*(char *)(iVar3 + 0x74) != '\0')) {
    FUN_0048bac0(iVar3);
    FUN_0048bee0(iVar3);
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
    return;
  }
  if (((*(ushort *)(param_1 + 0x4a) & 4) != 0) && (*(char *)(iVar3 + 0x74) == '\0')) {
    FUN_0048bb60(iVar3,iVar8);
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
    return;
  }
switchD_0048af20_caseD_4:
  PlayAudioById(0xb8,0,(undefined4 *)(iVar3 + 0x14));
  iVar8 = CEntities__SpawnRuntimeEntryByTypeAtPosition
                    (*(undefined4 *)(iVar3 + 0x14),*(undefined4 *)(iVar3 + 0x18),
                     *(undefined4 *)(iVar3 + 0x1c),0x13,0x11);
  if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x38), iVar8 != 0)) {
    switch(*(undefined2 *)(iVar3 + 0xc)) {
    case 0x2026:
      *(undefined4 *)(iVar8 + 0x24) = 0x600;
      *(undefined4 *)(iVar8 + 0x20) = 0x1000;
      *(undefined4 *)(iVar8 + 0x28) = 0x1000;
      break;
    default:
      goto switchD_0048b2e9_caseD_2027;
    case 0x202b:
      *(undefined4 *)(iVar8 + 0x28) = 0x1000;
      *(undefined4 *)(iVar8 + 0x20) = 0x600;
      *(undefined4 *)(iVar8 + 0x24) = 0x600;
      break;
    case 0x202c:
      *(undefined4 *)(iVar8 + 0x20) = 0x1000;
      *(undefined4 *)(iVar8 + 0x24) = 0x800;
      *(undefined4 *)(iVar8 + 0x28) = 0x800;
      break;
    case 0x202e:
      *(undefined4 *)(iVar8 + 0x28) = 0x600;
      *(undefined4 *)(iVar8 + 0x20) = 0x1000;
      *(undefined4 *)(iVar8 + 0x24) = 0x1000;
    }
    *(undefined4 *)(iVar8 + 0x30) = 0;
  }
switchD_0048b2e9_caseD_2027:
  CEntities__ReleaseRuntimeEntryToFreeList(param_1);
LAB_0048b34a:
  cVar7 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar7 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

