// Address: 0x00452A10

void InitMenuSceneRoot(int param_1)

{
  InitLoadGamePreviewTransform(param_1);
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(uint *)(param_1 + 0x54) = (uint)CONCAT11(0x82,(char)*(undefined4 *)(param_1 + 0x54));
  *(undefined2 *)(param_1 + 0xe) = 0x8100;
  *(undefined4 **)(param_1 + 0x100) = &g_TransitionSceneAnchorPrimary;
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xff;
  *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) & 0xff;
  *(undefined4 *)(param_1 + 0x18) = 0x1ec;
  return;
}


