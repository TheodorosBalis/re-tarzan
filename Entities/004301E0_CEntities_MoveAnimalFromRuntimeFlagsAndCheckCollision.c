
undefined1
CEntities__MoveAnimalFromRuntimeFlagsAndCheckCollision
          (int param_1,undefined4 param_2,int param_3,int param_4)

{
  ushort uVar1;
  undefined1 uVar2;
  
  uVar1 = *(ushort *)(param_1 + 0x4a);
  if ((uVar1 & 0x20) == 0) {
    if (((uVar1 & 2) != 0) || (param_3 = param_4, (uVar1 & 1) != 0)) goto LAB_0043021e;
  }
  else {
    if ((uVar1 & 2) != 0) {
      param_3 = -param_3;
      goto LAB_0043021e;
    }
    if ((uVar1 & 1) != 0) {
      param_3 = -param_4;
      goto LAB_0043021e;
    }
  }
  param_3 = 0;
LAB_0043021e:
  CEntities__MoveSceneEntryAndEaseFacingAngles(param_1,param_3);
  uVar2 = CEntities__CheckSceneEntryCollisionDelta(param_2);
  return uVar2;
}

