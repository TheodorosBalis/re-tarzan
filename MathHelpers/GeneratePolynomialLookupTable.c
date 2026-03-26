// Address: 0x004A9300

void GeneratePolynomialLookupTable(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  
  UpdateGameLoopFlag(0);
  puVar2 = &DAT_009e4a80;
  do {
    uVar1 = ConvertFpuTopToInt64();
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0xa04a80);
  ResetRenderPacketCount();
  return;
}


