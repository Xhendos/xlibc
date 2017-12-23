#ifndef	_SIGNAL_X_H
#define	_SIGNAL_X_H

/* Regular signals (from Minix3.1.8) 
 * command "kill -l" can be used to view some of the signals */
#define _SIGHUP       	1	/* hangup */
#define _SIGINT      	2	/* interrupt (DEL) */
#define _SIGQUIT      	3	/* quit (ASCII FS) */
#define _SIGILL       	4	/* illegal instruction */
#define _SIGTRAP     	5	/* trace trap (not reset when caught) */
#define _SIGABRT      	6	/* IOT instruction */
#define _SIGBUS       	7	/* bus error */
#define _SIGFPE       	8	/* floating point exception */
#define _SIGKILL      	9	/* kill (cannot be caught or ignored) */
#define _SIGUSR1      	10	/* user defined signal # 1 */
#define _SIGSEGV      	11	/* segmentation violation */
#define _SIGUSR2       	12	/* user defined signal # 2 */
#define _SIGPIPE     	13	/* write on a pipe with no one to read it */
#define _SIGALRM     	14	/* alarm clock */
#define _SIGTERM     	15	/* software termination signal from kill */
#define _SIGEMT		16	/* EMT instruction */
#define _SIGCHLD      	17	/* child process terminated or stopped */
#define _SIGWINCH   	21	/* window size has changed */
#define _SIGVTALRM    	24	/* virtual alarm */
#define _SIGPROF	25	/* profiler alarm */



#endif	/* _SIGNAL_X_H */
