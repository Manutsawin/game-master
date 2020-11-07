#include "Fuc.h"
float hpcalculate(float damage, float total_hp)
{
	
	total_hp = total_hp - damage;
	if (total_hp < 1)
	{
		total_hp = 1;
	}
	if (total_hp > 48)
	{
		total_hp = 48;
	}
	return total_hp;

}

float manacalculate(float manaDel, float total_mana)
{

	total_mana = total_mana - manaDel;
	if (total_mana < 1)
	{
		total_mana = 1;
	}
	if (total_mana > 26)
	{
		total_mana = 26;
	}
	return total_mana;

}


float selectIcon(float totalmana)
{
	float value=0;
	if (totalmana >= 21)
	{
		value = 600;
	}
	else if (totalmana >= 14)
	{
		value = 400;
	}
	else if (totalmana >= 7)
	{
		value = 200;
	}
	else
	{
		value = 0;
	}
	return value;
}