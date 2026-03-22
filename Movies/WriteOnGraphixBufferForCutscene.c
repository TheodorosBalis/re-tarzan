/* Address: 0x0049B570 */

undefined4
WriteOnGraphixBufferForCutscene
          (undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if ((((isGraphicsInitialized != 0) && (DAT_00722864 == 0)) && (param_2 != (undefined4 *)0x0)) &&
     ((param_3 != (undefined4 *)0x0 && (param_4 != (undefined4 *)0x0)))) {
    *param_2 = 0;
    *param_3 = 0;
    *param_4 = 0;
    uVar1 = WriteToGraphicsBufferIfGraphicsInitialized(0xffffffff,param_2,param_3);
    return uVar1;
  }
  return 0;
}

