#include "../libasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PRINTF(...) dont_print_logs ? printf(__VA_ARGS__) : 0 == 0

#define TESTS_STRLEN 6
#define TESTS_STRCPY 5
#define TESTS_STRCMP 6
#define TESTS_WRITE 6
#define TESTS_READ 6
#define TESTS_STRDUP 4

int dont_print_logs = 1;

int tests_strlen();
int tests_strcpy();
int tests_strcmp();
int tests_write();
int tests_read();
int tests_strdup();

int main(int argc, char **argv) {
	if (argc ==  2 && strncmp("unit", argv[1], 4) == 0) {
		dont_print_logs = 0;
	}

	if (tests_strlen()) {
		printf("Result strlen\t\t[\033[32m✓\033[0m]\n");
	} else {
		printf("Result strlen\t\t[\033[31m✗\033[0m]\n");
	}

	if (tests_strcpy()) {
		printf("Result strcpy\t\t[\033[32m✓\033[0m]\n");
	} else {
		printf("Result strcpy\t\t[\033[31m✗\033[0m]\n");
	}

	if (tests_strcmp()) {
		printf("Result strcmp\t\t[\033[32m✓\033[0m]\n");
	} else {
		printf("Result strcmp\t\t[\033[31m✗\033[0m]\n");
	}

	if (tests_write()) {
		printf("Result write\t\t[\033[32m✓\033[0m]\n");
	} else {
		printf("Result write\t\t[\033[31m✗\033[0m]\n");
	}

	if (tests_read()) {
		printf("Result read\t\t[\033[32m✓\033[0m]\n");
	} else {
		printf("Result read\t\t[\033[31m✗\033[0m]\n");
	}

	if (tests_strdup()) {
		printf("Result strdup\t\t[\033[32m✓\033[0m]\n");
	} else {
		printf("Result strdup\t\t[\033[31m✗\033[0m]\n");
	}
}

int tests_strlen() {
	char *s1 = "Salut tout le monde";
	char *s2 = "a";
	char *s3 = "";
	char *s4 = "Truc\0yaya";
	char *s5 = "aaaaaaaaaaab\1\2";
	char *s6 = malloc(600000);
	long int result_vrai = 0;
	long int result_mine = 0;
	int equals = 0;

	bzero(s6, 600000);
	memset(s6, '*', 599999);

	PRINTF("\033[1;3;32m--- Tests strlen ---\n\n\033[0m");

	result_vrai = strlen(s1);
	result_mine = ft_strlen(s1);

	if (result_mine == result_vrai) {
		equals++;
	}

	PRINTF("%s:\nstrlen:\t\t%ld\nft_strlen:\t%ld\n\n",
			s1, result_vrai, result_mine);

	result_vrai = strlen(s2);
	result_mine = ft_strlen(s2);

	if (result_mine == result_vrai) {
		equals++;
	}

	PRINTF("%s:\nstrlen:\t\t%ld\nft_strlen:\t%ld\n\n",
			s2, result_vrai, result_mine);

	result_vrai = strlen(s3);
	result_mine = ft_strlen(s3);

	if (result_mine == result_vrai) {
		equals++;
	}

	PRINTF("%s:\nstrlen:\t\t%ld\nft_strlen:\t%ld\n\n",
			s3, result_vrai, result_mine);
	
	result_vrai = strlen(s4);
	result_mine = ft_strlen(s4);

	if (result_mine == result_vrai) {
		equals++;
	}

	PRINTF("%s:\nstrlen:\t\t%ld\nft_strlen:\t%ld\n\n",
			s4, result_vrai, result_mine);
	
	result_vrai = strlen(s5);
	result_mine = ft_strlen(s5);

	if (result_mine == result_vrai) {
		equals++;
	}

	PRINTF("%s:\nstrlen:\t\t%ld\nft_strlen:\t%ld\n\n",
			s5, result_vrai, result_mine);

	result_vrai = strlen(s6);
	result_mine = ft_strlen(s6);

	if (result_mine == result_vrai) {
		equals++;
	}

	PRINTF("600 000 '*':\nstrlen:\t\t%ld\nft_strlen:\t%ld\n\n",
			result_vrai, result_mine);

	free(s6);

	return (equals == TESTS_STRLEN);
}

