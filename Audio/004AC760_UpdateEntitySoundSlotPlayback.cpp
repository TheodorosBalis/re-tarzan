#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC760
// Label: UpdateEntitySoundSlotPlayback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool UpdateEntitySoundSlotPlayback(undefined2 *soundId,int position)

{
  int slotIndex;
  char resultFlag;
  
  if (soundId == (undefined2 *)0x0) {
    return false;
  }
  if (*(int *)(soundId + 2) == -1) {
    slotIndex = *(int *)(soundId + 4);
    *(int *)(soundId + 4) = slotIndex + -1;
    if (slotIndex + -1 < 1) {
      return false;
    }
    ComputeEntitySfxSpatialParams(position);
    resultFlag = PlaySoundID(*soundId,100,g_EntitySfxSpatialX,g_EntitySfxSpatialY,g_EntitySfxSpatialZ);
    *(int *)(soundId + 2) = (int)resultFlag;
  }
  else {
    if ((g_ActiveAudioChannelMask >> ((byte)*(int *)(soundId + 2) & 0x1f) & 1U) == 0) {
      StopEntitySoundSlotPlayback(soundId);
      return false;
    }
    if (position != 0) {
      ComputeEntitySfxSpatialParams(position);
      UpdateSoundChannel3DPosition
                (0xffffffff,*(undefined1 *)(soundId + 2),g_EntitySfxSpatialX,g_EntitySfxSpatialY,
                 g_EntitySfxSpatialZ);
      return *(int *)(soundId + 2) != -1;
    }
  }
  return *(int *)(soundId + 2) != -1;
}

