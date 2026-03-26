// Address: 0x0049CC60

void RefreshDirtyTexturePage(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = CurrentGraphicsMode();
  switch(uVar1) {
  case 1:
    FUN_0049cec0(param_1,param_2);
    return;
  case 2:
    FUN_00496040(param_1,param_2);
    return;
  case 3:
  case 4:
    FUN_004974f0(param_1,param_2);
    return;
  case 5:
    FUN_0049b490(param_1,param_2);
  }
  return;
}


