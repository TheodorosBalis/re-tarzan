// 0x00446270

void CWorld::UpdateHud(void)

{
  UpdateHudHealthBar();
  UpdateOptionalHudMeterFill();
  UpdateHudPowerFruitSelector();
  UpdateHudLivesAndAvatar();
  UpdateHudCollectedSketch();
  UpdateHudCollectedTARZANslot();
  UpdateHudTokenCounterAndExtraLife();
  UpdateHudExtraLifeMeter();
  return;
}