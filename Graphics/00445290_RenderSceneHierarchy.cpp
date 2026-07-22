#include "tarzan_ghidra_types.hpp"

// Address: 0x00445290
// Label: RenderSceneHierarchy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderSceneHierarchy(int graphicsObject)

{
  Entity *entity = (Entity *)graphicsObject;
  ushort value;
  int entry;
  short shortValue;
  short shortValue2;
  short shortValue3;
  uint value2;
  int entry2;
  int entry3;
  ushort *dataCursor;
  ushort localState3;
  ushort localState2;
  ushort localState;
  
  entry = *(int *)(graphicsObject + 0x100);
  dataCursor = (ushort *)(graphicsObject + 0xc);
  if (((entity->next == 0) || ((*(byte *)(graphicsObject + 0xf) & 0x80) == 0)) ||
     (*(int *)(entity->next + 0xc) == 0)) {
    entry2 = entity->sceneObjects;
joined_r0x004453b7:
    if (entry2 != 0) {
      PrepareSceneNodeTransform(graphicsObject,entry);
    }
  }
  else {
    PrepareSceneNodeTransform(graphicsObject,entry);
    g_NatureTerrainRenderContext = entity->next;
    ApplySceneNodeFadeAndBlend(dataCursor,*(undefined4 *)(entry + 0xb0),entry + 0xb4);
    value = *dataCursor;
    value2 = value & 0x7000;
    if (value2 < 0x3001) {
      if (value2 == 0x3000) {
        entry2 = (*(int *)(graphicsObject + 0x14) >> 8) * 0x280;
        entry3 = (*(int *)(graphicsObject + 0x18) >> 8) * 0x1e0;
        DrawSceneSpriteQuad(*(int *)(entity->next + 0x14) + (value & 0xfff) * 0x26,
                            CONCAT22(((short)(entry3 / 0xf0) + (short)(entry3 >> 0x1f)) -
                                     (short)((longlong)entry3 * 0x88888889 >> 0x3f),
                                     (short)((int)(entry2 + (entry2 >> 0x1f & 0x1ffU)) >> 9)),0,
                            &DAT_00808080);
        goto LAB_004453c3;
      }
      if ((value & 0x7000) == 0) {
        RenderSceneModelNode(graphicsObject);
        entry2 = entity->sceneObjects;
        goto joined_r0x004453b7;
      }
      if (value2 != 0x2000) goto LAB_004453c3;
    }
    else if (value2 != 0x5000) goto LAB_004453c3;
    RenderSceneAssetNode(dataCursor);
  }
LAB_004453c3:
  entry2 = entity->sceneObjects;
  if (entry2 != 0) {
    shortValue2 = (short)g_ModelHierarchyTransformStackBaseTranslationY;
    shortValue3 = (short)g_ModelHierarchyTransformStackBaseTranslationZ;
    shortValue = (short)g_ModelHierarchyTransformStackBaseTranslationX;
    SetTransformBasisFromRef(&g_ModelHierarchyTransformStackBase);
    dataCursor = (ushort *)(&((EntitySceneObject *)entry2)->worldObject);
    for (value2 = (uint)*(ushort *)(entry2 + 0xc); value2 != 0; value2 = value2 - 1) {
      if ((dataCursor[1] & 0x8000) != 0) {
        if ((*dataCursor & 0x7000) == 0x1000) {
          localState3 = dataCursor[4];
          localState2 = dataCursor[6];
          localState = dataCursor[8];
          ProcessSceneLocatorNode_Stub
                    (&localState3,(uint)CONCAT11((char)(*(int *)(dataCursor + 0xe) >> 5),
                                             (char)(*(int *)(dataCursor + 0xc) >> 5)) << 8 |
                              *(int *)(dataCursor + 10) >> 5 & 0xffU);
        }
        else if ((*(int *)(dataCursor + 2) != 0) && (*(int *)(*(int *)(dataCursor + 2) + 0xc) != 0)) {
          if ((dataCursor[1] & 0x1000) == 0) {
            TransformVectorByBasis
                      (&g_ModelHierarchyTransformStackBase,dataCursor + 4,
                       &g_ModelHierarchyTransformStackBaseTranslationX);
            g_ModelHierarchyTransformStackBaseTranslationX =
                 g_ModelHierarchyTransformStackBaseTranslationX + shortValue;
            g_ModelHierarchyTransformStackBaseTranslationY =
                 g_ModelHierarchyTransformStackBaseTranslationY + shortValue2;
            g_ModelHierarchyTransformStackBaseTranslationZ =
                 g_ModelHierarchyTransformStackBaseTranslationZ + shortValue3;
          }
          else {
            g_ModelHierarchyTransformStackBaseTranslationX =
                 (*(int *)(entry + 0x58) * *(int *)(dataCursor + 4) >> 0xc) + (int)shortValue;
            g_ModelHierarchyTransformStackBaseTranslationY =
                 (*(int *)(entry + 0x5c) * *(int *)(dataCursor + 6) >> 0xc) + (int)shortValue2;
            g_ModelHierarchyTransformStackBaseTranslationZ =
                 (*(int *)(entry + 0x60) * *(int *)(dataCursor + 8) >> 0xc) + (int)shortValue3;
          }
          SetTransformBasisFromRef(&g_ModelHierarchyTransformStackBase);
          g_NatureTerrainRenderContext = *(undefined4 *)(dataCursor + 2);
          ApplySceneNodeFadeAndBlend(dataCursor,*(undefined4 *)(entry + 0xb0),entry + 0xb4);
          if ((*dataCursor & 0x7000) == 0x2000) {
            RenderSceneAssetNode(dataCursor);
          }
        }
      }
      dataCursor = dataCursor + 0x14;
    }
  }
  return;
}

