
void CEntities__SelectScriptAttachmentSequence(uint *param_1,short param_2)

{
  if ((*param_1 & 0xff) == 1) {
    if (param_1[4] != 0) {
      *(short *)(param_1 + 6) = param_2;
      param_1[3] = *(uint *)(param_1[4] + param_2 * 4);
    }
    *(undefined2 *)((int)param_1 + 0x16) = 0;
    *(undefined2 *)(param_1 + 5) = 0xffff;
  }
  else if ((*param_1 & 0xff) == 2) {
    if (param_1[4] != 0) {
      *(short *)(param_1 + 6) = param_2;
      param_1[3] = *(uint *)(param_1[4] + param_2 * 4);
    }
    *(undefined2 *)((int)param_1 + 0x16) = 0xffff;
    *(undefined2 *)(param_1 + 5) = 0xffff;
    return;
  }
  return;
}

