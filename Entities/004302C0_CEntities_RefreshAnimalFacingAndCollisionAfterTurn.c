
void CEntities__RefreshAnimalFacingAndCollisionAfterTurn(undefined4 param_1,undefined4 param_2)

{
  CEntities__MoveSceneEntryAndSnapFacingAngles(param_1,0);
  CEntities__CheckSceneEntryCollisionDelta(param_2);
  return;
}

