// Address: 0x0049E060

uint IsControlBindingPressed(undefined1 param_1)

{
  uint uVar1;
  
  uVar1 = GetUserInputAndConvert(param_1);
  return uVar1 & 0x8000;
}


