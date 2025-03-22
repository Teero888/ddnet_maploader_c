#ifndef MAP_LOADER_H
#define MAP_LOADER_H

enum {
  ENTITY_NULL = 0,
  ENTITY_SPAWN,
  ENTITY_SPAWN_RED,
  ENTITY_SPAWN_BLUE,
  ENTITY_FLAGSTAND_RED,
  ENTITY_FLAGSTAND_BLUE,
  ENTITY_ARMOR_1,
  ENTITY_HEALTH_1,
  ENTITY_WEAPON_SHOTGUN,
  ENTITY_WEAPON_GRENADE,
  ENTITY_POWERUP_NINJA,
  ENTITY_WEAPON_LASER,
  // DDRace - Main Lasers
  ENTITY_LASER_FAST_CCW,
  ENTITY_LASER_NORMAL_CCW,
  ENTITY_LASER_SLOW_CCW,
  ENTITY_LASER_STOP,
  ENTITY_LASER_SLOW_CW,
  ENTITY_LASER_NORMAL_CW,
  ENTITY_LASER_FAST_CW,
  // DDRace - Laser Modifiers
  ENTITY_LASER_SHORT,
  ENTITY_LASER_MEDIUM,
  ENTITY_LASER_LONG,
  ENTITY_LASER_C_SLOW,
  ENTITY_LASER_C_NORMAL,
  ENTITY_LASER_C_FAST,
  ENTITY_LASER_O_SLOW,
  ENTITY_LASER_O_NORMAL,
  ENTITY_LASER_O_FAST,
  // DDRace - Plasma
  ENTITY_PLASMAE = 29,
  ENTITY_PLASMAF,
  ENTITY_PLASMA,
  ENTITY_PLASMAU,
  // DDRace - Shotgun
  ENTITY_CRAZY_SHOTGUN_EX,
  ENTITY_CRAZY_SHOTGUN,
  // DDNet - Removing specific weapon
  ENTITY_ARMOR_SHOTGUN,
  ENTITY_ARMOR_GRENADE,
  ENTITY_ARMOR_NINJA,
  ENTITY_ARMOR_LASER,
  // DDRace - Draggers
  ENTITY_DRAGGER_WEAK = 42,
  ENTITY_DRAGGER_NORMAL,
  ENTITY_DRAGGER_STRONG,
  // Draggers Behind Walls
  ENTITY_DRAGGER_WEAK_NW,
  ENTITY_DRAGGER_NORMAL_NW,
  ENTITY_DRAGGER_STRONG_NW,
  // Doors
  ENTITY_DOOR = 49,
  // End Of Lower Tiles
  NUM_ENTITIES,
  // Start From Top Left
  // Tile Controllers
  TILE_AIR = 0,
  TILE_SOLID,
  TILE_DEATH,
  TILE_NOHOOK,
  TILE_NOLASER,
  TILE_THROUGH_CUT,
  TILE_THROUGH,
  TILE_JUMP,
  TILE_FREEZE = 9,
  TILE_TELEINEVIL,
  TILE_UNFREEZE,
  TILE_DFREEZE,
  TILE_DUNFREEZE,
  TILE_TELEINWEAPON,
  TILE_TELEINHOOK,
  TILE_WALLJUMP = 16,
  TILE_EHOOK_ENABLE,
  TILE_EHOOK_DISABLE,
  TILE_HIT_ENABLE,
  TILE_HIT_DISABLE,
  TILE_SOLO_ENABLE,
  TILE_SOLO_DISABLE,
  // Switches
  TILE_SWITCHTIMEDOPEN = 22,
  TILE_SWITCHTIMEDCLOSE,
  TILE_SWITCHOPEN,
  TILE_SWITCHCLOSE,
  TILE_TELEIN,
  TILE_TELEOUT,
  TILE_SPEED_BOOST_OLD = 28,
  TILE_SPEED_BOOST,
  TILE_TELECHECK = 29,
  TILE_TELECHECKOUT,
  TILE_TELECHECKIN,
  TILE_REFILL_JUMPS = 32,
  TILE_START,
  TILE_FINISH,
  TILE_TIME_CHECKPOINT_FIRST = 35,
  TILE_TIME_CHECKPOINT_LAST = 59,
  TILE_STOP = 60,
  TILE_STOPS,
  TILE_STOPA,
  TILE_TELECHECKINEVIL,
  TILE_CP,
  TILE_CP_F,
  TILE_THROUGH_ALL,
  TILE_THROUGH_DIR,
  TILE_TUNE,
  TILE_OLDLASER = 71,
  TILE_NPC,
  TILE_EHOOK,
  TILE_NOHIT,
  TILE_NPH,
  TILE_UNLOCK_TEAM,
  TILE_ADD_TIME = 79,
  TILE_NPC_DISABLE = 88,
  TILE_UNLIMITED_JUMPS_DISABLE,
  TILE_JETPACK_DISABLE,
  TILE_NPH_DISABLE,
  TILE_SUBTRACT_TIME = 95,
  TILE_TELE_GUN_ENABLE = 96,
  TILE_TELE_GUN_DISABLE = 97,
  TILE_ALLOW_TELE_GUN = 98,
  TILE_ALLOW_BLUE_TELE_GUN = 99,
  TILE_NPC_ENABLE = 104,
  TILE_UNLIMITED_JUMPS_ENABLE,
  TILE_JETPACK_ENABLE,
  TILE_NPH_ENABLE,
  TILE_TELE_GRENADE_ENABLE = 112,
  TILE_TELE_GRENADE_DISABLE = 113,
  TILE_TELE_LASER_ENABLE = 128,
  TILE_TELE_LASER_DISABLE = 129,
  TILE_CREDITS_1 = 140,
  TILE_CREDITS_2 = 141,
  TILE_CREDITS_3 = 142,
  TILE_CREDITS_4 = 143,
  TILE_LFREEZE = 144,
  TILE_LUNFREEZE = 145,
  TILE_CREDITS_5 = 156,
  TILE_CREDITS_6 = 157,
  TILE_CREDITS_7 = 158,
  TILE_CREDITS_8 = 159,
  TILE_ENTITIES_OFF_1 = 190,
  TILE_ENTITIES_OFF_2,
  // End of higher tiles
  // Layers
  LAYER_GAME = 0,
  LAYER_FRONT,
  LAYER_TELE,
  LAYER_SPEEDUP,
  LAYER_SWITCH,
  LAYER_TUNE,
  NUM_LAYERS,
  // Flags
  TILEFLAG_XFLIP = 1,
  TILEFLAG_YFLIP = 2,
  TILEFLAG_OPAQUE = 4,
  TILEFLAG_ROTATE = 8,
  // Rotation
  ROTATION_0 = 0,
  ROTATION_90 = TILEFLAG_ROTATE,
  ROTATION_180 = (TILEFLAG_XFLIP | TILEFLAG_YFLIP),
  ROTATION_270 = (TILEFLAG_XFLIP | TILEFLAG_YFLIP | TILEFLAG_ROTATE),

