
undefined4 CEntities__UpdateSceneEntryScript(undefined4 param_1,int param_2,int param_3)

{
  longlong lVar1;
  bool bVar2;
  short sVar3;
  short sVar4;
  undefined4 in_EAX;
  undefined2 uVar7;
  int iVar5;
  int iVar6;
  ushort uVar8;
  
  *(short *)(param_3 + 0x14) = *(short *)(param_3 + 0x14) + -1;
  uVar7 = (undefined2)((uint)in_EAX >> 0x10);
  iVar6 = CONCAT22(uVar7,*(short *)(param_3 + 0x14));
  sVar3 = 0;
  bVar2 = false;
  if (*(short *)(param_3 + 0x14) < 0) {
    do {
      *(short *)(param_3 + 0x16) = *(short *)(param_3 + 0x16) + 1;
      sVar4 = *(short *)(param_3 + 0x16);
      iVar6 = CONCAT22((short)((uint)iVar6 >> 0x10),sVar4);
      iVar5 = *(int *)(param_3 + 0xc);
      uVar8 = *(ushort *)(iVar5 + sVar4 * 2);
      if (-1 < (short)uVar8) break;
      switch(uVar8) {
      case 0x8000:
        *(undefined2 *)(param_3 + 0x16) = 0;
        if (sVar3 == 0) {
          sVar3 = 2;
        }
        break;
      case 0x8001:
        iVar6 = CEntities__AdvanceScriptAttachmentSequence(param_3);
        if (sVar3 == 0) {
          sVar3 = 3;
        }
        break;
      case 0x8002:
        iVar6 = CONCAT31((int3)((uint)iVar6 >> 8),~*(byte *)(param_2 + 0x75));
        *(byte *)(param_2 + 0x75) = ~*(byte *)(param_2 + 0x75);
        break;
      case 0x8003:
        iVar6 = CEntities__ReleaseRuntimeEntryToFreeList(param_1);
        goto LAB_00441fa0;
      case 0x8004:
        iVar6 = CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
LAB_00441fa0:
        uVar8 = 0;
        goto LAB_00441fa5;
      case 0x8005:
        sVar3 = (short)(iVar6 + 1);
        *(short *)(param_3 + 0x16) = sVar3;
        sVar3 = *(short *)(iVar5 + sVar3 * 2);
        iVar6 = CONCAT22((short)((uint)(iVar6 + 1) >> 0x10),sVar3);
        break;
      case 0x8006:
        sVar3 = (short)(iVar6 + 1);
        *(short *)(param_3 + 0x16) = sVar3;
        uVar8 = *(ushort *)(param_2 + 0xc);
        sVar3 = *(short *)(iVar5 + sVar3 * 2);
        iVar6 = CONCAT22((short)((uint)(iVar6 + 1) >> 0x10),sVar3);
        break;
      case 0x8007:
        *(byte *)(param_3 + 0x1e) = *(byte *)(param_3 + 0x1e) | 4;
        break;
      case 0x8008:
        if ((*(byte *)(param_3 + 0x1e) & 4) == 0) {
          sVar4 = (short)(iVar6 + 1);
          *(short *)(param_3 + 0x16) = sVar4;
          uVar7 = *(undefined2 *)(iVar5 + sVar4 * 2);
          iVar6 = CONCAT22((short)((uint)(iVar6 + 1) >> 0x10),uVar7);
          *(undefined2 *)(param_2 + 0x78) = 0;
          *(undefined2 *)(param_2 + 0x76) = uVar7;
          *(byte *)(param_3 + 0x1e) = *(byte *)(param_3 + 0x1e) | 1;
        }
        else {
          sVar4 = (short)(iVar6 + 1);
          *(short *)(param_3 + 0x16) = sVar4;
          uVar7 = *(undefined2 *)(iVar5 + sVar4 * 2);
          iVar6 = CONCAT22((short)((uint)(iVar6 + 1) >> 0x10),uVar7);
          *(undefined2 *)(param_2 + 0x78) = 0;
          *(undefined2 *)(param_2 + 0xc) = uVar7;
          *(byte *)(param_3 + 0x1e) = *(byte *)(param_3 + 0x1e) | 1;
        }
        break;
      case 0x8009:
        sVar4 = (short)(iVar6 + 1);
        *(short *)(param_3 + 0x16) = sVar4;
        uVar7 = *(undefined2 *)(iVar5 + sVar4 * 2);
        iVar6 = CONCAT22((short)((uint)(iVar6 + 1) >> 0x10),uVar7);
        *(undefined2 *)(param_2 + 0x78) = uVar7;
        break;
      case 0x800a:
        sVar4 = (short)(iVar6 + 1);
        *(short *)(param_3 + 0x16) = sVar4;
        uVar7 = *(undefined2 *)(iVar5 + sVar4 * 2);
        iVar6 = CONCAT22((short)((uint)(iVar6 + 1) >> 0x10),uVar7);
        *(undefined2 *)(param_2 + 0x78) = 0;
        *(undefined2 *)(param_2 + 0x76) = uVar7;
        *(byte *)(param_3 + 0x1e) = *(byte *)(param_3 + 0x1e) | 0x82;
        break;
      case 0x800b:
        *(short *)(param_3 + 0x16) = sVar4 + 1;
        lVar1 = 0x100 / (longlong)(*(short *)(iVar5 + (short)(sVar4 + 1) * 2) + 1);
        iVar6 = (int)lVar1;
        *(short *)(param_3 + 0x1c) = (short)lVar1;
        *(undefined2 *)(param_2 + 0x78) = 0;
        *(byte *)(param_3 + 0x1e) = *(byte *)(param_3 + 0x1e) | 2;
        break;
      case 0x800c:
        *(undefined2 *)(param_2 + 0x78) = 0;
        *(undefined2 *)(param_3 + 0x1e) = 0;
        break;
      case 0x800d:
        *(short *)(param_3 + 0x16) = sVar4 + 1;
        sVar4 = *(short *)(iVar5 + (short)(sVar4 + 1) * 2);
        *(undefined2 *)(param_3 + 0x1e) = 6;
        *(undefined2 *)(param_2 + 0x76) = *(undefined2 *)(param_2 + 0xc);
        *(undefined2 *)(param_2 + 0x78) = 0;
        lVar1 = 0x100 / (longlong)(sVar4 + 1);
        iVar6 = (int)lVar1;
        *(short *)(param_3 + 0x1c) = (short)lVar1;
        break;
      case 0x800e:
        *(ushort *)(param_2 + 0xe) = *(ushort *)(param_2 + 0xe) ^ 2;
        break;
      case 0x800f:
        *(ushort *)(param_2 + 0xe) = *(ushort *)(param_2 + 0xe) ^ 4;
        break;
      case 0x8010:
        *(ushort *)(param_2 + 0xe) = *(ushort *)(param_2 + 0xe) ^ 8;
        break;
      case 0x8011:
        *(ushort *)(param_2 + 0xe) = *(ushort *)(param_2 + 0xe) & 0xfff1;
        break;
      case 0x8012:
        *(short *)(param_3 + 0x16) = sVar4 + 1;
        iVar6 = PlayAudioById((int)*(short *)(iVar5 + (short)(sVar4 + 1) * 2),param_2 + 0x104,
                              param_2 + 0x14);
        break;
      case 0x8013:
        *(short *)(param_3 + 0x16) = sVar4 + 1;
        iVar6 = PlayAudioById((int)*(short *)(iVar5 + (short)(sVar4 + 1) * 2),0,param_2 + 0x14);
        break;
      case 0x8014:
        *(short *)(param_3 + 0x16) = sVar4 + 1;
        iVar6 = PlayAudioById((int)*(short *)(iVar5 + (short)(sVar4 + 1) * 2),0,0);
        break;
      case 0x8015:
        bVar2 = true;
        sVar4 = (short)(iVar6 + 1);
        *(short *)(param_3 + 0x16) = sVar4;
        uVar7 = *(undefined2 *)(iVar5 + sVar4 * 2);
        iVar6 = CONCAT22((short)((uint)(iVar6 + 1) >> 0x10),uVar7);
        *(undefined2 *)(param_3 + 0x14) = uVar7;
        break;
      case 0x8016:
        *(short *)(param_3 + 0x16) = sVar4 + 1;
        iVar6 = g_CurrentWorldSceneContext;
        iVar5 = (int)*(short *)(iVar5 + (short)(sVar4 + 1) * 2);
        if (iVar5 == 0x8000) {
          *(int *)(param_2 + 0x10) = g_CurrentWorldSceneContext;
        }
        else {
          iVar6 = g_WorldSceneEntryArrayBase + iVar5 * 0x68;
          *(int *)(param_2 + 0x10) = iVar6;
        }
        break;
      default:
        iVar6 = 0;
        if (*(code **)(&g_ScriptAttachmentWordOpcodeCallbackTable + (short)(uVar8 >> 8 & 0xf) * 8)
            != (code *)0x0) {
          iVar6 = (**(code **)(&g_ScriptAttachmentWordOpcodeCallbackTable +
                              (short)(uVar8 >> 8 & 0xf) * 8))(param_1,param_3,uVar8);
        }
      }
    } while ((short)uVar8 < 0);
LAB_00441fa5:
    if ((*(byte *)(param_3 + 0x1e) & 4) == 0) {
      *(ushort *)(param_2 + 0xc) = uVar8;
    }
    else {
      *(ushort *)(param_2 + 0x76) = uVar8;
    }
    uVar7 = (undefined2)((uint)iVar6 >> 0x10);
    if (!bVar2) {
      *(undefined2 *)(param_3 + 0x14) = **(undefined2 **)(param_3 + 0xc);
    }
    if ((*(byte *)(param_3 + 0x1e) & 0x80) != 0) {
      lVar1 = 0x100 / (longlong)(*(short *)(param_3 + 0x14) + 2);
      uVar7 = (undefined2)((ulonglong)lVar1 >> 0x10);
      *(short *)(param_3 + 0x1c) = (short)lVar1;
    }
  }
  if ((*(byte *)(param_3 + 0x1e) & 2) != 0) {
    *(short *)(param_2 + 0x78) = *(short *)(param_2 + 0x78) + *(short *)(param_3 + 0x1c);
  }
  if (0xff < *(short *)(param_2 + 0x78)) {
    *(undefined2 *)(param_2 + 0x78) = 0;
    *(undefined2 *)(param_3 + 0x1e) = 0;
    *(undefined2 *)(param_2 + 0xc) = *(undefined2 *)(param_2 + 0x76);
  }
  return CONCAT22(uVar7,sVar3);
}

