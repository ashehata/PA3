#ifndef _EnemyFactory_included_
#define _EnemyFactory_included_

#include "Enemy.h"

#include <vector>

class EnemyFactory
{
public:	
	static EnemyFactory & instance();
	virtual ~EnemyFactory();
	Enemy * generateEnemy(int iMaxLevel);
	static int randomValue(int iMax);

private:
	EnemyFactory();
	std::vector<Enemy*> m_vEnemies;
};

#endif
