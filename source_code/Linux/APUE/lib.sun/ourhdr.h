apue/lib.sun/prexit.c                                                                                  664     340      24          766  5211773725  10071                                                                                                                                                                                                                                                                                                                                                                      #include	<sys/types.h>
#include	<sys/wait.h>
#include	"ourhdr.h"

void
pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("normal termination, exit status = %d\n",
				WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n",
				WTERMSIG(status),
#ifdef	WCOREDUMP
				WCOREDUMP(status) ? " (core file generated)" : "");
#else
				"");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n",
				WSTOPSIG(status));
}
ble itselfapue/lib.sun/spipe.c                                                                                   664     340      24          307  5211773734   7665                                                                                                                                                                                                                                                                                                                                                                      #include	<sys/types.h>
#include	<sys/socket.h>
#include	"ourhdr.h"

int
s_pipe(int fd[2]) /* two file descriptors returned in fd[0] & fd[1] */
{
	return( socketpair(AF_UNIX, SOCK_STREAM, 0, fd) );
}
.c T  |   ?  	senderr.c  ?  ?   ?  sendfd.c  h  ?   ?  servaccept.c  ?  ?   ?  servlisten.c  ?  ?   ?  	cliconn.c ?  ?     recvfd.c   ?  ?    popen.c       prmask.c .c        	ptyfork.c c ts to head of LIFO stack */
to be performed at exit.
 */
int
atexit(fn)
	void (*fn)();
{apue/lib.sun/clrfl.c                                                                                   664     340      24          504  5211773570   7644                                                                                                                                                                                                                                                                                                                                                                      #include	<fcntl.h>
#include	"ourhdr.h"

void
clr_fl(int fd, int flags)
				/* flags are the file status flags to turn off */
{
	int		val;

	if ( (val = fcntl(fd, F_GETFL, 0)) < 0)
		err_sys("fcntl F_GETFL error");

	val &= ~flags;		/* turn flags off */

	if (fcntl(fd, F_SETFL, val) < 0)
		err_sys("fcntl F_SETFL error");
}
recvfd.c  ?  ?    popen.c       prmask.c         	ptyfork.c  it __atexit0;	/* one guaranteed table */
	register struct atexit *p;

	if ((p = __atexit) == 0)
		__atexit =apue/lib.sun/sleep.c                                                                                   664     340      24         2056  5211773733   7677                                                                                                                                                                                                                                                                                                                                                                      #include	<signal.h>
#include	<stddef.h>
#include	"ourhdr.h"

static void
sig_alrm(void)
{
	return;	/* nothing to do, just returning wakes up sigsuspend() */
}

unsigned int
sleep(unsigned int nsecs)
{
	struct sigaction	newact, oldact;
	sigset_t			newmask, oldmask, suspmask;
	unsigned int		unslept;

	newact.sa_handler = sig_alrm;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGALRM, &newact, &oldact);
					/* set our handler, save previous information */

	sigemptyset(&newmask);
	sigaddset(&newmask, 