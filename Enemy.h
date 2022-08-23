#pragma once
#include "EnemyState.h"

class EnemyState;

class Enemy
{
public:
	Enemy();
	inline EnemyState* GetCurrentState() const { return CurrentState; }
	void SwitchState();
	void SetState(EnemyState& NewState);
	
	float GetHealth() { return Health; }
	void TakeDamage(float damage) { Health -= damage; }
	bool IsAlive() { return Health > 0; }
	bool IsHealthLow() { return Health <= 25.0f; }
	void RecoverHealth() { Health += 25.0f; }

	bool IsPlayerSpotted() { return PlayerSpotted; }
	void SetPlayerSpotted(bool NewPlayerSpotted) { PlayerSpotted = NewPlayerSpotted; }

	bool IsPlayerDead() { return PlayerDead; }
	void SetPlayerDead(bool NewPlayerDead) { PlayerDead = NewPlayerDead; }

private:
	EnemyState* CurrentState;

	float Health = 100.0f;
	bool PlayerSpotted = false;
	bool PlayerDead = false;
};

