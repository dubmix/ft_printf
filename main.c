#include "ft_printf.h"

int	main(void)
{	
	//int a = 12;
	//int *b = &a;

	ft_printf("H%6.3dello W%#xorld!", -42, 3567);
	write(1, "\n", 1);
	printf("H%6.3dello W%#xorld!", -42, 3567);
		
	return (5);
}
