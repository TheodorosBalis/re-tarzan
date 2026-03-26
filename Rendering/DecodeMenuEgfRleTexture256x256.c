// Address: 0x004988D0

void DecodeMenuEgfRleTexture256x256(int param_1,ushort *param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  
  iVar4 = 0x100;
  do {
    sVar2 = 0;
    puVar6 = param_2;
    do {
      uVar1 = *puVar6;
      param_2 = puVar6 + 1;
      if ((uVar1 & 0x8000) == 0) {
        iVar3 = (int)sVar2;
        sVar2 = sVar2 + 1;
        *(ushort *)(param_1 + iVar3 * 2) = uVar1;
      }
      else {
        iVar3 = (short)(ushort)(byte)*param_2 + 1;
        do {
          iVar5 = (int)sVar2;
          sVar2 = sVar2 + 1;
          iVar3 = iVar3 + -1;
          *(ushort *)(param_1 + iVar5 * 2) = uVar1 & 0x7fff;
        } while (iVar3 != 0);
        param_2 = (ushort *)((int)puVar6 + 3);
      }
      puVar6 = param_2;
    } while (sVar2 < 0x100);
    param_1 = param_1 + 0x200;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


