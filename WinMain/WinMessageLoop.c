// Address: 0x004AECB0

void WinMessageLoop(void)

{
  char cVar1;
  BOOL BVar2;
  int iVar3;
  DWORD DVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  char *pcVar9;
  char *pcVar10;
  tagPOINT tStack_128;
  int local_120;
  tagMSG local_11c;
  char cStack_100;
  undefined4 uStack_ff;
  
  do {
    g_MainWindowMessagePulseCount = 0;
    local_120 = 0;
    do {
      BVar2 = PeekMessageA(&local_11c,(HWND)0x0,0,0,0);
      if (BVar2 == 0) break;
      BVar2 = GetMessageA(&local_11c,(HWND)0x0,0,0);
      if (BVar2 == 0) {
        ExitIfFailed2();
      }
      TranslateMessage(&local_11c);
      DispatchMessageA(&local_11c);
      local_120 = local_120 + 1;
    } while (local_120 < 0x14);
    if (g_MainWindowActivationState == 1) {
      g_MainWindowActivationState = 0;
    }
    ReadUseIsPauseOptionsMenuRequested();
    iVar3 = HasPendingGraphicsModeChange();
    if (iVar3 != 0) {
      PauseAudioLinePlayback();
      StopActiveStreamedWork();
    }
    RunLegacyHandlersOrUpdateFrame();
    iVar3 = ConsumeGraphicsModeFailure(&local_120);
    if (iVar3 != 0) {
      cStack_100 = DAT_00724234;
      puVar8 = &uStack_ff;
      for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      *(undefined2 *)puVar8 = 0;
      *(undefined1 *)((int)puVar8 + 2) = 0;
      switch(local_120) {
      case 1:
        uVar6 = 0xffffffff;
        pcVar10 = s_COMPATIBLE_CARD_NOT_FOUND_00518f6c;
        do {
          pcVar9 = pcVar10;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar9 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar9;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        pcVar9 = pcVar9 + -uVar6;
        break;
      case 2:
        uVar6 = 0xffffffff;
        pcVar10 = s_CARD_NOT_SUITABLE_00518f58;
        do {
          pcVar9 = pcVar10;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar9 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar9;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        pcVar9 = pcVar9 + -uVar6;
        break;
      case 3:
        uVar6 = 0xffffffff;
        pcVar10 = s_FAILED_TO_SETUP_CARD_00518f40;
        do {
          pcVar9 = pcVar10;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar9 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar9;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        pcVar9 = pcVar9 + -uVar6;
        break;
      case 4:
        uVar6 = 0xffffffff;
        pcVar10 = s_IT_CONFLICTS_WITH_A_PREVIOUS_MOD_00518f1c;
        do {
          pcVar9 = pcVar10;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar9 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar9;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        pcVar9 = pcVar9 + -uVar6;
        break;
      default:
        goto switchD_004aed82_default;
      }
      tStack_128.x = (LONG)&cStack_100;
      pcVar10 = (char *)tStack_128.x;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
switchD_004aed82_default:
      switch(iVar3) {
      case 1:
        if (DAT_00724ed0 == 0) {
          pcVar10 = s_GLIDE_3D_NOT_AVAILABLE_00518f04;
LAB_004aee78:
          ShowTwoLineOptionsMessage(pcVar10,&cStack_100);
        }
        break;
      case 2:
        if (DAT_00724ed0 == 0) {
          pcVar10 = s_DIRECT3D_NOT_AVAILABLE_00518eec;
          goto LAB_004aee78;
        }
        break;
      case 3:
        if (DAT_00724ed0 == 0) {
          pcVar10 = s_DDRAW_LOW_RES_NOT_AVAILABLE_00518ed0;
          goto LAB_004aee78;
        }
        break;
      case 4:
        if (DAT_00724ed0 == 0) {
          pcVar10 = s_DDRAW_HIGH_RES_NOT_AVAILABLE_00518eb0;
          goto LAB_004aee78;
        }
      }
    }
    SetIsWindowActive();
    if ((g_MainWindowActivationState == 0) || (g_IsMainWindowMinimized != 0)) {
      WaitMessage();
    }
    if (((g_MainWindowActivationState != 0) && (g_IsMainWindowMinimized == 0)) &&
       (g_MainWindowMessagePulseCount == 0)) {
      iVar3 = VerifyGraphicsMode();
      if ((iVar3 != 0) && (DVar4 = timeGetTime(), DAT_00c46c64 < DVar4)) {
        GetCursorPos(&tStack_128);
        SetCursorPos(tStack_128.x,tStack_128.y);
        DAT_00c46c64 = DVar4 + 5000;
      }
      return;
    }
  } while( true );
}


