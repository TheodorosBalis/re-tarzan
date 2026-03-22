/* Address: 0x0049CB20 */

undefined4
LoadSoundOrUpdateGraphixBufferForCutscene
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint *param_5
          )

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_5 != (uint *)0x0) {
    uVar1 = CurrentGraphicsMode();
    switch(uVar1) {
    case 1:
      iVar2 = FUN_0049cea0();
      *param_5 = (uint)(0x27f < iVar2);
      uVar1 = FUN_0049cf80(param_1,param_2,param_3,param_4);
      return uVar1;
    case 2:
      iVar2 = FUN_00494d30();
      *param_5 = (uint)(0x27f < iVar2);
      uVar1 = FUN_00494d50(param_1,param_2,param_3,param_4);
      return uVar1;
    case 3:
    case 4:
      iVar2 = FUN_00497450();
      *param_5 = (uint)(0x27f < iVar2);
      uVar1 = FUN_004976a0(param_1,param_2,param_3,param_4);
      return uVar1;
    case 5:
      iVar2 = SetWindowWidth();
      *param_5 = (uint)(0x27f < iVar2);
      uVar1 = WriteOnGraphixBufferForCutscene(param_1,param_2,param_3,param_4);
      return uVar1;
    }
  }
  return 0;
}

