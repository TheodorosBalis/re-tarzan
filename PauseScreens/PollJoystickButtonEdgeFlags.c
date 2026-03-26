// Address: 0x0049DF80

uint PollJoystickButtonEdgeFlags(UINT param_1)

{
  uint uVar1;
  MMRESULT MVar2;
  uint *puVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  joyinfoex_tag *pjVar7;
  joyinfoex_tag local_34;
  
  uVar6 = 0;
  if ((&DAT_00723cd8)[param_1] != '\0') {
    pjVar7 = &local_34;
    for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {
      pjVar7->dwSize = 0;
      pjVar7 = (joyinfoex_tag *)&pjVar7->dwFlags;
    }
    local_34.dwSize = 0x34;
    local_34.dwFlags = 0x483;
    MVar2 = joyGetPosEx(param_1,&local_34);
    if (MVar2 == 0) {
      bVar4 = 0;
      puVar3 = &DAT_00516290;
      do {
        if ((*puVar3 & local_34.dwButtons) != 0) {
          uVar6 = uVar6 | 1 << (bVar4 & 0x1f);
        }
        puVar3 = puVar3 + 1;
        bVar4 = bVar4 + 1;
      } while ((int)puVar3 < 0x516300);
      if (local_34.dwXpos < (uint)(&DAT_00723c54)[param_1]) {
        uVar6 = uVar6 | 0x10000000;
      }
      if ((uint)(&DAT_00723c14)[param_1] < local_34.dwXpos) {
        uVar6 = uVar6 | 0x20000000;
      }
      if (local_34.dwYpos < (uint)(&DAT_007237d4)[param_1]) {
        uVar6 = uVar6 | 0x40000000;
      }
      if ((uint)(&DAT_00723c98)[param_1] < local_34.dwYpos) {
        uVar6 = uVar6 | 0x80000000;
      }
      uVar1 = (&DAT_00723ce8)[param_1];
      (&DAT_00723ce8)[param_1] = uVar1 & uVar6;
      return ~(uVar1 & uVar6) & uVar6;
    }
  }
  return 0;
}


