// Address: 0x004AFA50

undefined4 DrawGraphicsTextinMem_2(undefined1 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  uVar1 = FUN_004b1dbc(&local_24,param_2,&stack0x0000000c);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_004b0d05(0,&local_24);
  }
  else {
    *local_24 = 0;
  }
  return uVar1;
}


