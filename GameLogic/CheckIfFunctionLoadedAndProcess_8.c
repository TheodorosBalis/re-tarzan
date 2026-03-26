// Address: 0x004979F0

void CheckIfFunctionLoadedAndProcess_8(void)

{
  if (UnknownFunctionPTR7 != (int *)0x0) {
    DAT_00553668 = (**(code **)(*UnknownFunctionPTR7 + 8))(UnknownFunctionPTR7);
  }
  UnknownFunctionPTR7 = (int *)0x0;
  return;
}


