apue/printer/acctfile                                                                                  664     340      24           27  5211773612  10161                                                                                                                                                                                                                                                                                                                                                                         1.00 kohala:stevens
  ;?GS =  `  2  acctfile  8  t  3  	mbox.errs L     4  	pageno.ps `     4  	pageno.ps t.o \
		pagecount.o sendfile.o tty.o vars.o
DIR = /usr/local/lib

all:	${PROGS}

lprps:	${OBJS}
		${LINK.c} -o $@ ${OBJS} ${LDLIBS}

psif:	psif.o
		${LINK.c} -o $@ psif.o ${LDLIBS}

install:lprps
		mv lprps ${DIR}/lprps

clean:
	rm -f ${PROGS} ${TEMPFILES}
ne_intro == 0) {
			fputs("Your PostScript printer job "
				  "produced the following output:\n", mailfp);
			done_intro = 1;
	apue/printer/mbox.errs                                                                                 600     340      24         3664  5211773612  10366                                                                                                                                                                                                                                                                                                                                                                      From stevens Thu Nov 21 05:26:22 1991
Return-Path: <stevens>
Received: by kohala.noname (4.1/SMI-4.1)
	id AA03626; Thu, 21 Nov 91 05:26:22 MST
Date: Thu, 21 Nov 91 05:26:22 MST
From: stevens (Richard Stevens)
Message-Id: <9111211226.AA03626@kohala.noname>
To: stevens@kohala
Subject: printer job
Status: O

Your PostScript printer job produced the error `undefined'.
The offending command was `#include'.

From stevens Thu Nov 21 05:29:29 1991
Return-Path: <stevens>
Received: by kohala.noname (4.1/SMI-4.1)
	id AA03646; Thu, 21 Nov 91 05:29:28 MST
Date: Thu, 21 Nov 91 05:29:28 MST
From: stevens (Richard Stevens)
Message-Id: <9111211229.AA03646@kohala.noname>
To: stevens@kohala
Subject: printer job
Status: O

Your PostScript printer job produced the error `undefined'.
The offending command was `sssetfont'.

From stevens Thu Nov 21 05:30:13 1991
Return-Path: <stevens>
Received: by kohala.noname (4.1/SMI-4.1)
	id AA03657; Thu, 21 Nov 91 05:30:12 MST
Date: Thu, 21 Nov 91 05:30:12 MST
From: stevens (Richard Stevens)
Message-Id: <9111211230.AA03657@kohala.noname>
To: stevens@kohala
Subject: printer job
Status: OR

Your PostScript printer job produced the error `stackunderflow'.
The offending command was `pop'.

From stevens Thu Nov 21 05:34:19 1991
Return-Path: <stevens>
Received: by kohala.noname (4.1/SMI-4.1)
	id AA03668; Thu, 21 Nov 91 05:34:18 MST
Date: Thu, 21 Nov 91 05:34:18 MST
From: stevens (Richard Stevens)
Message-Id: <9111211234.AA03668@kohala.noname>
To: stevens@kohala
Subject: printer job
Status: OR

Your PostScript printer job produced the following output:
hello, world

From stevens Thu Nov 21 05:38:19 1991
Return-Path: <stevens>
Received: by kohala.noname (4.1/SMI-4.1)
	id AA03696; Thu, 21 Nov 91 05:38:19 MST
Date: Thu, 21 Nov 91 05:38:19 MST
From: stevens (Richard Stevens)
Message-Id: <9111211238.AA03696@kohala.noname>
To: stevens@kohala
Subject: printer job
Status: OR

Your PostScript printer job produced the following output:
^C

ck_write(const char *, int);	/* tty.c */
void	tty_flush(void);
void	set_blocapue/printer/pageno.ps                                                                                 664     340      24           44  5211773612  10300                                                                                                                                                                                                                                                                                                                                                                      %!
statusdi