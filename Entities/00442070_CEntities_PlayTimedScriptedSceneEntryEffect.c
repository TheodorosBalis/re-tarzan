
undefined4 CEntities__PlayTimedScriptedSceneEntryEffect(undefined4 param_1,int param_2,int param_3)

{
  ushort *puVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  short sVar5;
  longlong lVar6;
  int iVar7;
  undefined4 in_EAX;
  undefined2 uVar9;
  int iVar8;
  ushort uVar10;
  
  *(short *)(param_3 + 0x14) = *(short *)(param_3 + 0x14) + -1;
  uVar9 = (undefined2)((uint)in_EAX >> 0x10);
  uVar2 = 0;
  if (*(short *)(param_3 + 0x14) < 0) {
    do {
      *(short *)(param_3 + 0x16) = *(short *)(param_3 + 0x16) + 1;
      iVar7 = g_CurrentWorldSceneContext;
      uVar10 = *(ushort *)(*(int *)(param_3 + 0xc) + *(short *)(param_3 + 0x16) * 4);
      iVar8 = *(int *)(param_3 + 0xc) + *(short *)(param_3 + 0x16) * 4;
      if (-1 < (short)uVar10) break;
      uVar9 = (undefined2)((uint)iVar8 >> 0x10);
      switch(uVar10) {
      case 0x8000:
        *(undefined2 *)(param_3 + 0x16) = 0xffff;
        uVar2 = 2;
        break;
      case 0x8001:
        iVar8 = CEntities__AdvanceScriptAttachmentSequence(param_3);
        uVar2 = 3;
        break;
      case 0x8002:
        iVar8 = CONCAT31((int3)((uint)iVar8 >> 8),~*(byte *)(param_2 + 0x75));
        *(byte *)(param_2 + 0x75) = ~*(byte *)(param_2 + 0x75);
        break;
      case 0x8003:
        iVar8 = CEntities__ReleaseRuntimeEntryToFreeList(param_1);
        goto LAB_004422a8;
      case 0x8004:
        iVar8 = CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
LAB_004422a8:
        uVar10 = 0;
        goto LAB_004422ad;
      case 0x8005:
        uVar2 = *(undefined2 *)(iVar8 + 2);
        break;
      case 0x8006:
        uVar2 = *(undefined2 *)(iVar8 + 2);
        uVar10 = *(ushort *)(param_2 + 0xc);
        break;
      case 0x8007:
        *(byte *)(param_3 + 0x1e) = *(byte *)(param_3 + 0x1e) | 4;
        break;
      case 0x8008:
        if ((*(byte *)(param_3 + 0x1e) & 4) == 0) {
          uVar9 = *(undefined2 *)(iVar8 + 2);
          *(undefined2 *)(param_2 + 0x78) = 0;
          *(undefined2 *)(param_2 + 0x76) = uVar9;
          *(byte *)(param_3 + 0x1e) = *(byte *)(param_3 + 0x1e) | 1;
        }
        else {
          uVar3 = *(undefined2 *)(iVar8 + 2);
          iVar8 = CONCAT22(uVar9,uVar3);
          *(undefined2 *)(param_2 + 0x78) = 0;
          *(undefined2 *)(param_2 + 0xc) = uVar3;
          *(byte *)(param_3 + 0x1e) = *(byte *)(param_3 + 0x1e) | 1;
        }
        break;
      case 0x8009:
        *(undefined2 *)(param_2 + 0x78) = *(undefined2 *)(iVar8 + 2);
        break;
      case 0x800a:
        uVar3 = *(undefined2 *)(iVar8 + 2);
        iVar8 = CONCAT22(uVar9,uVar3);
        *(undefined2 *)(param_2 + 0x78) = 0;
        *(undefined2 *)(param_2 + 0x76) = uVar3;
        *(byte *)(param_3 + 0x1e) = *(byte *)(param_3 + 0x1e) | 0x82;
        break;
      case 0x800b:
        puVar1 = (ushort *)(iVar8 + 2);
        iVar8 = 0;
        *(short *)(param_3 + 0x1c) = (short)(0x100 / (ulonglong)(longlong)(int)(*puVar1 + 1));
        *(undefined2 *)(param_2 + 0x78) = 0;
        *(byte *)(param_3 + 0x1e) = *(byte *)(param_3 + 0x1e) | 2;
        break;
      case 0x800c:
        *(undefined2 *)(param_2 + 0x78) = 0;
        *(undefined2 *)(param_3 + 0x1e) = 0;
        break;
      case 0x800d:
        uVar4 = *(ushort *)(iVar8 + 2);
        *(undefined2 *)(param_3 + 0x1e) = 6;
        *(undefined2 *)(param_2 + 0x76) = *(undefined2 *)(param_2 + 0xc);
        iVar8 = 0;
        *(undefined2 *)(param_2 + 0x78) = 0;
        *(short *)(param_3 + 0x1c) = (short)(0x100 / (ulonglong)(longlong)(int)(uVar4 + 1));
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
        iVar8 = PlayAudioById(*(undefined2 *)(iVar8 + 2),param_2 + 0x104,param_2 + 0x14);
        break;
      case 0x8013:
        iVar8 = PlayAudioById(*(undefined2 *)(iVar8 + 2),0,param_2 + 0x14);
        break;
      case 0x8014:
        iVar8 = PlayAudioById(*(undefined2 *)(iVar8 + 2),0,0);
        break;
      default:
        iVar8 = 0;
        if (*(code **)(&g_ScriptAttachmentTimedOpcodeCallbackTable + (short)(uVar10 >> 8 & 0xf) * 8)
            != (code *)0x0) {
          iVar8 = (**(code **)(&g_ScriptAttachmentTimedOpcodeCallbackTable +
                              (short)(uVar10 >> 8 & 0xf) * 8))(param_1,param_3,uVar10);
        }
        break;
      case 0x8016:
        if (*(ushort *)(iVar8 + 2) == 0x8000) {
          *(int *)(param_2 + 0x10) = g_CurrentWorldSceneContext;
          iVar8 = iVar7;
        }
        else {
          iVar8 = g_WorldSceneEntryArrayBase + (uint)*(ushort *)(iVar8 + 2) * 0x68;
          *(int *)(param_2 + 0x10) = iVar8;
        }
      }
    } while ((short)uVar10 < 0);
LAB_004422ad:
    if ((*(byte *)(param_3 + 0x1e) & 4) == 0) {
      *(ushort *)(param_2 + 0xc) = uVar10;
    }
    else {
      *(ushort *)(param_2 + 0x76) = uVar10;
    }
    sVar5 = *(short *)(*(int *)(param_3 + 0xc) + 2 + *(short *)(param_3 + 0x16) * 4);
    uVar9 = (undefined2)((uint)iVar8 >> 0x10);
    *(short *)(param_3 + 0x14) = sVar5;
    if ((*(byte *)(param_3 + 0x1e) & 0x80) != 0) {
      lVar6 = 0x100 / (longlong)(sVar5 + 2);
      uVar9 = (undefined2)((ulonglong)lVar6 >> 0x10);
      *(short *)(param_3 + 0x1c) = (short)lVar6;
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
  return CONCAT22(uVar9,uVar2);
}

