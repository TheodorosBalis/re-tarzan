// 0x00441940

void BuildDefaultRuntimeActivationBounds(int *param_1,int *param_2)

{
  *param_1 = g_CameraFocusX + -0x1c00;
  param_1[1] = g_CameraFocusY + -0x1c00;
  param_1[2] = g_CameraFocusZ + -0x1c00;
  param_1[3] = g_CameraFocusX + 0x1c00;
  param_1[4] = g_CameraFocusY + 0x1c00;
  param_1[5] = g_CameraFocusZ + 0x1c00;
  *param_2 = g_CameraFocusX + -0x2100;
  param_2[1] = g_CameraFocusY + -0x2100;
  param_2[2] = g_CameraFocusZ + -0x2100;
  param_2[3] = g_CameraFocusX + 0x2100;
  param_2[4] = g_CameraFocusY + 0x2100;
  param_2[5] = g_CameraFocusZ + 0x2100;
  return;
}