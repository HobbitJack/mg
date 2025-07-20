#include <stdio.h>
#include <stdlib.h>

int
get_battery_percentage()
{
	int cnow, cfull;
	FILE* f_cnow, *f_cfull;
	
	f_cnow = fopen("/sys/class/power_supply/BAT1/charge_now", "r");
	f_cfull = fopen("/sys/class/power_supply/BAT1/charge_full", "r");
	if ((f_cnow == NULL) || (f_cfull == NULL))
		return -1;

	fscanf(f_cnow, "%d", &cnow);
	fscanf(f_cfull, "%d", &cfull);
	
	return (int) 100 * (((float) cnow) / cfull);
}

/* int
get_battery_percentage()
{
	return (int) 100 * (((float) rand()) / RAND_MAX);
} */