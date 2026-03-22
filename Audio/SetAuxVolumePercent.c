/* Address: 0x004A1890 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetAuxVolumePercent(int param_1)

{
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (100 < param_1) {
    param_1 = 100;
  }
  if (DAT_0072427c != 0) {
    _DAT_007242a0 = param_1 * 0x28f;
    _DAT_00724284 = param_1;
    _DAT_007242a4 = _DAT_007242a0;
    mixerSetControlDetails((HMIXEROBJ)0x0,(LPMIXERCONTROLDETAILS)&DAT_00724288,0);
  }
  return;
}

