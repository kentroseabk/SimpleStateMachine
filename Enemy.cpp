#include "Enemy.h"
#include "ConcreteEnemyStates.h"

Enemy::Enemy()
{
	CurrentState = &EnemyIdle::GetInstance();
}

void Enemy::SetState(EnemyState& NewState)
{
	CurrentState->Exit(this);
	CurrentState = &NewState;
	CurrentState->Enter(this);
}

void Enemy::SwitchState()
{
	CurrentState->SwitchState(this);
}

