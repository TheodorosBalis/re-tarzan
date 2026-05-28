
void CEntities__AdvanceScriptAttachmentSequence(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  
  if ((*param_1 & 0xff) == 1) {
    uVar1 = param_1[4];
    if (uVar1 != 0) {
      *(short *)(param_1 + 6) = (short)param_1[6] + 1;
      while( true ) {
        uVar2 = *(uint *)(uVar1 + (short)param_1[6] * 4);
        if (uVar2 != 0) break;
        sVar3 = (short)param_1[6] + 1;
        *(short *)(param_1 + 6) = sVar3;
        *(undefined2 *)(param_1 + 6) = *(undefined2 *)(uVar1 + sVar3 * 4);
      }
      param_1[3] = uVar2;
    }
    *(undefined2 *)((int)param_1 + 0x16) = 0;
    *(undefined2 *)(param_1 + 5) = 0xffff;
  }
  else if ((*param_1 & 0xff) == 2) {
    uVar1 = param_1[4];
    if (uVar1 != 0) {
      *(short *)(param_1 + 6) = (short)param_1[6] + 1;
      while( true ) {
        uVar2 = *(uint *)(uVar1 + (short)param_1[6] * 4);
        if (uVar2 != 0) break;
        sVar3 = (short)param_1[6] + 1;
        *(short *)(param_1 + 6) = sVar3;
        *(undefined2 *)(param_1 + 6) = *(undefined2 *)(uVar1 + sVar3 * 4);
      }
      param_1[3] = uVar2;
    }
    *(undefined2 *)((int)param_1 + 0x16) = 0xffff;
    *(undefined2 *)(param_1 + 5) = 0xffff;
    return;
  }
  return;
}

