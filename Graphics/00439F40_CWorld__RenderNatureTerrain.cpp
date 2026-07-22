#include "tarzan_ghidra_types.hpp"

// Address: 0x00439F40
// Label: CWorld::RenderNatureTerrain
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CWorld::RenderNatureTerrain(void)

{
  int value;
  undefined4 value3;
  undefined4 *dataCursor;
  int value2;
  
  value = g_CurrentWorldSceneContext;
  if ((g_NatureTerrainFlags & 2) != 0) {
    g_SceneTransformScratch_Field0012 = 0xffff;
    SetDrawWindow(g_RenderWorldSceneActive,0);
    g_NatureTerrainRenderContext = value;
    g_SceneTransformScratch_Field000B = 0;
    SetProjectionScreenOrigin
              (g_RenderNatureTerrainViewportCenterX,g_RenderNatureTerrainViewportCenterY);
    SetProjectionDepthScale(g_CameraDistanceScale);
    SetFadeBrightnessAndTint(g_FadeDrawEnabled,&g_FadeCurrentBrightness);
    UpdateRenderCameraState(&g_CameraFocusX);
    SetTransformBasisFromRef(&DAT_0051c530);
    if (g_NatureTerrainRenderEntryCount != 0) {
      dataCursor = &DAT_0051d2fc;
      value2 = g_NatureTerrainRenderEntryCount;
      do {
        value3 = ComputeNatureTerrainCellVisibility(dataCursor + -3);
        *dataCursor = value3;
        dataCursor = dataCursor + 5;
        value2 = value2 + -1;
      } while (value2 != 0);
    }
    dataCursor = &DAT_0051d2ec;
    for (value2 = g_NatureTerrainRenderEntryCount; value2 != 0; value2 = value2 + -1) {
      if (dataCursor[4] != 0) {
        RenderNatureTerrainCellEntitySceneObjects(*dataCursor,&g_CameraFocusX);
      }
      dataCursor = dataCursor + 5;
    }
  }
  if ((g_NatureTerrainFlags & 1) != 0) {
    RenderWorldBitmapLayers(value + 0x10);
    return;
  }
  LegacyTransitionCallback_Stub(0,0,0);
  return;
}

