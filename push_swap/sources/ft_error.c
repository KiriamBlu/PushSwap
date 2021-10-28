#include "ps_header.h"

int	ft_get_no_dup(int argc, char const **argv, char *aux)
{
	size_t count;

	count = 0;
	while (count < argc)
	{
		if(ft_strcmp(*argv[count], aux) == -1)
			return(-1);
		count++;
	}
	return(1);
}
int	ft_not_short(int argc, char	const **argv)
{
	size_t count;

	count = 0;
	while(count < argc - 1)
	{
		// AÑADIR AQUI LA COMPARACIÖN PARA ENCONTRAR EL MAYOR Y MENOR
		if (*argv[count] < *argv[count + 1])
			return(-1)
		count++;
	}
	return(1);	
}

int	ft_error(int argc, char const **argv)
{
	char *aux;

	if (ft_not_short(argc, argv) == -1)
		return(-1)
	while (argc-- > 1)
	{
		aux = ft_strdup(*argv[argc]);
		if (ft_get_no_dup(argc, argv, aux) == -1)
		{
			free(aux);
			return (-1);
		}
	}
}