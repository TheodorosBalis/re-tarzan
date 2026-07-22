#include "tarzan_ghidra_types.hpp"

// Address: 0x00439A60
// Label: CWorld::LoadNatureTerrainSceneContext
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CWorld::LoadNatureTerrainSceneContext(int *arg1,undefined4 *arg2,int arg3)

{
  int *intCursor;
  int entry;
  int entry2;
  byte flagByte;
  undefined4 value;
  int entry3;
  int entry4;
  
  ResetMenuModelSet(arg2);
  *arg1 = (int)arg2;
  arg1[1] = arg3;
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 1;
  entry3 = *arg1;
  entry4 = entry3 + 0x10;
  if (arg2 == (undefined4 *)0x0) {
    arg1[5] = arg1[5] & 0xfffffffc;
    return;
  }
  arg1[5] = 3;
  ResetBitmapCellRuntimeDescriptor(entry4);
  intCursor = (int *)(entry3 + 0x18);
  LoadAssetPayloadIntoBoundHandle(arg2[1],intCursor);
  InitializePalettedTextureBlockFromAsset(entry4,*intCursor);
  BuildPalettedTextureBlockRuntime(entry4);
  if (*(int *)(entry3 + 0x1c) == 0) {
    FreeModelHeapBlock(*intCursor,&g_ModelLoadHeapState);
  }
  else {
    value = ResizeModelHeapBlock(*intCursor,*(undefined4 *)(*intCursor + 0x14),&g_ModelLoadHeapState);
    *(undefined4 *)(entry3 + 0x1c) = value;
    BindModelHeapBlockHandle(*intCursor,(undefined4 *)(entry3 + 0x1c));
    *intCursor = 0;
  }
  CWorld::ReadMapSceneHeader(arg2);
  arg2[3] = 0;
  value = LoadAssetPayload(*arg2);
  arg2[3] = value;
  arg1[6] = 0;
  arg1[0x10] = 0;
  arg1[9] = 0;
  ResolveEntitySceneObjectPointers(arg1);
  MarkCollisionSurfacePathEndSegments();
  intCursor = (int *)arg1[8];
  arg1[2] = *intCursor;
  arg1[3] = intCursor[1];
  entry3 = intCursor[2];
  arg1[0x5016] = 0x1fff;
  arg1[4] = entry3;
  entry3 = arg1[2];
  entry3 = ((entry3 + 0x1fff) / entry3) * 2 + 1;
  arg1[0x5011] = entry3;
  entry = ((arg1[3] + 0x1fff) / arg1[3]) * 2 + 1;
  arg1[0x5012] = entry;
  entry2 = ((arg1[4] + 0x1fff) / arg1[4]) * 2 + 1;
  arg1[0x5013] = entry2;
  flagByte = CountBitsNeededForValue(entry2 * entry * entry3);
  entry3 = 1 << (flagByte & 0x1f);
  arg1[0x5014] = entry3 + -1;
  entry3 = CompactAndAllocModelHeapBlock(entry3,&g_ModelLoadHeapState);
  arg1[0x5015] = entry3;
  BuildBitmapCellResourceRuntime(entry4,arg2[3]);
  return;
}

