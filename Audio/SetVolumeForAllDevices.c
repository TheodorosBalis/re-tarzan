/* Address: 0x004A1800 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetVolumeForAllDevices(int param_1)

{
  UINT *pUVar1;
  int iVar2;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (100 < param_1) {
    param_1 = 100;
  }
  if (DAT_007246a4 != 0) {
    _DAT_007246c8 = param_1 * 0x28f;
    _DAT_007246ac = param_1;
    _DAT_007246cc = _DAT_007246c8;
    mixerSetControlDetails((HMIXEROBJ)0x0,(LPMIXERCONTROLDETAILS)&DAT_007246b0,0);
  }
  iVar2 = 0;
  if (0 < DAT_00724ac8) {
    pUVar1 = &DAT_00724238;
    do {
      auxSetVolume(*pUVar1,param_1 * 0x28f028f);
      iVar2 = iVar2 + 1;
      pUVar1 = pUVar1 + 2;
    } while (iVar2 < DAT_00724ac8);
  }
  return;
}

