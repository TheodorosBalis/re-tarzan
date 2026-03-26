// Address: 0x004AC8D0

void SelectLevelAudioProfile(uint param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  DAT_00c46068 = param_1 & 0x7fffffff;
  puVar2 = (undefined *)0x0;
  switch(DAT_00c46068) {
  case 1:
    puVar2 = &DAT_005179fc;
    break;
  case 2:
    puVar2 = &DAT_00517b20;
    break;
  case 3:
    puVar2 = &DAT_00517c58;
    break;
  case 4:
    puVar2 = &DAT_00517d6c;
    break;
  case 5:
    puVar2 = &DAT_00517e18;
    break;
  case 6:
    puVar2 = &DAT_00517f58;
    break;
  case 7:
    puVar2 = &DAT_00518088;
    break;
  case 8:
    puVar2 = &DAT_00518138;
    break;
  case 9:
    puVar2 = &DAT_0051825c;
    break;
  case 10:
    puVar2 = &DAT_005183a4;
    break;
  case 0xb:
    puVar2 = &DAT_00518580;
    break;
  case 0xc:
    puVar2 = &DAT_00518678;
    break;
  case 0xd:
    puVar2 = &DAT_005187b8;
    break;
  case 0xe:
    puVar2 = &DAT_005188a0;
    break;
  case 0xf:
    puVar2 = &DAT_005189b0;
    break;
  case 0x10:
    puVar2 = &DAT_00518a98;
    break;
  case 0x12:
    puVar2 = &DAT_005184e4;
    break;
  case 0x13:
    puVar2 = &DAT_00518c54;
    break;
  case 0x14:
    puVar2 = &DAT_00518b60;
    break;
  case 0x16:
    puVar2 = &DAT_00518d38;
  }
  if (-1 < (int)param_1) {
    if (((DAT_00c46068 == 0x16) && (-1 < g_SelectedLevelIndex)) &&
       ((short)g_LoadTransitionFlags == -0x7fff)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    SelectECMfileAndInitAudio(uVar3);
  }
  puVar1 = DAT_00c46074;
  if (puVar2 != DAT_00c46074) {
    if (puVar2 != (undefined *)0x0) {
      FUN_004acaa0(puVar2);
    }
    if (DAT_00c46074 != (undefined *)0x0) {
      FUN_004acb00(DAT_00c46074);
    }
    puVar1 = puVar2;
    if (puVar2 != (undefined *)0x0) {
      FUN_004aca50(puVar2);
      FUN_004acad0(puVar2);
    }
  }
  DAT_00c46074 = puVar1;
  return;
}