int tests_strcpy() {
	char basis[100] = "salut tout le monde";
	char vrai[100];
	char mine[100];
	int equals = 0;

	PRINTF("\033[1;3;32m--- Tests strcpy ---\n\n\033[0m");

	bzero(vrai, 100);
	bzero(mine, 100);

	strcpy(vrai, basis);
	strcpy(mine, basis);

	if (!strcmp(vrai, mine)) {
		equals++;
	}

	PRINTF("strcpy:\t\t%s\nft_strlen:\t%s\n\n", vrai, mine);

	bzero(basis, 100);

	bzero(vrai, 100);
	bzero(mine, 100);
	strcpy(vrai, basis);
	strcpy(mine, basis);

	if (!strcmp(vrai, mine)) {
		equals++;
	}

	PRINTF("strcpy:\t\t%s\nft_strlen:\t%s\n\n", vrai, mine);

	strcpy(basis, "Truc de ouf bla bla bla");

	strcpy(vrai, basis);
	strcpy(mine, basis);

	if (!strcmp(vrai, mine)) {
		equals++;
	}

	PRINTF("strcpy:\t\t%s\nft_strlen:\t%s\n\n", vrai, mine);

	strcpy(basis, "J'adore l'assambleur");

	strcpy(vrai, basis);
	strcpy(mine, basis);

	if (!strcmp(vrai, mine)) {
		equals++;
	}

	PRINTF("strcpy:\t\t%s\nft_strlen:\t%s\n\n", vrai, mine);

	strcpy(basis, "xor rax, rax");

	strcpy(vrai, basis);
	strcpy(mine, basis);

	if (!strcmp(vrai, mine)) {
		equals++;
	}

	PRINTF("strcpy:\t\t%s\nft_strlen:\t%s\n", vrai, mine);

	return (equals == TESTS_STRCPY);
}

int tests_strcmp() {
	char s1[100] = "salut";
	char s2[100] = "salut";
	int vrai, mine;
	int equals = 0;

	PRINTF("\033[1;3;32m--- Tests strcmp ---\n\n\033[0m");

	vrai = strcmp(s1, s2);
	mine = ft_strcmp(s1, s2);

	equals += vrai == mine;

	PRINTF("[%s | %s]\nstrcmp:\t\t%d\nft_strcmp:\t%d\n\n", s1, s2, vrai, mine);

	strcpy(s1, "saaaaa");

	vrai = strcmp(s1, s2);
	mine = ft_strcmp(s1, s2);

	equals += vrai == mine;

	PRINTF("[%s | %s]\nstrcmp:\t\t%d\nft_strcmp:\t%d\n\n", s1, s2, vrai, mine);

	strcpy(s1, "");

	vrai = strcmp(s1, s2);
	mine = ft_strcmp(s1, s2);

	equals += vrai == mine;

	PRINTF("[%s | %s]\nstrcmp:\t\t%d\nft_strcmp:\t%d\n\n", s1, s2, vrai, mine);

	strcpy(s2, "");

	vrai = strcmp(s1, s2);
	mine = ft_strcmp(s1, s2);

	equals += vrai == mine;

	PRINTF("[%s | %s]\nstrcmp:\t\t%d\nft_strcmp:\t%d\n\n", s1, s2, vrai, mine);

	strcpy(s2, "");
	strcpy(s1, "salut");

	vrai = strcmp(s1, s2);
	mine = ft_strcmp(s1, s2);

	equals += vrai == mine;

	PRINTF("[%s | %s]\nstrcmp:\t\t%d\nft_strcmp:\t%d\n\n", s1, s2, vrai, mine);

	strcpy(s2, "saaaaaa");
	strcpy(s1, "salut");

	vrai = strcmp(s1, s2);
	mine = ft_strcmp(s1, s2);

	equals += vrai == mine;

	PRINTF("[%s | %s]\nstrcmp:\t\t%d\nft_strcmp:\t%d\n", s1, s2, vrai, mine);
	return (equals == TESTS_STRCMP);
}

