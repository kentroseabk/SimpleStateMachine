#pragma once

class Enemy;

class EnemyState
{
public:
	virtual void Enter(Enemy* enemy) = 0;
	virtual void SwitchState(Enemy* enemy) = 0;
	virtual void Exit(Enemy* enemy) = 0;
	virtual void Print(Enemy* enemy) = 0;
	virtual ~EnemyState() {}
};

