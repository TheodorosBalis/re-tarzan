#include "tarzan_ghidra_types.hpp"

// Address: 0x00495070
// Label: ConfigureDefaultDirect3DRenderStates
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ConfigureDefaultDirect3DRenderStates(void)

{
  g_Direct3DRenderStateDirty = 0x80;
  g_Direct3DBackBufferPixelMask = 0x80;
  g_Direct3DRenderStateCurrentTexturePage = 0x80;
  if (g_Direct3DDevice != (int *)0x0) {
    g_Direct3DLastResult = (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0x1f,1);
    if (g_Direct3DDevice != (int *)0x0) {
      g_Direct3DLastResult = (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,4,1);
      if (g_Direct3DDevice != (int *)0x0) {
        g_Direct3DLastResult = (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,3,3);
        if (g_Direct3DDevice != (int *)0x0) {
          g_Direct3DLastResult = (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,9,2);
          if (g_Direct3DDevice != (int *)0x0) {
            g_Direct3DLastResult = (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0x1d,0);
            if (g_Direct3DDevice != (int *)0x0) {
              g_Direct3DLastResult =
                   (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0x11,2);
              if (g_Direct3DDevice != (int *)0x0) {
                g_Direct3DLastResult =
                     (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0x12,2);
                if (g_Direct3DDevice != (int *)0x0) {
                  g_Direct3DLastResult =
                       (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0x1a,1);
                  if (g_Direct3DDevice != (int *)0x0) {
                    g_Direct3DLastResult =
                         (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0x16,1);
                    if (g_Direct3DDevice != (int *)0x0) {
                      g_Direct3DLastResult =
                           (**(code **)(*g_Direct3DDevice + 0x5c))
                                     (g_Direct3DDevice,7,g_Direct3DDevice);
                      if (g_Direct3DDevice != (int *)0x0) {
                        g_Direct3DLastResult =
                             (**(code **)(*g_Direct3DDevice + 0x5c))
                                       (g_Direct3DDevice,0xe,g_Direct3DDevice);
                        if (g_Direct3DDevice != (int *)0x0) {
                          g_Direct3DLastResult =
                               (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0x17,4);
                          if (g_Direct3DDevice != (int *)0x0) {
                            g_Direct3DLastResult =
                                 (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0xf,1);
                            if (g_Direct3DDevice != (int *)0x0) {
                              g_Direct3DLastResult =
                                   (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0x19,5);
                              if (g_Direct3DDevice != (int *)0x0) {
                                g_Direct3DLastResult =
                                     (**(code **)(*g_Direct3DDevice + 0x5c))
                                               (g_Direct3DDevice,0x18,0);
                                if (g_Direct3DDevice != (int *)0x0) {
                                  g_Direct3DLastResult =
                                       (**(code **)(*g_Direct3DDevice + 0x5c))
                                                 (g_Direct3DDevice,0x1b,1);
                                  if (g_Direct3DDevice != (int *)0x0) {
                                    g_Direct3DLastResult =
                                         (**(code **)(*g_Direct3DDevice + 0x5c))
                                                   (g_Direct3DDevice,0x15,4);
                                    if (g_Direct3DDevice != (int *)0x0) {
                                      g_Direct3DLastResult =
                                           (**(code **)(*g_Direct3DDevice + 0x5c))
                                                     (g_Direct3DDevice,0x13,5);
                                      if (g_Direct3DDevice != (int *)0x0) {
                                        g_Direct3DLastResult =
                                             (**(code **)(*g_Direct3DDevice + 0x5c))
                                                       (g_Direct3DDevice,0x14,6);
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}

