#include "ConcreteEnemyStates.h"

void EnemyIdle::SwitchState(Enemy* enemy)
{
	if (!enemy->IsAlive())
	{
		enemy->SetState(EnemyDead::GetInstance());
		return;
	}

	if (!enemy->IsPlayerDead() && enemy->IsPlayerSpotted())
	{
		enemy->SetState(EnemyFight::GetInstance());
	}
}

EnemyState& EnemyIdle::GetInstance()
{
	static EnemyIdle singleton;
	return singleton;
}

void EnemyFight::SwitchState(Enemy* enemy)
{
	if (!enemy->IsAlive())
	{
		enemy->SetState(EnemyDead::GetInstance());
		return;
	}

	if (enemy->IsHealthLow())
	{
		enemy->SetState(EnemyRecover::GetInstance());
	} else if (!enemy->IsPlayerSpotted() || enemy->IsPlayerDead())
	{
		enemy->SetState(EnemyIdle::GetInstance());
	}
}

EnemyState& EnemyFight::GetInstance()
{
	static EnemyFight singleton;
	return singleton;
}

void EnemyRecover::SwitchState(Enemy* enemy)
{
	if (!enemy->IsAlive())
	{
		enemy->SetState(EnemyDead::GetInstance());
		return;
	}

	if (!enemy->IsHealthLow() && enemy->IsPlayerSpotted() && !enemy->IsPlayerDead())
	{
		enemy->SetState(EnemyFight::GetInstance());
	}
	else if (!enemy->IsHealthLow())
	{
		enemy->SetState(EnemyIdle::GetInstance());
	}
}

EnemyState& EnemyRecover::GetInstance()
{
	static EnemyRecover singleton;
	return singleton;
}

void EnemyDead::SwitchState(Enemy* enemy)
{

}

EnemyState& EnemyDead::GetInstance()
{
	static EnemyDead singleton;
	return singleton;
}