// Address: 0x004948C0

void DecodeCfgBuffer(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    *(byte *)((int)&tarzanCFGbuffer + uVar1) =
         *(byte *)((int)&tarzanCFGbuffer + uVar1) ^ (char)uVar1 * '{';
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0xbc);
  return;
}


