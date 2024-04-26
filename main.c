/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:57:02 by tluegham          #+#    #+#             */
/*   Updated: 2024/04/26 11:32:20 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

#define STR(x)   #x
#define SHOW_DEFINE(x) printf("%s=%s\n", #x, STR(x))

int	main(int argc, char **argv)
{
	int		fd;
	char	*file_path;
	char	*res;

	if (argc < 2)
	{
		printf("not enough arguments!\n");
		return (1);
	}
	file_path = argv[1];
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		printf("file \"%s\" could not be opened!\n", file_path);
		return (1);
	}
	SHOW_DEFINE(BUFFER_SIZE);
	res = get_next_line(fd);
	while (res != NULL)
	{
		printf("%s", res);
		free(res);
		res = get_next_line(fd);
	}
	free(res);
	close(fd);
	return (0);
}
