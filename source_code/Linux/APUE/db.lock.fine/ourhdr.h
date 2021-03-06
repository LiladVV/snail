apue/db.lock.fine/alloc.c                                                                              664     340      24         1416  5211773662  10543                                                                                                                                                                                                                                                                                                                                                                      #include	"db.h"

/* Allocate & initialize a DB structure, and all the buffers it needs  */

DB *
_db_alloc(int namelen)
{
	DB		*db;

			/* Use calloc, to init structure to zero */
	if ( (db = calloc(1, sizeof(DB))) == NULL)
		err_dump("calloc error for DB");

	db->idxfd = db->datfd = -1;				/* descriptors */

		/* Allocate room for the name.
		   +5 for ".idx" or ".dat" plus null at end. */

	if ( (db->name = malloc(namelen + 5)) == NULL)
		err_dump("malloc error for name");

		/* Allocate an index buffer and a data buffer.
		   +2 for newline and null at end. */

	if ( (db->idxbuf = malloc(IDXLEN_MAX + 2)) == NULL)
		err_dump("malloc error for index buffer");
	if ( (db->datbuf = malloc(DATLEN_MAX + 2)) == NULL)
		err_dump("malloc error for data buffer");

	return(db);
}
term.c_cflag = CS7 | PARENB | PARODD;
	else
		log_quit("unknown parity");
	term.c_cflag |= CREAD |			/* enable receiver */
					HUPCL;			/* lower modem lines on last close */
									/* 1 stop bit (since CSTOPB off) */
	if (modem == 0)
		terapue/db.lock.fine/checkfree.c                                                                          664     340      24         1604  5211773552  11365                                                                                                                                                                                                                                                                                                                                                                      #include	"db.h"

/* Check the consistency of the free list, and return a count of
   the number of records on the free list.
   This is an undocumented function and should be called when the
   db is not being updated. */

int
_db_checkfree(DB *db)
{
	off_t	offset, nextoffset, saveoffset;
	char	c, *ptr;
	int		count;

		/* Read the free list pointer */
	saveoffset = FREE_OFF;
	offset = _db_readptr(db, saveoffset);

		/* Loop through the free list */
	count = 0;
	while (offset != 0) {
		count++;
		nextoffset = _db_readidx(db, offset);

			/* make certain key is all blank */
		ptr = db->idxbuf;
		while ( (c = *ptr++) != 0)
			if (c != ' ')
				return(-1);	/* error */

			/* make certain data is all blank */
		ptr = _db_readdat(db);
		while ( (c = *ptr++) != 0)
			if (c != ' ')
				return(-1);	/* error */

		saveoffset = offset;
		offset = nextoffset;
	}
	return(count);		/* can be zero */
}
r */
					HUPCL;			/* lower modem lines on last close */
									/* 1 stop bit (since CSTOPB off) */
	if (modem == 0)
		terapue/db.lock.fine/close.c                                                                              664     340      24          142  5211773663  10532                                                                                                                                                                                                                                                                                                                                                                      #include	"db.h"

void
db_close(DB *db)
{
	_db_free(db);	/* closes fds, free buffers & struct */
}
 ?   ?  
dodelete.c ?   ?   ?  fetch.c    ?   ?  find.c c   ?   ?  
findfree.c     ?   ?  free.c e      ?  hash.c e     ?  	nextrec.c  e  $   ?  open.c .  8   ?  	readdat.c  ?  L   ?  	readidx.c 8  `   ?  	readptr.c L  t   ?  rewind.c  `  ?   ?  stats.c   ?   ?  store.c   ?   ?  t4.c tor  ?   ?  tstats.c .c   ?   ?  
writedat.c ?  ?   ?  
writeidx.c ?      ?  
writapue/db.loc