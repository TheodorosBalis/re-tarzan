/* Address: 0x0047F110 */

void AdvanceMenuIdleScriptCursor(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  
  puVar4 = (uint *)*param_1;
  if (puVar4 == (uint *)0x0) {
    *param_1 = param_1[1];
    return;
  }
  uVar1 = *puVar4;
  if ((uVar1 & 0x80000000) == 0) {
    *param_1 = (int)(puVar4 + 1);
    *(short *)(param_2 + 0xc) = (short)uVar1;
    return;
  }
  do {
    if (uVar1 == 0x80000001) {
      puVar3 = puVar4 + 2;
      LoadSoundFileAndInitAudio(puVar4[1],0,0);
LAB_0047f168:
      uVar2 = *puVar3;
      puVar4 = puVar3 + 1;
    }
    else {
      if (uVar1 == 0xc0000002) {
        puVar3 = (uint *)puVar4[1];
        goto LAB_0047f168;
      }
      uVar2 = uVar1;
      if (uVar1 == 0xc0000003) {
        uVar2 = (uint)*(ushort *)(param_2 + 0xc);
      }
    }
    if (((uVar1 & 0x40000000) != 0) && (puVar3 = (uint *)param_1[1], puVar3 != (uint *)0x0)) {
      param_1[1] = 0;
      uVar2 = *puVar3;
      puVar4 = puVar3;
    }
    uVar1 = uVar2;
    if ((uVar2 & 0x80000000) == 0) {
      *param_1 = (int)puVar4;
      *(short *)(param_2 + 0xc) = (short)uVar2;
      return;
    }
  } while( true );
}

