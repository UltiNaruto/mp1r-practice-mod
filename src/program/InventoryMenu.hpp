#pragma once

#include "types.h"

class CPowerUp {
public:
  int amount;
  int capacity;
};
class CPlayerStateMP1 {
public:
  enum class EItemType : int {
    Invalid = -1,
    PowerBeam = 0,
    IceBeam = 1,
    WaveBeam = 2,
    PlasmaBeam = 3,
    Missiles = 4,
    ScanVisor = 5,
    MorphBallBombs = 6,
    PowerBombs = 7,
    Flamethrower = 8,
    ThermalVisor = 9,
    ChargeBeam = 10,
    SuperMissile = 11,
    GrappleBeam = 12,
    XRayVisor = 13,
    IceSpreader = 14,
    SpaceJumpBoots = 15,
    MorphBall = 16,
    CombatVisor = 17,
    BoostBall = 18,
    SpiderBall = 19,
    PowerSuit = 20,
    GravitySuit = 21,
    VariaSuit = 22,
    PhazonSuit = 23,
    EnergyTanks = 24,
    UnknownItem1 = 25,
    HealthRefill = 26,
    UnknownItem2 = 27,
    Wavebuster = 28,
    Truth = 29,
    Strength = 30,
    Elder = 31,
    Wild = 32,
    Lifegiver = 33,
    Warrior = 34,
    Chozo = 35,
    Nature = 36,
    Sun = 37,
    World = 38,
    Spirit = 39,
    Newborn = 40,
    Max
  };

  bool HasPowerUp(EItemType type) const;
  bool AddPowerUp(EItemType type, int amount);
  void IncrPickUp(CPlayerStateMP1::EItemType, int);
  void SetPickup(EItemType type, int amount);
  void SetPowerUp(EItemType type, int amount);
  int GetPowerUp(EItemType type);
  int GetItemCapacity(EItemType type) const;

  inline CPowerUp* GetPowerups() { return reinterpret_cast<CPowerUp*>(reinterpret_cast<size_t>(this) + 0x44); }

  static int GetItemMax(EItemType type);
//  _ZN15CPlayerStateMP110GetItemMaxE9EItemType
//  _ZN15CPlayerStateMP110GetItemMaxENS_9EItemTypeE
//  _ZNK15CPlayerStateMP115GetItemCapacityENS_9EIt
//  _ZN15CPlayerStateMP115GetItemCapacityENS_9EItemTypeE

};


class CGameStateMP1 {
public:
//  CPlayerStateMP1* GetPlayerState() const;
  CPlayerStateMP1* PlayerState();
  inline CPlayerStateMP1* GetPlayerState_2() { return reinterpret_cast<CPlayerStateMP1*>(reinterpret_cast<size_t>(this) + 0x20); }
};
extern CGameStateMP1* gpGameState;

class CPlayerMP1;
class CStateManagerGameLogicMP1 {
public:
  static CPlayerStateMP1 *PlayerState();
  CPlayerMP1 *PlayerActor();
};

class CStateManager {
public:
  inline CStateManagerGameLogicMP1* GameLogic() {
      return reinterpret_cast<CStateManagerGameLogicMP1*>(reinterpret_cast<size_t>(this) + 0x4e0150);
  }
};
namespace GUI {
  void drawInventoryMenu();
}