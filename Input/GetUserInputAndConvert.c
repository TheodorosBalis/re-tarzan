// Address: 0x0049E080

uint GetUserInputAndConvert(int param_1)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = GetAsyncKeyState(param_1);
  uVar2 = (&InputBuffer)[param_1] & uVar1 & 0x8001;
  (&InputBuffer)[param_1] = uVar2;
  return ~uVar2 & uVar1 & 0x8001;
}


