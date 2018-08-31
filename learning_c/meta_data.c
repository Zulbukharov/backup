/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 22:01:34 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/16 18:33:46 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

typedef struct	s_meta
{
	uint32_t 	len;
	unsigned char type;
	char name[16];
}				t_meta;

int		main(int ac, char **av)
{
	int fd;
	t_meta *meta;
	struct stat buff;

	meta = malloc(sizeof(meta));
	if (ac < 1)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		return (0);
	stat(av[1], &buff);
	printf("total size: %lld\n", buff.st_size);
	printf("ID of device: %d\n", buff.st_dev);
	printf("protection: %d\n", buff.st_mode);
	printf("%lld\n", buff.st_atime);
	
	//dev_t     st_dev;     /* ID of device containing file */
    //ino_t     st_ino;     /* inode number */
    //mode_t    st_mode;    /* protection */
    //nlink_t   st_nlink;   /* number of hard links */
    //uid_t     st_uid;     /* user ID of owner */
    //gid_t     st_gid;     /* group ID of owner */
    //dev_t     st_rdev;    /* device ID (if special file) */
    //off_t     st_size;    /* total size, in bytes */
    //blksize_t st_blksize; /* blocksize for file system I/O */
    //blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
    //time_t    st_atime;   /* time of last access */
    //time_t    st_mtime;   /* time of last modification */
    //time_t    st_ctime;   /* time of last status change */
	
	close(fd);
	return (0);
}
