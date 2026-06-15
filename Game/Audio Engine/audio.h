#ifdef _WIN32
#include <windows.h>
#include <process.h>
#endif

#define NUM_SFX 25 // Current number of SFX files
#define NUM_BGM 8 // Current number of BGM files

#include "miniaudio.h"

ma_engine audioengine;

ma_sound soundFX[NUM_SFX];
ma_sound soundBGM[NUM_BGM];

char FXPaths[NUM_SFX][128] = 
{
  "Audio Engine/SFX/OpenMenu.mp3",
  "Audio Engine/SFX/CombatCursorMove.mp3",
  "Audio Engine/SFX/CursorMove.mp3",
  "Audio Engine/SFX/CombatCursorSelect.mp3",
  "Audio Engine/SFX/CursorSelect.mp3",
  "Audio Engine/SFX/LevelUp.mp3",
  "Audio Engine/SFX/ReturnFromMenu.mp3",
  "Audio Engine/SFX/UseItem.mp3",
  "Audio Engine/SFX/HitConfirm.mp3",
  "Audio Engine/SFX/CriticalHit.mp3",
  "Audio Engine/SFX/AQUA STORM.mp3",
  "Audio Engine/SFX/EARTH SMASH.mp3",
  "Audio Engine/SFX/WIND GUST.mp3",
  "Audio Engine/SFX/SCORCH FLAME.mp3",
  "Audio Engine/SFX/BLIZZARD.mp3",
  "Audio Engine/SFX/CloseGame.mp3",
  "Audio Engine/SFX/PlayerHit.mp3",
  "Audio Engine/SFX/OpenChest.mp3",
  "Audio Engine/SFX/FootStep.mp3",
  "Audio Engine/SFX/HealSpot.mp3",
  "Audio Engine/SFX/Speech.mp3",
  "Audio Engine/SFX/BossDefeated.mp3",
  "Audio Engine/SFX/EnemyDefeated.mp3",
  "Audio Engine/SFX/EnemyEncounter.mp3",
  "Audio Engine/SFX/PartyEscaped.mp3",
};

char BGMPaths[NUM_BGM][128] = 
{
  "Audio Engine/BGM/Intro.mp3",
  "Audio Engine/BGM/NameInput.mp3",
  "Audio Engine/BGM/HubTown.mp3",
  "Audio Engine/BGM/Area1.mp3",
  "Audio Engine/BGM/Area2.mp3",
  "Audio Engine/BGM/Area3.mp3",
  "Audio Engine/BGM/EnemyFight1.mp3",
  "Audio Engine/BGM/BossFight1.mp3",
};

int initAudioEngine() 
{
    ma_result result;
    result = ma_engine_init(NULL, &audioengine);
    if (result != MA_SUCCESS) { return -1; }

    for(char i = 0; i < NUM_SFX; i ++) 
    {
      result = ma_sound_init_from_file(&audioengine, FXPaths[i], MA_SOUND_FLAG_NO_PITCH | MA_SOUND_FLAG_NO_SPATIALIZATION, NULL, NULL, &soundFX[i]);
      if (result != MA_SUCCESS) { return -1; }
    }

    for(char i = 0; i < NUM_BGM; i ++) 
    {
      result = ma_sound_init_from_file(&audioengine, BGMPaths[i], MA_SOUND_FLAG_NO_PITCH | MA_SOUND_FLAG_NO_SPATIALIZATION, NULL, NULL, &soundBGM[i]);
      if (result != MA_SUCCESS) { return -1; }
      ma_sound_set_looping(&soundBGM[i], 1);
    }

    return 0;
}

void playSFX(char* sfxName) 
{
  for(char i = 0; i < NUM_SFX; i++) 
  {
    if(strstr(FXPaths[i], sfxName) != NULL) 
    { 
      ma_sound_seek_to_pcm_frame(&soundFX[i], 0);
      ma_sound_start(&soundFX[i]);
    }
  }
}

// SFX don't really need a stop() function.

void playBGM(char* bgmName) 
{
  for(char i = 0; i < NUM_BGM; i++) 
  {
    if(strstr(BGMPaths[i], bgmName) != NULL) 
    { 
      ma_sound_seek_to_pcm_frame(&soundBGM[i], 0);
      ma_sound_start(&soundBGM[i]);
    }
  }
}

void stopBGM(char* bgmName) 
{
  for(char i = 0; i < NUM_BGM; i++) 
  {
    if(strstr(BGMPaths[i], bgmName) != NULL) { ma_sound_stop(&soundBGM[i]); }
  }
}