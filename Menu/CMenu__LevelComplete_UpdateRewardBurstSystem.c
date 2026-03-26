// Address: 0x0045E6C0

void CMenu__LevelComplete_UpdateRewardBurstSystem(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  piVar6 = param_1 + 7;
  if (0 < *param_1) {
    *param_1 = *param_1 + -1;
    iVar1 = param_1[3];
    iVar2 = param_1[1] + 0xa0;
    param_1[2] = param_1[2] + (short)(&DAT_0077c788)[param_1[1] & 0xfff] + 0x300;
    param_1[3] = iVar1 + 0xc;
    param_1[1] = iVar2;
    if (0x3ff < iVar2) {
      param_1[1] = 0x400;
    }
    iVar2 = param_1[2] >> 3;
    uVar5 = 0;
    do {
      if ((*(byte *)((int)piVar6 + 0xf) & 0x80) != 0) {
        iVar4 = piVar6[0x55] + (uVar5 & 0x1f) * -4 + -0x40;
        piVar6[0x55] = iVar4;
        if (iVar4 < 1) {
          *(ushort *)((int)piVar6 + 0xe) = *(ushort *)((int)piVar6 + 0xe) & 0x7fff;
        }
        iVar4 = piVar6[0x52];
        uVar3 = iVar1 + 0xc + piVar6[0x56];
        piVar6[0x52] = iVar4 + 9;
        piVar6[5] = ((short)(&DAT_0077c788)[uVar3 - 0x400 & 0xfff] * iVar2 >> 0xc) * piVar6[0x57] >>
                    0xc;
        piVar6[6] = (iVar4 + 9) * iVar2 >> 0xc;
        piVar6[7] = ((short)(&DAT_0077c788)[uVar3 & 0xfff] * iVar2 >> 0xc) * piVar6[0x57] >> 0xc;
        *(ushort *)(piVar6 + 0x29) = (short)piVar6[0x29] + ((ushort)uVar5 & 0x1f) * 8 + -0x40;
        piVar6[0xc] = piVar6[0x55] + -1;
        RenderMenuSceneHierarchy(piVar6);
      }
      piVar6 = piVar6 + 0x58;
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 0x30);
  }
  return;
}