int tests_write() {
	char str[10] = "salut\0\0\0\0";
	int vrai, mine;
	int equals = 0;

	PRINTF("\033[1;3;32m--- Tests write ---\033[0m\n\n");

	vrai = write(2, str, 5);
	PRINTF("\t%d\n", vrai);
	mine = ft_write(2, str, 5);
	PRINTF("\t%d\n\n", mine);

	equals += vrai == mine;

	vrai = write(2, str, 10);
	PRINTF("\t%d\n", vrai);
	mine = ft_write(2, str, 10);
	PRINTF("\t%d\n\n", mine);

	equals += vrai == mine;

	vrai = write(2, str, 0);
	PRINTF("\t%d\n", vrai);
	mine = ft_write(2, str, 0);
	PRINTF("\t%d\n\n", mine);

	equals += vrai == mine;

	bzero(str, 10);

	vrai = write(2, str, 7);
	PRINTF("\t%d\n", vrai);
	mine = ft_write(2, str, 7);
	PRINTF("\t%d\n\n", mine);

	equals += vrai == mine;

	strcpy(str, "bonjour");

	vrai = write(0, str, 7);
	PRINTF("\t%d\n", vrai);
	mine = ft_write(0, str, 7);
	PRINTF("\t%d\n\n", mine);

	equals += vrai == mine;

	vrai = write(7, str, 7);
	PRINTF("\t%d errno: %d\n", vrai, errno);
	mine = ft_write(7, str, 7);
	PRINTF("\t%d errno: %d\n\n", mine, errno);

	equals += vrai == mine;

	return (equals == TESTS_WRITE);
}

int tests_read() {
	int equals = 0;
	char vrai[100];
	char mine[100];
	int	vrai_ret, mine_ret;
	int fd_vrai = open("tests/vrai.txt", O_RDONLY);
	int fd_mine = open("tests/mine.txt", O_RDONLY);

	bzero(vrai, 100);
	bzero(mine, 100);

	PRINTF("\033[1;3;32m--- Tests read ---\033[0m\n\n");

	vrai_ret = read(fd_vrai, vrai, 4);
	mine_ret = read(fd_mine, mine, 4);

	equals += (vrai_ret == mine_ret && !strcmp(vrai, mine));

	PRINTF("%s\t%d\n%s\t%d\n\n", vrai, vrai_ret, mine, mine_ret);

	bzero(vrai, 100);
	bzero(mine, 100);
	vrai_ret = read(fd_vrai, vrai, 66);
	mine_ret = read(fd_mine, mine, 66);

	equals += (vrai_ret == mine_ret && !strcmp(vrai, mine));

	PRINTF("%s\t%d\n%s\t%d\n\n", vrai, vrai_ret, mine, mine_ret);

	bzero(vrai, 100);
	bzero(mine, 100);
	vrai_ret = read(fd_vrai, vrai, 5);
	mine_ret = read(fd_mine, mine, 5);

	equals += (vrai_ret == mine_ret && !strcmp(vrai, mine));

	PRINTF("%s\t%d\n%s\t%d\n\n", vrai, vrai_ret, mine, mine_ret);

	bzero(vrai, 100);
	bzero(mine, 100);
	vrai_ret = read(fd_vrai, vrai, 42);
	mine_ret = read(fd_mine, mine, 42);

	equals += (vrai_ret == mine_ret && !strcmp(vrai, mine));

	PRINTF("%s\t%d\n%s\t%d\n\n", vrai, vrai_ret, mine, mine_ret);

	bzero(vrai, 100);
	bzero(mine, 100);
	vrai_ret = read(fd_vrai, vrai, 42);
	mine_ret = read(fd_mine, mine, 42);

	equals += (vrai_ret == mine_ret && !strcmp(vrai, mine));

	PRINTF("%s\t%d\n%s\t%d\n\n", vrai, vrai_ret, mine, mine_ret);

	bzero(vrai, 100);
	bzero(mine, 100);
	vrai_ret = read(42, vrai, 42);
	int vrai_errno = errno;
	mine_ret = read(42, mine, 42);
	int mine_errno = errno;

	equals += (vrai_ret == mine_ret && (vrai_errno == mine_errno));

	PRINTF("%d errno: %d\n%d errno: %d\n\n", vrai_ret, vrai_errno, mine_ret, mine_errno);

	close(fd_mine);
	close(fd_vrai);

	return (equals == TESTS_READ);
}

int tests_strdup() {
	char *vrai, *mine;
	char str[100] = "Salut";
	int equals = 0;

	PRINTF("\033[1;3;32m--- Tests strdup ---\033[0m\n\n");


	vrai = strdup(str);
	mine = ft_strdup(str);

	equals = !strcmp(vrai, mine);

	PRINTF("%s\n%s", vrai, mine);

	return (equals == TESTS_STRDUP);
}
