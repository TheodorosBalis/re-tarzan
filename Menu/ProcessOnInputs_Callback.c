/* Address: 0x00452E30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::ProcessOnInputs_Callback(int param_1)

{
  code *pcVar1;
  undefined **ppuVar2;
  int iVar3;
  uint uVar4;
  
  if ((ram0x00534026 & 0x8000) == 0) {
    if (FadeBrightness != 0) goto LAB_00452e63;
  }
  else if (FadeBrightness != 0) {
    return;
  }
  if (3 < FadeStatus) {
    return;
  }
LAB_00452e63:
  uVar4 = MenuKeyPressed & MenuKeyJustReleased;
  if ((uVar4 & 0x50) == 0) {
    TimeIDLEinMenu = TimeIDLEinMenu + 1;
    if (((uVar4 & 0x1000) != 0) && (*(int *)(param_1 + 0x14) != 0)) {
      LoadSoundFileAndInitAudio(0xaa,0,0);
      (**(code **)(param_1 + 0x14))(*(undefined4 *)(param_1 + 0x18));
    }
    if ((MenuKeyPressed & MenuKeyJustReleased & 0x4008) != 0) {
      pcVar1 = *(code **)(*(int *)(param_1 + 8) + 0x10 + *(int *)(param_1 + 0x24) * 0x18);
      if (pcVar1 != (code *)0x0) {
        ppuVar2 = *(undefined ***)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x24) * 0x18 + 0x14);
        if ((((ppuVar2 != &PTR_PTR_004eff98) && (ppuVar2 != &PTR_PTR_004efff8)) &&
            (ppuVar2 != &PTR_PTR_004f00d8)) &&
           ((ppuVar2 != &PTR_PTR_004f0130 && (ppuVar2 != &PTR_PTR_004f0188)))) {
          LoadSoundFileAndInitAudio(0xac,0,0);
        }
        iVar3 = *(int *)(*(int *)(param_1 + 8) + 0xc + *(int *)(param_1 + 0x24) * 0x18);
        if (iVar3 != -1) {
          LoadSoundFileAndInitAudio(iVar3,0,0);
        }
        (*pcVar1)(*(undefined4 *)(*(int *)(param_1 + 8) + 0x14 + *(int *)(param_1 + 0x24) * 0x18));
      }
    }
  }
  else {
    if (0 < TimeIDLEinMenu) {
      TimeIDLEinMenu = 0;
    }
    if ((((uVar4 & 0x40) != 0) && (*(int *)(param_1 + 0x24) < *(int *)(param_1 + 4) + -1)) &&
       (*(int *)(*(int *)(param_1 + 8) + 0x1c + *(int *)(param_1 + 0x24) * 0x18) != -1)) {
      LoadSoundFileAndInitAudio(0xaa,0,0);
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    }
    if (((MenuKeyPressed & MenuKeyJustReleased & 0x10) != 0) && (0 < *(int *)(param_1 + 0x24))) {
      LoadSoundFileAndInitAudio(0xaa,0,0);
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
      return;
    }
  }
  return;
}

