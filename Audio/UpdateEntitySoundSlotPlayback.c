// Address: 0x004AC760

bool UpdateEntitySoundSlotPlayback(undefined2 *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  if (param_1 == (undefined2 *)0x0) {
    return false;
  }
  if (*(int *)(param_1 + 2) == -1) {
    iVar1 = *(int *)(param_1 + 4);
    *(int *)(param_1 + 4) = iVar1 + -1;
    if (iVar1 + -1 < 1) {
      return false;
    }
    ComputeEntitySfxSpatialParams(param_2);
    cVar2 = PlaySoundID(*param_1,100,g_EntitySfxSpatialX,g_EntitySfxSpatialY,g_EntitySfxSpatialZ);
    *(int *)(param_1 + 2) = (int)cVar2;
  }
  else {
    if ((g_ActiveAudioChannelMask >> ((byte)*(int *)(param_1 + 2) & 0x1f) & 1U) == 0) {
      StopEntitySoundSlotPlayback(param_1);
      return false;
    }
    if (param_2 != 0) {
      ComputeEntitySfxSpatialParams(param_2);
      UpdateSoundChannel3DPosition
                (0xffffffff,*(undefined1 *)(param_1 + 2),g_EntitySfxSpatialX,g_EntitySfxSpatialY,
                 g_EntitySfxSpatialZ);
      return *(int *)(param_1 + 2) != -1;
    }
  }
  return *(int *)(param_1 + 2) != -1;
}


