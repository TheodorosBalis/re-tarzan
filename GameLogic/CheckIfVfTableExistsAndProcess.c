// Address: 0x00496350

void CheckIfVfTableExistsAndProcess(void)

{
  if (((DAT_005535c4 != 0) && (DAT_005535c4 = 0, DAT_005535c0 != 0)) && (DAT_005535cc == 0)) {
    FUN_00496390();
    if (UnknownFunctionPTR_3 != (int *)0x0) {
      DAT_005535bc = (**(code **)(*UnknownFunctionPTR_3 + 0x2c))(UnknownFunctionPTR_3);
    }
  }
  return;
}


