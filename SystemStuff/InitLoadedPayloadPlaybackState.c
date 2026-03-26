// Address: 0x004ABE00

void InitLoadedPayloadPlaybackState(undefined4 *param_1)

{
  g_ActiveTransitionPayload = param_1;
  param_1[3] = 0;
  param_1[4] = 0;
  DAT_005113f0 = *param_1;
  DAT_005113f4 = param_1[1];
  TotalGameLoopTicks = param_1[2];
  return;
}


