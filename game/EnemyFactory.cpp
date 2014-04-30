#include "EnemyFactory.h"

#include <random>
#include <ctime>

using namespace std;


EnemyFactory & EnemyFactory::instance()
{
	// Dummy, just to make this compile -- won't work.
	return * static_cast<EnemyFactory*>(NULL);
}

EnemyFactory::EnemyFactory()
{
}

EnemyFactory::~EnemyFactory()
{
}

int EnemyFactory::randomValue(int iMax)
{
	static mt19937 mt(time(NULL));
	return mt() % iMax;
}
