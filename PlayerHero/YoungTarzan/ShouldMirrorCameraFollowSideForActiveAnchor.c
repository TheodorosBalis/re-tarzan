// 0x00434bd0
bool ShouldMirrorCameraFollowSideForActiveAnchor(void)

{
  int iVar1;
  
  if (*(int *)(g_ActiveCameraAnchorEntry + 0x38) != 0) {
    iVar1 = GetWrappedSignedAngleDelta12Bit
                      (-g_CameraYaw & 0xfff,
                       *(ushort *)(*(int *)(g_ActiveCameraAnchorEntry + 0x38) + 0xa2) & 0xfff);
    return iVar1 < 0;
  }
  return false;
}