#include "tarzan_ghidra_types.hpp"

// Address: 0x004388C0
// Label: RebuildLoadedWorldSceneState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RebuildLoadedWorldSceneState(void)

{
  ushort *stateFlags;
  ushort stateFlags4;
  bool flagByte;
  undefined2 upperWord;
  undefined2 upperWord2;
  undefined2 stateFlags5;
  int entry;
  int *intCursor;
  short state;
  uint stateFlags6;
  int entry2;
  ushort *stateFlags2;
  undefined *stateFlags3;
  short *value;
  undefined *scratchBuffer;
  
  FlushEntitySoundSlots();
  entry2 = 1;
  _g_RockinTheBoatLevelStateTable = 1;
  if (*( undefined2 *)((int)&g_LevelTransitionRequestFlags + 2) == 0x8000) {
    scratchBuffer = g_CurrentWorldSceneContext;
  }
  else {
    scratchBuffer = (undefined *)
              (g_WorldEntitySceneObjectArrayBase + (uint)*( undefined2 *)((int)&g_LevelTransitionRequestFlags + 2) * 0x68)
    ;
  }
  entry = *(int *)(*(int *)(g_CurrentWorldSceneContext + 0xc) + 0x24);
  if (entry != 0) {
    intCursor = (int *)(entry + 0x24 + *(int *)(g_CurrentWorldSceneContext + 0xc));
    state = 1;
    if (0 < *intCursor) {
      do {
        UpdateCurrentWorldSceneAuxResourceIfLoaded(entry2);
        if ((intCursor[entry2 * 4 + 3] != 0) || (intCursor[entry2 * 4 + 4] != -1)) {
          ReleaseWorldSceneAuxResourceNoOp(g_CurrentWorldSceneContext,entry2);
        }
        state = state + 1;
        entry2 = (int)state;
      } while (entry2 <= *intCursor);
    }
  }
  entry2 = 0x1001;
  stateFlags6 = 0x1001;
  do {
    flagByte = false;
    entry = (stateFlags6 & 0xfff) * 0x10;
    intCursor = (int *)(&g_EncodedSceneModelResourceTable + entry);
    if (*(int *)(*intCursor + 0x30 + *(int *)(entry + 0x4caaf0) * 8) != 0) {
      stateFlags2 = *(ushort **)(g_CurrentLevelStartPositionX + 4);
      stateFlags4 = *stateFlags2;
      while (-1 < (short)stateFlags4) {
        if (((stateFlags4 & 0x5000) == 0x1000) &&
           (intCursor == (int *)(&g_EncodedSceneModelResourceTable + (stateFlags4 & 0xfff) * 0x10))) {
          flagByte = true;
          break;
        }
        stateFlags = stateFlags2 + 1;
        stateFlags2 = stateFlags2 + 1;
        stateFlags4 = *stateFlags;
      }
      stateFlags2 = *(ushort **)(g_CurrentLevelStartPositionZ + 0x20 + g_CurrentCheckpointId * 0x24);
      stateFlags4 = *stateFlags2;
      if ((short)stateFlags4 < 0) {
        if (flagByte) goto LAB_00438a1a;
      }
      else {
        do {
          if ((flagByte) ||
             (((stateFlags4 & 0x5000) == 0x1000 &&
              (intCursor == (int *)(&g_EncodedSceneModelResourceTable + (stateFlags4 & 0xfff) * 0x10)))))
          goto LAB_00438a1a;
          stateFlags4 = stateFlags2[1];
          stateFlags2 = stateFlags2 + 1;
        } while (-1 < (short)stateFlags4);
      }
      ReleaseEncodedResourceId(entry2);
    }
LAB_00438a1a:
    entry2 = entry2 + 1;
    stateFlags6 = stateFlags6 + 1;
    if (0x1031 < (short)entry2) {
      entry2 = 0;
      stateFlags3 = &g_ResourceSetDescriptorTable;
      do {
        flagByte = false;
        if ((stateFlags3 != scratchBuffer) && (*(int *)(stateFlags3 + 0xc) != 0)) {
          stateFlags2 = *(ushort **)(g_CurrentLevelStartPositionX + 4);
          stateFlags4 = *stateFlags2;
          while (-1 < (short)stateFlags4) {
            if (((stateFlags4 & 0x5000) == 0) &&
               (stateFlags3 == &g_ResourceSetDescriptorTable + (short)stateFlags4 * 0x68)) {
              flagByte = true;
              break;
            }
            stateFlags = stateFlags2 + 1;
            stateFlags2 = stateFlags2 + 1;
            stateFlags4 = *stateFlags;
          }
          stateFlags2 = *(ushort **)(g_CurrentLevelStartPositionZ + 0x20 + g_CurrentCheckpointId * 0x24)
          ;
          stateFlags4 = *stateFlags2;
          while (-1 < (short)stateFlags4) {
            if (((stateFlags4 & 0x5000) == 0) &&
               (stateFlags3 == &g_ResourceSetDescriptorTable + (short)stateFlags4 * 0x68)) goto LAB_00438adb;
            stateFlags = stateFlags2 + 1;
            stateFlags2 = stateFlags2 + 1;
            stateFlags4 = *stateFlags;
          }
          if (!flagByte) {
            ReleaseEncodedResourceId(entry2);
          }
        }
LAB_00438adb:
        entry2 = entry2 + 1;
        stateFlags3 = stateFlags3 + 0x68;
        if (0x90 < (short)entry2) {
          stateFlags2 = *(ushort **)(g_CurrentLevelStartPositionX + 4);
          stateFlags4 = *stateFlags2;
          while (-1 < (short)stateFlags4) {
            if ((stateFlags4 & 0x4000) == 0) {
              LoadNecessaryEncodedResourceId(stateFlags4);
            }
            else {
              ReleaseEncodedResourceId();
            }
            stateFlags = stateFlags2 + 1;
            stateFlags2 = stateFlags2 + 1;
            stateFlags4 = *stateFlags;
          }
          value = *(short **)(g_CurrentLevelStartPositionZ + 0x20 + g_CurrentCheckpointId * 0x24);
          state = *value;
          stateFlags6 = CONCAT22((short)((uint)(g_CurrentCheckpointId * 9) >> 0x10),state);
          while (-1 < state) {
            if ((stateFlags6 & 0x4000) == 0) {
              LoadNecessaryEncodedResourceId(stateFlags6);
              stateFlags5 = upperWord2;
            }
            else {
              ReleaseEncodedResourceId();
              stateFlags5 = upperWord;
            }
            state = value[1];
            stateFlags6 = CONCAT22(stateFlags5,state);
            value = value + 1;
          }
          InitCurrentBackgroundMusicTrack();
          return;
        }
      } while( true );
    }
  } while( true );
}

