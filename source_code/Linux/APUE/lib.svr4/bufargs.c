apue/lib.svr4/cliconn.c                                                                                664     340      24          560  5211773754  10266                                                                                                                                                                                                                                                                                                                                                                      #include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"ourhdr.h"

/* Create a client endpoint and connect to a server. */

int			/* returns fd if all OK, <0 on error */
cli_conn(const char *name)
{
	int		fd;

				/* open the mounted stream */
	if ( (fd = open(name, O_RDWR)) < 0)
		return(-1);
	if (isastream(fd) == 0)
		return(-2);

	return(fd);
}
ph.c    p   ?  	senderr.c    ?  ?  sendfd.c  cv  ?  ?  servaccept.c  ?  ?  ?  servlisten.c  ?  ?   ?  setfl.c   ?   ?  apue/lib.svr4/clrfl.c                                            