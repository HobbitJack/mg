#include <stdio.h>
#include <stdlib.h>

int
get_battery_percentage()
{
	return (int) 100 * (((float) rand()) / RAND_MAX);
}