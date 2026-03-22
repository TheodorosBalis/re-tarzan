/* Address: 0x0049A880 */

undefined4 LoadFontTexture(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = LocateAndSetBufferForEgfObject(param_1,&DAT_005156bc);
  FUN_0049a7a0(uVar1,0,2);
  uVar2 = FUN_0049a850(uVar1);
  FUN_0049a660(uVar1);
  return uVar2;
}

