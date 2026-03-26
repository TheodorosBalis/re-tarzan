// Address: 0x004A8040

char PlaySoundID(ushort param_1,byte param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  short sVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (((g_IsDSoundInitialized != 0) && (DAT_009e4a4c == 0)) && (param_1 < 2000)) {
    iVar7 = (int)(short)param_1;
    iVar6 = iVar7 * 0x2c;
    if ((((&DAT_009cf220)[iVar7 * 0xb] != 0) &&
        ((DAT_009e4a50 == 0 || (((&DAT_009cf246)[iVar6] & 1) != 0)))) &&
       ((&DAT_009cf247)[iVar6 + *(short *)(&DAT_009cf244 + iVar6)] == '\0')) {
      cVar3 = FUN_004a81b0();
      if (cVar3 != -1) {
        iVar5 = (int)cVar3;
        sVar1 = *(short *)(&DAT_009cf244 + iVar6);
        (&DAT_009e49e0)[iVar5 * 2] = param_1;
        (&DAT_009e49e2)[iVar5 * 2] = sVar1;
        if ((param_2 < 0x65) &&
           (piVar2 = (int *)(&DAT_009cf220)[iVar7 * 0xb + (int)sVar1], piVar2 != (int *)0x0)) {
          (**(code **)(*piVar2 + 0x3c))(piVar2,(int)(short)(&g_DSoundVolumeCurve)[(char)param_2]);
        }
        piVar2 = *(int **)(&DAT_009cf230 +
                          ((int)(short)(&DAT_009e49e2)[iVar5 * 2] + iVar7 * 0xb) * 4);
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x4c))(piVar2,param_3,param_4,param_5,0);
        }
        if ((DAT_009e4a50 == 0) &&
           (piVar2 = (int *)(&DAT_009cf220)[(int)*(short *)(&DAT_009cf244 + iVar6) + iVar7 * 0xb],
           piVar2 != (int *)0x0)) {
          (**(code **)(*piVar2 + 0x30))(piVar2,0,0,(&DAT_009cf246)[iVar6] & 1);
        }
        (&DAT_009cf247)[iVar6 + *(short *)(&DAT_009cf244 + iVar6)] = 1;
        uVar4 = (int)*(short *)(&DAT_009cf244 + iVar6) + 1U & 0x80000003;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
        }
        *(short *)(&DAT_009cf244 + iVar6) = (short)uVar4;
        return cVar3;
      }
    }
  }
  return -1;
}


