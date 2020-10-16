#include "Fuc.h"
float hpcalculate(float damage, float total_hp)
{
	
	total_hp = total_hp - damage;
	return total_hp;

}

float manacalculate(float manaDel, float total_mana)
{

	total_mana = total_mana - manaDel;
	return total_mana;

}