/* Address: 0x0049AE80 */

void DrawGraphicsTextinMem
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = Return6(param_3,param_4,param_5);
  uVar1 = Return6_2(uVar1);
  uVar1 = Return6(1,1,uVar1);
  uVar1 = Return6_2(uVar1);
  DrawGraphicsText(param_1,param_2,uVar1);
  return;
}

