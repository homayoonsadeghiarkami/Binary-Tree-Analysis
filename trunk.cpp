#include "trunk.h"

Trunk::Trunk(Trunk *prev, string str)
{
	this->prev = prev;
	this->str = str;
}
