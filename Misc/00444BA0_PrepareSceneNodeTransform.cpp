#include "tarzan_ghidra_types.hpp"

// Address: 0x00444BA0
// Label: PrepareSceneNodeTransform
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 * PrepareSceneNodeTransform(int arg1,int *arg2)

{
  uint *dataCursor;
  ushort value;
  short shortValue;
  ushort value2;
  ushort value3;
  int entry;
  int entry2;
  int scratchTransform4;
  int scratchTransform3;
  int scratchTransform2;
  int scratchTransform;
  int scratchTransform6;
  int scratchTransform5;
  
  scratchTransform4 = (*(int *)(arg1 + 0x3c) + *(int *)(arg1 + 0x14)) - *arg2;
  scratchTransform3 = (*(int *)(arg1 + 0x40) - arg2[1]) + *(int *)(arg1 + 0x18);
  dataCursor = (uint *)(arg2 + 0x1a);
  value = *(ushort *)(arg1 + 0xe);
  scratchTransform2 = (*(int *)(arg1 + 0x44) - arg2[2]) + *(int *)(arg1 + 0x1c);
  TransformVectorByBasis(dataCursor,&scratchTransform4,&g_ModelHierarchyTransformStackBaseTranslationX);
  g_ModelHierarchyTransformStackBaseTranslationX =
       g_ModelHierarchyTransformStackBaseTranslationX + arg2[0x1f];
  g_ModelHierarchyTransformStackBaseTranslationY =
       g_ModelHierarchyTransformStackBaseTranslationY + arg2[0x20];
  g_ModelHierarchyTransformStackBaseTranslationZ =
       g_ModelHierarchyTransformStackBaseTranslationZ + arg2[0x21];
  g_SceneTransformScratch_Field000B =
       (&g_SceneTransformScratch_FieldFFAABCD0)[((int)(uint)value >> 1 & 7U) * 4];
  shortValue = *(short *)(arg1 + 0xa6);
  if (shortValue == 3) {
    if ((value & 0x1000) == 0) {
      g_ModelHierarchyTransformStackBase = *dataCursor;
      g_SceneTransformScratch_Field0044 = arg2[0x1b];
      g_SceneNodePreparedTransform = arg2[0x1c];
      g_SceneTransformScratch_Field004C = arg2[0x1d];
      g_SceneNodePreparedTranslation = (short)arg2[0x1e];
      if ((value & 0xe) == 0) {
        if (*(int *)(arg1 + 0xb4) != 0) {
          ScaleBasisAxesClamped(&g_ModelHierarchyTransformStackBase,arg1 + 0xa8);
        }
      }
      else if (*(int *)(arg1 + 0xb4) == 0) {
        scratchTransform = (-(uint)((value & 2) != 0) & 0xffffe000) + 0x1000;
        scratchTransform6 = (-(uint)((value & 4) != 0) & 0xffffe000) + 0x1000;
        scratchTransform5 = (-(uint)((value & 8) != 0) & 0xffffe000) + 0x1000;
        ScaleBasisAxesClamped(&g_ModelHierarchyTransformStackBase,&scratchTransform);
      }
      else {
        ScaleBasisAxesClamped(&g_ModelHierarchyTransformStackBase,arg1 + 0xa8);
      }
    }
    else {
      value3 = *(ushort *)(arg2 + 0x16);
      g_ModelHierarchyTransformStackBase = (uint)value3;
      g_SceneTransformScratch_Field0044 = 0;
      value2 = *(ushort *)(arg2 + 0x17);
      g_SceneNodePreparedTransform = (uint)value2;
      g_SceneTransformScratch_Field004C = 0;
      g_SceneNodePreparedTranslation = (short)arg2[0x18];
      if ((value & 0xe) == 0) {
        if (*(int *)(arg1 + 0xb4) != 0) {
          g_ModelHierarchyTransformStackBase =
               *(int *)(arg1 + 0xa8) * (int)(short)value3 >> 0xc & 0xffff;
          g_SceneNodePreparedTransform =
               *(int *)(arg1 + 0xac) * (int)(short)value2 >> 0xc & 0xffff;
          g_SceneNodePreparedTranslation =
               (short)(*(int *)(arg1 + 0xb0) * (int)g_SceneNodePreparedTranslation >> 0xc);
        }
      }
      else if (*(int *)(arg1 + 0xb4) == 0) {
        g_ModelHierarchyTransformStackBase =
             (uint)(ushort)((-(ushort)((value & 2) != 0) & 0xe000) + 0x1000);
        g_SceneNodePreparedTransform =
             (uint)(ushort)((-(ushort)((value & 4) != 0) & 0xe000) + 0x1000);
        g_SceneNodePreparedTranslation = (-(ushort)((value & 8) != 0) & 0xe000) + 0x1000;
      }
      else {
        if ((value & 2) == 0) {
          value3 = (ushort)(*(int *)(arg1 + 0xa8) * (int)(short)value3 >> 0xc);
        }
        else {
          value3 = -(short)(*(int *)(arg1 + 0xa8) * (int)(short)value3 >> 0xc);
        }
        g_ModelHierarchyTransformStackBase = (uint)value3;
        if ((value & 4) == 0) {
          value3 = (ushort)(*(int *)(arg1 + 0xac) * (int)(short)value2 >> 0xc);
        }
        else {
          value3 = -(short)(*(int *)(arg1 + 0xac) * (int)(short)value2 >> 0xc);
        }
        g_SceneNodePreparedTransform = (uint)value3;
        if ((value & 8) == 0) {
          g_SceneNodePreparedTranslation =
               (short)(*(int *)(arg1 + 0xb0) * (int)g_SceneNodePreparedTranslation >> 0xc);
        }
        else {
          g_SceneNodePreparedTranslation =
               -(short)(*(int *)(arg1 + 0xb0) * (int)g_SceneNodePreparedTranslation >> 0xc);
        }
      }
    }
  }
  else {
    if (FrameCount != *(int *)(arg1 + 0xf8)) {
      *(int *)(arg1 + 0xf8) = FrameCount;
      if (shortValue == 0) {
        BuildBasisMatrixFromEulerAngles(arg1 + 0xa0,arg1 + 0xb8);
      }
      else if (shortValue == 1) {
        BuildSceneNodeMode1BasisFromEulerAngles(arg1 + 0xa0,arg1 + 0xb8);
      }
      else if (shortValue == 2) {
        BuildRotationBasisFromEulerAngles(arg1 + 0xa0,arg1 + 0xb8);
      }
      if (*(int *)(arg1 + 0xb4) != 0) {
        ScaleBasisAxesClamped(arg1 + 0xb8,arg1 + 0xa8);
      }
    }
    if ((value & 0xe) != 0) {
      if ((value & 2) != 0) {
        *(short *)(arg1 + 0xb8) = -*(short *)(arg1 + 0xb8);
        *(short *)(arg1 + 0xbe) = -*(short *)(arg1 + 0xbe);
        *(short *)(arg1 + 0xc4) = -*(short *)(arg1 + 0xc4);
      }
      if ((value & 4) != 0) {
        *(short *)(arg1 + 0xba) = -*(short *)(arg1 + 0xba);
        *(short *)(arg1 + 0xc0) = -*(short *)(arg1 + 0xc0);
        *(short *)(arg1 + 0xc6) = -*(short *)(arg1 + 0xc6);
      }
      if ((value & 8) != 0) {
        *(short *)(arg1 + 0xbc) = -*(short *)(arg1 + 0xbc);
        *(short *)(arg1 + 0xc2) = -*(short *)(arg1 + 0xc2);
        *(short *)(arg1 + 200) = -*(short *)(arg1 + 200);
      }
    }
    MultiplyBasisMatrices(dataCursor,arg1 + 0xb8,&g_ModelHierarchyTransformStackBase);
  }
  SetDrawWindow(arg2[0x31],*(undefined4 *)(arg1 + 0x6c));
  if ((*(byte *)(arg1 + 0xf) & 1) == 0) {
    entry2 = arg2[7];
    entry = arg2[6];
  }
  else {
    entry2 = ((*(int *)(arg1 + 0x58) >> 8) * 0x1e0) / 0xf0;
    entry = (*(int *)(arg1 + 0x54) >> 8) * 0x280;
    entry = (int)(entry + (entry >> 0x1f & 0x1ffU)) >> 9;
  }
  SetProjectionScreenOrigin(entry,entry2);
  SetProjectionDepthScale(arg2[8]);
  SetTransformBasisFromRef(&g_ModelHierarchyTransformStackBase);
  return &g_ModelHierarchyTransformStackBase;
}

