// Address: 0x004A8810

void DoDsoundSetupStuff(void)

{
  uint local_2c;
  undefined2 local_28;
  undefined2 local_26;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined2 *local_4;
  
  local_28 = 1;
  local_26 = 1;
  local_4 = &local_28;
  local_2c = 0;
  DAT_009e4a34 = (undefined4 *)0x0;
  local_8 = 0;
  DAT_009e4a38 = (undefined4 *)0x0;
  DAT_009e4a3c = (int *)0x0;
  local_18 = 0;
  local_24 = 0x5622;
  local_1a = 0x10;
  local_1c = 2;
  local_20 = 0xac44;
  local_14 = 0x14;
  local_10 = 0x12;
  local_c = 0x80;
  if ((((g_DirectSound != (int *)0x0) &&
       ((**(code **)(*g_DirectSound + 0xc))(g_DirectSound,&local_14,&DAT_009e4a34,0),
       DAT_009e4a34 != (undefined4 *)0x0)) &&
      ((**(code **)*DAT_009e4a34)(DAT_009e4a34,&DAT_004ba3e0,&DAT_009e4a38),
      DAT_009e4a38 != (undefined4 *)0x0)) &&
     (((**(code **)*DAT_009e4a38)(DAT_009e4a38,&DAT_004ba420,&DAT_009e4a3c),
      DAT_009e4a3c != (int *)0x0 &&
      ((**(code **)(*DAT_009e4a3c + 0x14))(DAT_009e4a3c,&DAT_004ba430,0,&local_2c),
      (local_2c & 2) != 0)))) {
    if (DAT_009e4a3c != (int *)0x0) {
      (**(code **)(*DAT_009e4a3c + 0x14))(DAT_009e4a3c,&DAT_004ba440,0,&local_2c);
    }
    if ((local_2c & 2) != 0) {
      return;
    }
  }
  FUN_004a8930();
  return;
}


