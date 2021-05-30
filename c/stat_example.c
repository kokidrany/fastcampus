#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	struct stat sb;
	int ret;
	if (argc < 2){
		printf("Usage: %s <files>\n", argv[0]);
		return -1;
	}
	ret = stat(argv[1], &sb);
	if (ret){
		perror("stat error: ");
		return -1;
	}

	switch (sb.st_mode & S_IFMT){
		case S_IFBLK:
			printf("block device node\n");
			break;
		case S_IFCHR:
			printf("character device node\n");
			break;
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFIFO:
			printf("FIFO\n");
			break;
		case S_IFLNK:
			printf("symbolic link\n");
			break;
		case S_IFREG:
			printf("regular file\n");
			break;
		case S_IFSOCK:
			printf("socket\n");
			break;
		default:
			printf("unkonwn\n");
			break;
	}

	printf("file(%s) is %ld bytes\n", argv[1], sb.st_size);
	printf("ino_t(%s) is %ld inode\n", argv[1], sb.st_ino);
	printf("mode_t(%s) is %ld mode\n", argv[1], sb.st_mode);
	printf("nlink_t(%s) is %ld nlink\n", argv[1], sb.st_nlink);
	printf("uid_t(%s) is %ld userid\n", argv[1], sb.st_uid);
	printf("gid_t(%s) is %ld groupid\n", argv[1], sb.st_gid);
	printf("blksize_t(%s) is %ld blksize\n", argv[1], sb.st_blksize);
	printf("blkcnt_t(%s) is %ld blkcnt\n", argv[1], sb.st_blocks);
	printf("time_t(%s) is %ld atime\n", argv[1], sb.st_atime);
	printf("time_t(%s) is %ld ctime\n", argv[1], sb.st_ctime);
	printf("time_t(%s) is %ld mtime\n", argv[1], sb.st_mtime);
	return 0;
}

