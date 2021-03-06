apue/datafiles/getpw44bsd.c                                                                            664     340      24          501  5211773660  11110                                                                                                                                                                                                                                                                                                                                                                      #include	<sys/types.h>
#include	<pwd.h>
#include	"ourhdr.h"

int
main(void)		/* 44BSD version */
{
	struct passwd	*ptr;

	if ( (ptr = getpwnam("stevens")) == NULL)
		err_sys("getpwnam error");

	printf("pw_passwd = %s\n",
				ptr->pw_passwd == NULL || ptr->pw_passwd[0] == 0 ?
				"(null)" : ptr->pw_passwd);
	exit(0);
}
pend D  ?  !  printer   ?    proc tyo  ?  5  pty   ?    sess        :  signals     !  stdio gc     M  streams   0  &  termios      R  test   ot a ttyapue/datafiles/getpwnam.c                                                                              664     340      24          564  5211773661  10755                                                                                                                                                                                                                                                                                                                                                                      #include <sys/types.h>
#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd *
getpwnam(const char *name)
{
    struct passwd  *ptr;

    setpwent();
    while ( (ptr = getpwent()) != NULL) {
        if (strcmp(name, ptr->pw_name) == 0)
            break;		/* found a match */
    }
    endpwent();
    return(ptr);	/* ptr is NULL if no match found */
}
  5  pty   ?    sess        :  signals     !  stdio gc     M  streams   0  &  termios      R  test   ot a ttyapue/datafiles/getpwsvr4.c                                                                             664     340      24          471  5211773661  11075                                                                                                                                                                                                                                                                                                                                                                      #include	<sys/types.h>
#include	<shadow.h>
#include	"ourhdr.h"

int
main(void)		/* SVR4 version */
{
	struct spwd	*ptr;

	if ( (ptr = getspnam("stevens")) == NULL)
		err_sys("getspnam error");

	printf("sp_pwdp = %s\n",
				ptr->sp_pwdp == NULL || ptr->sp_pwdp[0] == 0 ?
				"(null)" : ptr->sp_pwdp);
	exit(0);
}
();
    return(ptr);	/* ptr is NULL if no match found */
}
  5  pty   ?    sess        :  signals     !  stdio gc     M  streams   0  &  termios      R  test   ot a ttyapue/datafiles/prtime.c                                                                                664     340      24          565  5211773662  10435                                                                                                                                                                                                                                                                                                                                                                      #include	<time.h>
#include	"ourhdr.h"

int
main(void)
{
	time_t		caltime;
	struct tm	*tm;
	char		line[MAXLINE];

	if ( (caltime = time(NULL)) == -1)
		err_sys("time error");
	if ( (tm = localtime(&caltime)) == NULL)
		err_sys("localtime error");

	if (strftime(line, MAXLINE, "%a %b %d %X %Z %Y\n", tm) == 0)
		err_sys("strftime error");
	fputs(line, stdout);

	exit(0);
}
 5  pty   ?    sess        :  signals     !  stdio gc     M  streams   0  &  termios      R  test   ot a ttyapue/db.loc