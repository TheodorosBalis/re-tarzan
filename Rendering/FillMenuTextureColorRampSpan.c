// Address: 0x0049E630

void FillMenuTextureColorRampSpan(char param_1,char param_2,int param_3,int param_4)

{
  bool bVar1;
  ushort uVar2;
  bool bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  
  bVar1 = 0 < param_3;
  bVar3 = !bVar1;
  if (bVar3) {
    param_3 = param_4;
  }
  if (-1 < param_3 + -1) {
    do {
      uVar4 = ConvertFpuTopToInt64();
      uVar5 = ConvertFpuTopToInt64();
      uVar6 = ConvertFpuTopToInt64();
      uVar2 = CONCAT11(param_2,param_1);
      param_1 = param_1 + bVar1;
      (&g_MenuTextureAtlasPixels)[uVar2] = ((uVar4 & 0x1f) << 5 | uVar5 & 0x1f) << 5 | uVar6 & 0x1f;
      param_2 = param_2 + bVar3;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


