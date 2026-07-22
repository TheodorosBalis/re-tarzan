#include "tarzan_ghidra_types.hpp"

// Address: 0x0043A1A0
// Label: RenderNatureTerrainModelEntry
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RenderNatureTerrainModelEntry(int graphicsObject,int source2,int dest)

{
  uint value;
  undefined *dataCursor;
  
  if ((*(byte *)(source2 + 10) & 1) == 0) {
    dataCursor = (undefined *)BuildNatureTerrainEntitySceneObjectTransform(graphicsObject,dest);
  }
  else {
    _g_NatureTerrainRenderScratch_Field5BF8 = *(short *)(graphicsObject + 0x20) - (short)g_CameraFocusX;
    dataCursor = &g_RenderCameraScaleBasisXX;
    _g_NatureTerrainRenderScratch_Field5BFA = *(short *)(graphicsObject + 0x24) - (short)g_CameraFocusY;
    _g_NatureTerrainRenderScratch_Field5BFC = *(short *)(graphicsObject + 0x28) - (short)g_CameraFocusZ;
    _g_NatureTerrainRenderScratch_Field19C60 = *(int *)(graphicsObject + 0x20) - g_CameraFocusX;
    _g_NatureTerrainRenderScratch_Field19C64 = *(int *)(graphicsObject + 0x24) - g_CameraFocusY;
    _g_NatureTerrainRenderScratch_Field19C68 = *(int *)(graphicsObject + 0x28) - g_CameraFocusZ;
    TransformVectorByBasis
              (dest + 0x68,&g_NatureTerrainRenderScratch_Field19C60,
               &g_NatureTerrainRenderScratch_Field0014);
    g_NatureTerrainRenderScratch_Field0014 =
         g_NatureTerrainRenderScratch_Field0014 + *(int *)(dest + 0x7c);
    g_NatureTerrainRenderScratch_Field0018 =
         g_NatureTerrainRenderScratch_Field0018 + *(int *)(dest + 0x80);
    g_NatureTerrainRenderScratch_Field001C =
         g_NatureTerrainRenderScratch_Field001C + *(int *)(dest + 0x84);
  }
  SetTransformBasisFromRef(dataCursor);
  SetDrawWindow(0,*(undefined4 *)(graphicsObject + 0x70));
  value = ClassifyProjectedBoundsVisibility(*(int *)(source2 + 0xc) + 0xc + source2);
  if ((value != 0) && (g_SceneTransformScratch_Field0012 < 0)) {
    if ((value & 6) != 0) {
      RenderSceneAssetIfVisible_Thunk();
      return;
    }
    RenderSceneAssetIfVisible(source2,0x800);
  }
  return;
}

