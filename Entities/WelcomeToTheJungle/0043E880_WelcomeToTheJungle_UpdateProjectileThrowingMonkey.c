
void WelcomeToTheJungle__UpdateProjectileThrowingMonkey(int param_1)

{
  short sVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  LoadEncodedResourceId(0x1015);
  iVar6 = *(int *)(param_1 + 0x38);
  if ((iVar6 != 0) && (iVar4 = FindRuntimeEntityAttachmentByFlags(param_1,0x400), iVar4 != 0)) {
    sVar3 = CEntities__UpdateScriptedSceneEntryAttachment(param_1);
    iVar7 = (int)sVar3;
    sVar3 = *(short *)(iVar4 + 0x18);
    CEntities__HandleAnimalScriptEvent(param_1,iVar6,iVar7);
    CEntities__MoveSceneEntryAndSnapFacingAngles(param_1,0);
    cVar2 = CEntities__CheckPlayerDamageContact(iVar6);
    if (cVar2 != '\0') {
      g_PlayerDamageContactSceneEntry = iVar6;
      QueuePlayerDamageEvent(param_1,6);
    }
    cVar2 = CEntities__CheckEntityHitByPlayerAttackOrThrowable(param_1);
    if (cVar2 != '\0') {
      if (*(short *)(param_1 + 0x3e) < 1) goto LAB_0043e92e;
      PlayAudioById(0x112,0,iVar6 + 0x14);
      *(undefined2 *)(param_1 + 0x48) = 9;
    }
    if (*(short *)(param_1 + 0x3e) < 1) {
LAB_0043e92e:
      PlayAudioById(0x158,0,iVar6 + 0x14);
      CEntities__ProcessRuntimeEntryDeathAndRelease(param_1,1);
      return;
    }
    switch(*(undefined2 *)(param_1 + 0x48)) {
    case 0:
      *(undefined2 *)(param_1 + 0x48) = 1;
      *(uint *)(param_1 + 0x4c) = (uint)*(ushort *)(param_1 + 0x4a);
      break;
    case 1:
      if (((*(int *)(param_1 + 0x34) == 0) ||
          ((*(byte *)(*(int *)(*(int *)(param_1 + 0x34) + 0x10) + 3) & 1) == 0)) ||
         (iVar7 = FUN_00430d40(param_1,g_PlayerRuntimeEntry), iVar7 != 0)) {
        iVar7 = *(int *)(param_1 + 0x4c) + -1;
        *(int *)(param_1 + 0x4c) = iVar7;
        if ((iVar7 < 1) && (*(int *)(g_PlayerSceneEntry + 0x18) - *(int *)(iVar6 + 0x18) < 300)) {
          *(undefined2 *)(param_1 + 0x48) = 5;
          CEntities__SelectScriptAttachmentSequence(iVar4,0x15);
          iVar6 = RandomModulo(4);
          *(int *)(param_1 + 0x50) = iVar6 + 5;
        }
      }
      else {
        *(undefined2 *)(param_1 + 0x48) = 0xc;
        CEntities__SelectScriptAttachmentSequence(iVar4,7);
      }
      break;
    case 5:
      if (iVar7 == 0xb) {
        iVar4 = GetSceneAttachmentWorldPositionByMask(iVar6,0x100,&uStack_c);
        if ((iVar4 != 0) &&
           (iVar4 = CEntities__SpawnRuntimeEntryByTypeAtPosition
                              (uStack_c,uStack_8,uStack_4,0x1a,0x11), iVar4 != 0)) {
          iVar7 = CEntities__CreateRuntimeEntryAttachment(iVar4,0x9c,0x10000000);
          if (iVar7 == 0) {
            CEntities__ReleaseRuntimeEntryToFreeList(iVar4);
          }
          else {
            *(undefined4 *)(iVar7 + 0x1c) = 6;
            *(undefined2 *)(iVar7 + 0x18) = 0x5a;
            if ((*(int *)(param_1 + 0x34) != 0) &&
               (iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0x34) + 0x10) + 4), iVar4 != 0)) {
              *(short *)(iVar7 + 0x18) = (short)iVar4;
            }
            *(int *)(iVar7 + 0xc) =
                 (short)(&g_SinCosTable12Bit)[*(ushort *)(iVar6 + 0xa2) - 0x400 & 0xfff] * 0x50 >>
                 0xc;
            uVar5 = RandomModulo(0x14);
            *(undefined4 *)(iVar7 + 0x10) = uVar5;
            sVar1 = (&g_SinCosTable12Bit)[*(ushort *)(iVar6 + 0xa2) & 0xfff];
            *(undefined1 *)(iVar7 + 0x20) = 0;
            *(int *)(iVar7 + 0x14) = sVar1 * 0x50 >> 0xc;
          }
        }
      }
      else if (iVar7 == 0x10e) {
        iVar7 = *(int *)(param_1 + 0x50) + -1;
        *(int *)(param_1 + 0x50) = iVar7;
        if (((iVar7 != 0) && (*(int *)(g_PlayerSceneEntry + 0x18) - *(int *)(iVar6 + 0x18) < 300))
           && (iVar6 = FUN_00430d40(param_1,g_PlayerRuntimeEntry), iVar6 != 0)) {
          *(undefined2 *)(iVar4 + 0x16) = 5;
        }
        break;
      }
      if (sVar3 == 0) {
        *(undefined2 *)(param_1 + 0x48) = 0;
      }
      break;
    case 9:
      *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfffc;
      CEntities__SelectScriptAttachmentSequence(iVar4,0x12);
      *(undefined2 *)(param_1 + 0x48) = 0xc;
      break;
    case 0xc:
      if (sVar3 == 0) {
        *(undefined2 *)(param_1 + 0x48) = 1;
      }
    }
  }
  cVar2 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar2 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

