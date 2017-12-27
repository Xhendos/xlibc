#ifndef _MEMORY_H
#define	_MEMORY_H

/* Function prototyping */
void _meminit(void);		/* Initialise the first struct memblk */

void _memdump(void);		/* Dump all struct memblk that exist */

void _free(void *ptr);		/* Release the allocated memory */

void *_mallocb(size_t size);	/* Allocate size bytes using the best-fit algorhitm */

#endif				/* _MEMORY_H */
