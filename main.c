/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:04:28 by hheimerd          #+#    #+#             */
/*   Updated: 2020/10/23 17:04:34 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int					main()
{
	char			dest[10];
	int				undef = 1;
	char			con[1];
	char			res[7] = "\0\0\0\0\0\0\0";
	char			*dup;

	printf("===============strlen===============\n");
	printf("ft_strlen %3d || %-3lu strlen\n", ft_strlen("sa"), strlen("sa"));
	printf("ft_strlen %3d || %-3lu strlen\n", ft_strlen(""), strlen(""));
	printf("ft_strlen %3d || %-3lu strlen\n", ft_strlen("ssssssssssssssssssssssssssssss"), strlen("ssssssssssssssssssssssssssssss"));
	printf("\n=============strcpy===============\n");
	if (undef)
	{
		ft_strcpy(0, "dw");
		ft_strcpy("ds", 0);
	}
	printf("src /%s/ => \nret /%s/ = \ndst /%s/\n", "test",ft_strcpy(dest, "test"), dest);
	printf("src /%s/ => \nret /%s/ = \ndst /%s/\n", "test\200",ft_strcpy(dest, "test\200"), dest);
	// printf("src /%s/ => \nret /%s/ = \ndst /%s/\n", "qwertyuiopasdfghjkl;zxcvbnm,./sdfghjkl;/~©ƒ©®∂ß®∂",ft_strcpy(dest, "qwertyuiopasdfghjkl;zxcvbnm,./sdfghjkl;/~©ƒ©®∂ß®∂"), dest);
	printf("src /%s/ => \nret /%s/ = \ndst /%s/\n", "",ft_strcpy(dest, ""), dest);
	printf("ret %p = dest %p\n", ft_strcpy(dest, "test"), dest);
	printf("\n=============strcmp===============\n");
	printf("ft_strcmp %2d || %-2d strcmp\n", ft_strcmp("da", "da"), strcmp("da", "da"));
	printf("ft_strcmp %2d || %-2d strcmp\n", ft_strcmp("d", "d"), strcmp("d", "d"));
	printf("ft_strcmp %2d || %-2d strcmp\n", ft_strcmp("d", "da"), strcmp("d", "da"));
	printf("ft_strcmp %2d || %-2d strcmp\n", ft_strcmp("da", "d"), strcmp("da", "d"));
	printf("ft_strcmp %2d || %-2d strcmp\n", ft_strcmp("da", "ds"), strcmp("da", "ds"));
	printf("ft_strcmp %2d || %-2d strcmp\n", ft_strcmp("das", "ds"), strcmp("das", "ds"));
	printf("ft_strcmp %2d || %-2d strcmp\n", ft_strcmp("ds", "da"), strcmp("ds", "da"));
	printf("ft_strcmp %2d || %-2d strcmp\n", ft_strcmp("123", "321"), strcmp("123", "321"));
	printf("ft_strcmp %2d || %-2d strcmp\n", ft_strcmp("123", "123"), strcmp("123", "123"));
	printf("ft_strcmp %2d || %-2d strcmp\n", ft_strcmp("\0", "\200"), strcmp("\0", "\200"));
	printf("\n=============write===============\n");
	int	fd = open("test", O_RDWR);
	printf("ft_write: 0 = %zd\n", ft_write(fd, "123456", 0));
	read(0, con, 1);
	printf("ft_write: 1 = %zd\n", ft_write(fd, "123456", 1));
	lseek(fd, 0, SEEK_SET);
	read(0, con, 1);
	printf("ft_write: 6 = %zd\n", ft_write(fd, "123456", 6));
	read(0, con, 1);
	lseek(fd, 0, SEEK_SET);
	printf("ft_write fake fd -1 = %zd\n", ft_write(10, "123456", 6));
	printf("errno: %d\n", errno);
	printf("ft_write fake fd -1 = %zd\n", ft_write(9809, "bonjour", 7));
	printf("errno: %d\n", errno);
	printf("\n=============read================\n");
	printf("ft_read(fd, res, 3) 3 из 6 = %zd\n", ft_read(fd, res, 3));
	printf("res: /%s/\n", res);
	printf("ft_read(fd, res, 5) 3 + 5 из 6 = %zd\n", ft_read(fd, res, 5));
	printf("res: /%s/\n", res);
	printf("ft_read(fd, res, 1) 6 из 6 = %zd\n", ft_read(fd, res, 1));
	printf("res: /%s/\n", res);
	printf("ft_read fake fd -1 = %zd\n", ft_read(10, res, 1));
	printf("res: /%s/\n", res);
	printf("errno: %d\n", errno);
	read(0, con, 1);
	close(fd);
	printf("\n=============strdup===============\n");
	dup = ft_strdup("1234567890");
	if (dup)
	{
		printf("'1234567890' = '%s'\n", dup);
		printf("dup[10] = %d\n", dup[10]);
		printf("free(dup)\n\n");
		free(dup);
	}
	else
		printf("alloc error\n");
	dup = ft_strdup("");
	if (dup)
	{
		printf("'' = '%s'\n", dup);
		printf("dup[0] = %d\n", dup[0]);
		printf("free(dup)\n\n");
		free(dup);
	}
	else
		printf("alloc error\n");
	return (0);
}