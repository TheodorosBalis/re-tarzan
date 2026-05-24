
void TriggerHudExtraLifeAward(void)

{
  if (g_HudExtraLifeAwardScene != 0) {
    g_ExtraLifeAwardState = 1;
    return;
  }
  g_LevelTransitionContext._3_1_ = g_LevelTransitionContext._3_1_ + '\x01';
  if ('c' < g_LevelTransitionContext._3_1_) {
    g_LevelTransitionContext._3_1_ = 'c';
  }
  return;
}

