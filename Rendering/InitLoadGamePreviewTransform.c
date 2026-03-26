// Address: 0x00444A30

void InitLoadGamePreviewTransform(int param_1)

{
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined2 *)(param_1 + 0x140) = 0x80;
  *(undefined2 *)(param_1 + 0x142) = 0;
  *(undefined2 *)(param_1 + 0xa6) = 3;
  *(undefined2 *)(param_1 + 0xa4) = 0;
  *(undefined2 *)(param_1 + 0xa2) = 0;
  *(undefined2 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0x1000;
  *(undefined4 *)(param_1 + 0xac) = 0x1000;
  *(undefined4 *)(param_1 + 0xb0) = 0x1000;
  *(undefined4 **)(param_1 + 0x100) = &g_TransitionSceneAnchorPrimary;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  FUN_00444a10(param_1 + 0xc);
  return;
}


