#include "libft.h"

int	converttosignedchar(int vl, int mode)
{
	int	i;

	i = 0;
	if (mode == 1 && (vl < -32768 || vl > 32767))
	{
		while (vl < -32768)
			vl += 65536;
		while (vl > 127)
			vl -= 65536;
	}
	else if (mode == 2 && (vl < -128 || vl > 127))
	{
		while (vl < -128)
			vl += 256;
		while (vl > 127)
			vl -= 256;
	}
	else if (mode == 3 && vl > 127)
	{
		while (vl > 127)
			vl -= 128;
	}
	return (vl);
}
