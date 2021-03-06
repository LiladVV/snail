apue/lib.svr4/senderr.c                                                                                664     340      24          744  5211773730  14472  1apue/lib.sun/senderr.c                                                                                                                                                                                                                                                                                                                                             apue/lib.svr4/sendfd.c                                                                                 644     340      24         1201  5211773763  10113                                                                                                                                                                                                                                                                                                                                                                      #include	<sys/types.h>
#include	<stropts.h>
#include	"ourhdr.h"

/* Pass a file descriptor to another process.
 * If fd<0, then -fd is sent back instead as the error status. */

int
send_fd(int clifd, int fd)
{
	char	buf[2];		/* send_fd()/recv_fd() 2-byte protocol */

	buf[0] = 0;			/* null byte flag to recv_fd() */
	if (fd < 0) {
		buf[1] = -fd;	/* nonzero status means error */
		if (buf[1] == 0)
			buf[1] = 1;	/* -256, etc. would screw up protocol */
	} else {
		buf[1] = 0;		/* zero status means OK */
	}

	if (write(clifd, buf, 2) != 2)
		return(-1);

	if (fd >= 0)
		if (ioctl(clifd, I_SENDFD, fd) < 0)
			return(-1);
	return(0);
}
ror");
		nread = dat.len;
		if (nread == 0) {
			err_ret("connection closed by server");
			return(-1);
		}
			/* See if this is the final data with null & status.
			   Null must be next to last byte of buffer, status
			   byte is last byte.  Zero status means there must
			   be a file descriptor to receive. */
		for (ptr = buf; ptr < &buf[nread]; ) {
			if (*ptr++ == 0) {
				apue/lib.svr4/servaccept.c                                                                             664     340      24         1032  5211773764  11014                                                                                                                                                                                                                                                                                                                                                                      #include	<sys/types.h>
#include	<sys/stat.h>
#include	<stropts.h>
#include	"ourhdr.h"

/* Wait for a client connection to arrive, and accept it.
 * We also obtain the client's user ID. */

int			/* returns new fd if all OK, -1 on error */
serv_accept(int listenfd, uid_t *uidptr)
{
	struct strrecvfd	recvfd;

	if (ioctl(listenfd, I_RECVFD, &recvfd) < 0)
		return(-1);		/* could be EINTR if signal caught */

	if (uidptr != NULL)
		*uidptr = recvfd.uid;	/* effective uid of caller */

	return(recvfd.fd);	/* return the new descriptor */
}
 != 2)
		return(-1);

	if (fd >= 0)
		if (ioctl(clifd, I_SENDFD, fd) < 0)
			return(-1);
	return(0);
}
ror");
		nread = dat.len;
		if (nread == 0) {
			err_ret("connection closed by server");
			return(-1);
		}
			/* See if this is the final data with null & status.
			   Null must be next to last byte of buffer, status
			   byte is last byte.  Zero status means there must
			   be a file descriptor to receive. */
		for (ptr = buf; ptr < &buf[nread]; ) {
			if (*ptr++ == 0) {
				apue/lib.svr4/servlisten.c                                                                             664     340      24         1310  5211773764  11052                                                                                                                                                                                                                                                                                                                                                                      #include	<sys/types.h>
#include	<sys/stat.h>
#include	<stropts.h>
#include	"ourhdr.h"

#define	FIFO_MODE  (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
					/* user rw, group rw, others rw */

int			/* returns fd if all OK, <0 on error */
serv_listen(const char *name)
{
	int		tempfd, fd[2], len;

					/* create a file: mount point for fattach() */
	unlink(name);
	if ( (tempfd = creat(name, FIFO_MODE)) < 0)
		return(-1);
	if (close(tempfd) < 0)
		return(-2);

	if (pipe(fd) < 0)
		return(-3);
							/* push connld & fattach() on fd[1] */
	if (ioctl(fd[1], I_PUSH, "connld") < 0)
		return(-4);
	if (fattach(fd[1], name) < 0)
		return(-5);

	return(fd[0]);	/* fd[0] is where client connections arrive */
}
osed by server");
			return(-1);
		}
			/* See if this is the final data with null & status.
			   Null must be next to last byte of buffer, status
			   byte is last byte.  Zero status means there must
			   be a file descriptor to receive. */
		for (ptr = buf; ptr < &buf[nread]; ) {
			if (*ptr++ == 0) {
				apue/lib.svr4/setfl.c                                                                                  664     340      24          471  5211773731  13616  1apue/lib.sun/setfl.c                                                                                                                                                                                                                                                                                                                                               apue/lib.svr4/signal.c                                                                                 664     340      24         1010  5211773732  14125  1apue/lib.sun/signal.c                                                                                                                                                                                                                                                                                                                                              apue/lib.svr4/signalintr.c                                                                             664     340      24          535  5211773732  15712  1apue/lib.sun/signalintr.c                                                                                                                                                                                                                                                                                                                                          apue/lib.svr4/sleep.c                                                                                  664     340      24         2056  5211773733  13627  1apue/lib.sun/sleep.c                                                                                                                                                                                                                                                                                                                                               apue/lib.svr4/spipe.c                                                                                  664     340      24          171  5211773766   7762                                                                                                                                                                                                                                                                                                                                                                      #include	"ourhdr.h"

int
s_pipe(int fd[2]) /* two file descriptors returned in fd[0] & fd[1] */
{
	return( pipe(fd) );
}
c L  `   ?  
ttymodes.c `  t    prmask.c  t  ?   ?  writen.c  ?  ?   ?  spipe.socket.c ?  ?   ?  daemoninit.c   ?  ?  ?  	ptyopen.c ?  ?    	ptyfork.c ?     ?  	sleepus.c    ?  	sleepus.c k.c ?     ?  	sleepus.c ?     ?  	sleepus.c    ?  	sleepus.c k.return(-1);
	if (close(tempfd) < 0)
		return(-2);

	if (pipe(fd) < 0)
		return(-3);
							/* puapue/lib.svr4/strerror.c                                                                               644     340      24          376  5211773566  15140  1apue/lib.sun/strerror.c      