  ENTITY_OFFSET = 255 - 16 * 4,
};

typedef struct GameLayer {
  unsigned char *m_pData;
  unsigned char *m_pFlags;
} SGameLayer;

typedef struct TeleLayer {
  unsigned char *m_pNumber;
  unsigned char *m_pType;
} STeleLayer;

typedef struct SpeedupLayer {
  unsigned char *m_pForce;
  unsigned char *m_pMaxSpeed;
  unsigned char *m_pType;
  short *m_pAngle;
} SSpeedupLayer;

typedef struct SwitchLayer {
  unsigned char *m_pNumber;
  unsigned char *m_pType;
  unsigned char *m_pFlags;
  unsigned char *m_pDelay;
} SSwitchLayer;

typedef struct DoorLayer {
  unsigned char *m_pIndex;
  unsigned char *m_pFlags;
  int *m_pNumber;
} SDoorLayer;

typedef struct TuneLayer {
  unsigned char *m_pNumber;
  unsigned char *m_pType;
} STuneLayer;

typedef struct {
  float x, y;
} v2;

typedef struct MapData {
  int m_Width;
  int m_Height;

  SGameLayer m_GameLayer;
  SGameLayer m_FrontLayer;
  STeleLayer m_TeleLayer;
  SSpeedupLayer m_SpeedupLayer;
  SSwitchLayer m_SwitchLayer;
  SDoorLayer m_DoorLayer;
  STuneLayer m_TuneLayer;

  int m_NumSettings;
  char **m_ppSettings;

  int m_NumSpawnPoints;
  int m_NumTeleOuts;
  int m_NumTeleCheckOuts;
  v2 *m_pSpawnPoints;
  v2 *m_pTeleOuts;
  v2 *m_pTeleCheckOuts;

} SMapData;

SMapData load_map(const char *pName);
void free_map_data(SMapData *pMapData);

#endif // MAP_LOADER_H
