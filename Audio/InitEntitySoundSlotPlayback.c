// Address: 0x004AC6F0

undefined4 InitEntitySoundSlotPlayback(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    param_2[1] = 0xffffffff;
    *param_2 = param_1;
    param_2[2] = 0xf;
    return 1;
  }
  PlaySoundID(param_1,100,0,0,0x3fb33333);
  return 1;
}


