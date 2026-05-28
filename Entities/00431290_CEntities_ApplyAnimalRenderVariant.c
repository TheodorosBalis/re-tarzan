
void CEntities__ApplyAnimalRenderVariant(undefined4 param_1,int param_2,int param_3)

{
  if (param_3 == 99) {
    param_3 = RandomModulo(3);
  }
  if (param_3 == 1) {
    *(byte *)(param_2 + 0xf) = *(byte *)(param_2 + 0xf) | 2;
    *(undefined4 *)(param_2 + 0x70) = 1;
  }
  else if (param_3 == 2) {
    *(byte *)(param_2 + 0xf) = *(byte *)(param_2 + 0xf) | 2;
    *(undefined4 *)(param_2 + 0x70) = 2;
    return;
  }
  return;
}

