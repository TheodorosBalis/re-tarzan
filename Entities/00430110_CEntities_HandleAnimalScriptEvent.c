
undefined4 CEntities__HandleAnimalScriptEvent(int param_1,int param_2,int param_3)

{
  if (param_3 < 0x108) {
    if (param_3 == 0x107) {
      *(byte *)(param_2 + 0x75) = ~*(byte *)(param_2 + 0x75);
      *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xffd7;
      CEntities__RefreshAnimalFacingAndCollisionAfterTurn(param_1,param_2);
      return 0;
    }
    if (param_3 < 0x106) {
      if (param_3 == 0x105) {
        *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 1;
        return 0;
      }
      if (1 < param_3) {
        if (param_3 < 4) {
          *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfff7;
          return 1;
        }
        if (param_3 == 4) {
          *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfffc;
          return 0;
        }
      }
    }
    else if (param_3 == 0x106) {
      *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 2;
      return 0;
    }
  }
  else if (param_3 == 0x108) {
    *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 0x20;
  }
  else {
    if (param_3 == 0x109) {
      *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xffdf;
      return 0;
    }
    if (param_3 == 0x111) {
      *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 8;
      return 0;
    }
  }
  return 0;
}

