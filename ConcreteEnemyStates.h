#pragma once
#include <iostream>
#include "EnemyState.h"
#include "Enemy.h"

using namespace std;

class EnemyIdle : public EnemyState
{
public:
	void Enter(Enemy* enemy) {};
	void SwitchState(Enemy* enemy);
	void Exit(Enemy* enemy) {};
	static EnemyState& GetInstance();
	void Print(Enemy* enemy) { cout << "Enemy idling, health: " << enemy->GetHealth() << endl; }

private:
	EnemyIdle() {}
	EnemyIdle(const EnemyIdle& other);
	EnemyIdle& operator=(const EnemyIdle& other);
};

class EnemyFight : public EnemyState
{
public:
	void Enter(Enemy* enemy) {};
	void SwitchState(Enemy* enemy);
	void Exit(Enemy* enemy) {};
	static EnemyState& GetInstance();
	void Print(Enemy* enemy) { cout << "Enemy fighting, health: " << enemy->GetHealth() << endl; }

private:
	EnemyFight() {}
	EnemyFight(const EnemyFight& other);
	EnemyFight& operator=(const EnemyFight& other);
};

class EnemyRecover : public EnemyState
{
public:
	void Enter(Enemy* enemy) 
	{
		enemy->RecoverHealth();
	};
	void SwitchState(Enemy* enemy);
	void Exit(Enemy* enemy) {};
	static EnemyState& GetInstance();
	void Print(Enemy* enemy) { cout << "Enemy recovering, health: " << enemy->GetHealth() << endl; }

private:
	EnemyRecover() {}
	EnemyRecover(const EnemyRecover& other);
	EnemyRecover& operator=(const EnemyRecover& other);
};

class EnemyDead : public EnemyState
{
public:
	void Enter(Enemy* enemy) {};
	void SwitchState(Enemy* enemy);
	void Exit(Enemy* enemy) {};
	static EnemyState& GetInstance();
	void Print(Enemy* enemy) { cout << "Enemy dead, health: " << enemy->GetHealth() << endl; }

private:
	EnemyDead() {}
	EnemyDead(const EnemyDead& other);
	EnemyDead& operator=(const EnemyDead& other);
};