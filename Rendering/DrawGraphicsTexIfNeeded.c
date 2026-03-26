// Address: 0x0049AFE0

void DrawGraphicsTexIfNeeded(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  
  iVar2 = ReadFromGlobal722994();
  if (iVar2 != DAT_00515c50) {
    DAT_00722810 = 0x78;
    DAT_00515c50 = iVar2;
  }
  DAT_00722810 = DAT_00722810 + -1;
  if (DAT_00722810 < 0) {
    return;
  }
  uVar3 = CurrentGraphicsMode();
  switch(uVar3) {
  case 1:
    pcVar7 = s_GLIDE_3D_CARD_00515cec;
    break;
  case 2:
    uVar5 = 0xffffffff;
    pcVar7 = s_DIRECT3D_CARD_00515cdc;
    do {
      pcVar8 = pcVar7;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar7 = pcVar8 + -uVar5;
    pcVar8 = (char *)&DAT_007223f4;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    goto LAB_0049b097;
  case 3:
    pcVar7 = s_SOFTWARE_LOW_RES_00515cc8;
    break;
  case 4:
    uVar5 = 0xffffffff;
    pcVar7 = s_SOFTWARE_HIGH_RES_00515cb4;
    do {
      pcVar8 = pcVar7;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar7 = pcVar8 + -uVar5;
    pcVar8 = (char *)&DAT_007223f4;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    goto LAB_0049b097;
  case 5:
    pcVar7 = s_SOFTWARE_WINDOW_00515ca4;
    break;
  default:
    goto switchD_0049b01e_default;
  }
  uVar5 = 0xffffffff;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_007223f4;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
LAB_0049b097:
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  iVar2 = Return6();
  iVar4 = GetWindowHeight(&DAT_007223f4);
  iVar2 = Return6_2(iVar4 - iVar2);
  uVar5 = 0xffffffff;
  pcVar7 = (char *)&DAT_007223f4;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  iVar4 = GetWindowWidth();
  DrawGraphicsTextInMem_stub(iVar4 - iVar2 * (~uVar5 - 1));
  iVar2 = FUN_004a79e0();
  if (iVar2 == 0) {
    pcVar7 = s_NO_SOUND_CARD_FOUND_00515c6c;
  }
  else {
    iVar2 = FUN_004a79c0();
    pcVar7 = s_EAX_SOUND_CARD_00515c94;
    if (iVar2 == 0) {
      pcVar7 = s_DIRECTSOUND_CARD_00515c80;
    }
  }
  DrawGraphicsTextinMem_2(&DAT_007223f4,&DAT_00515c68,pcVar7);
  iVar2 = Return6(&DAT_007223f4);
  iVar4 = GetWindowHeight();
  iVar2 = Return6_2(iVar4 + iVar2 * -2);
  uVar5 = 0xffffffff;
  pcVar7 = (char *)&DAT_007223f4;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  iVar4 = GetWindowWidth();
  DrawGraphicsTextInMem_stub(iVar4 - iVar2 * (~uVar5 - 1));
  pcVar7 = s_MMX_CPU_00515c60;
  if (DAT_00c46c44 == 0) {
    pcVar7 = &DAT_00515c58;
  }
  uVar5 = 0xffffffff;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (char *)&DAT_007223f4;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  iVar2 = Return6(&DAT_007223f4);
  iVar4 = GetWindowHeight();
  iVar2 = Return6_2(iVar4 + iVar2 * -3);
  uVar5 = 0xffffffff;
  pcVar7 = (char *)&DAT_007223f4;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  iVar4 = GetWindowWidth();
  DrawGraphicsTextInMem_stub(iVar4 - iVar2 * (~uVar5 - 1));
switchD_0049b01e_default:
  return;
}


