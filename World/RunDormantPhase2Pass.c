// 0x004446b0

void RunDormantPhase2Pass(void)

{
  byte *pbVar1;
  
  _g_RuntimeProcessingPhase = 2;
  for (pbVar1 = DAT_00531e38; pbVar1 != (byte *)0x0; pbVar1 = *(byte **)(pbVar1 + 0x20)) {
    if ((*pbVar1 & 1) != 0) {
      (**(code **)(pbVar1 + 0x30))(pbVar1);
    }
  }
  _g_RuntimeProcessingPhase = 0;
  return;
}