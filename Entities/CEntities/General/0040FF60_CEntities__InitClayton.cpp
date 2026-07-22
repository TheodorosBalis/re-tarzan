#include "tarzan_ghidra_types.hpp"

// Address: 0x0040FF60
// Label: CEntities::InitClayton
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitClayton(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value3;
  int value2;
  
  g_ClaytonEntity = entry;
  value = entity->sceneObjects;
  ((EntitySceneObject *)value)->surfacePathIndex = *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
  ((EntitySceneObject *)value)->surfaceIndex = *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
  value2 = g_PlayerEntitySceneObject;
  ((EntitySceneObject *)value)->surfaceIndex = *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
  ((EntitySceneObject *)value)->surfacePathIndex = *(undefined4 *)(value2 + 0x110);
  ((EntitySceneObject *)value)->surface = *(undefined4 *)(g_PlayerEntitySceneObject + 0x114);
  ((EntitySceneObject *)value)->pad108 = *(undefined4 *)(g_PlayerEntitySceneObject + 0x108);
  ((EntitySceneObject *)value)->x = *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
  ((EntitySceneObject *)value)->y = *(undefined4 *)(g_PlayerEntitySceneObject + 0x18);
  value3 = *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c);
  *(undefined1 *)(value + 0x75) = 0;
  ((EntitySceneObject *)value)->z = value3;
  CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(value,0xfffff300);
  *(undefined4 *)(value + 0x6c) = 0xffffffd0;
  ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58);
  ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1ee0;
  *(undefined2 *)(value + 0xc) = 1;
  ((EntitySceneObject *)value)->roll = 0;
  CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_ClaytonScriptAttachmentDesc);
  CEntities::SelectEntityAnimationAttachmentState(entry,2);
  *(undefined2 *)(entry + 0x48) = 0x16;
  g_ClaytonAttackDamageWindowActive = 0;
  return;
}

