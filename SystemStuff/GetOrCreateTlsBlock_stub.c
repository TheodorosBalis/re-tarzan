/* Address: 0x004B00BE */

void GetOrCreateTlsBlock_stub(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = GetOrCreateTlsBlock();
  *(undefined4 *)(iVar1 + 0x14) = param_1;
  return;
}

