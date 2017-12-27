#include <stdio.h>					/* Used for NULL
							 * Used for size_t 
							 * Contains the declaration printf() */
							
#define MEM_SIZE	10240				/* Total memory block of the heap (10 Kb) */				

char block[MEM_SIZE];					/* Memory block that represents the heap */

struct memblk
{
	int used;					/* [0 chunk is not used] [1 chunk is used] */
	int size;					/* Size of the chunk */
	struct memblk *next;				/* Pointer to the next chunk */
	void *data;					/* Pointer to char block[] where a caller write/read */
};

struct memblk *get_blockb(int size)
{
	struct memblk *block0;				/* Pointer to the first and only known struct memblk */
	struct memblk *free;				/* The new entry in the singly linked list (if needed) */
	int surplus;					/* The extra bytes that that our memory block got (memory - size) */
	
	block0 = (struct memblk *)&block;
	free = NULL;					/* free is by default NULL. This could be used for error checking */
	surplus = MEM_SIZE;				/* Our allocation has the most memory by default 
							 * This is only used if we want to allocate memory from a free'd space */

	if(block0->next != NULL)			/* A second entry exist and block0->next is pointing to it. Loop through all entries */
	{
							/* If the first entry (block0) got already a pointer */
							/* We could have 3 different sitations 
		 					 * 1) The next memblk is not used AND is big enough
		 					 * 2) The next memblk is not used, but the size is not enough
		 					 * 3) The next memblk is used */
		while(block0->next != NULL)		/* Sitation 1 or 2. We do not know at this point */ 
		{
			if(!block0->used &&		/* Sitation 1. We found a free block! */
			   block0->size >= size &&
			   block0->size <= surplus)
			{
				free = block0;		/* Point to the structure of the free block */
			}

			block0 = block0->next;		/* The size was not big enough or was not free, let's try the next memblk */
		}
		
	} 
	else if(block0->next == NULL)			/* If block0 (first entry) has no next pointer */
	{
		free = (struct memblk *) (sizeof(struct memblk) + (char *) block0);
		block0->next = free;			
	} 
	
	if(free == NULL)				/* If the first entry is pointing to another entry
							 * and there are no free entries available (everything is used or not big enough) */
	{
		free = (struct memblk *) (sizeof(struct memblk) + (char *) block0 + block0->size);
		block0->next = free;			/* Situation 3. All memory blocks are being used. Let's create a new one */
	}

	return free;
}

/*
 * |------------|----------|--------|
 * |	seg 1	| seg 2	   | seg 3  |
 * |	next	|	   |        |
 * |------------|----------|--------|
 *	|		       ^
 *	_______________________|
 *
 * Imagine seg 1 and seg 2 are free (not used), but seg 3 is being used
 * The method that merge_blocks() is doing is the next one (if 2 segments that sit next to eachother are free):
 * - Seg1 should nog point to seg 2, but to seg 3 (skip seg2)
 * - Seg1 it's size is the chrrent size + seg2 (struct memblk AND the size reserved for the user)
 *
 * This return of seg1 if it is allocated causes the 'garbage data' by allocation.
 */
void merge_blocks()
{
	struct memblk *blockx;
	struct memblk *prev;

	blockx = (struct memblk *)&block;		/* Point to the first (and only known) struct memblk */
	prev = (struct memblk *)&block;			/* Point to the first (and only known) struct memblk */	

	while(blockx->next != NULL)
	{
		if(!blockx->used && !prev->used)	/* If the current block AND the previous block are not used */
		{
			prev->size += blockx->size +	/* Add the memory block size to the previous one */
				      sizeof(struct memblk);
			prev->next = blockx->next;	/* Point to the next entry as where the current pointer would point to (as next) */
		}

		prev = blockx;
		blockx = blockx->next;
	}	
}


void _meminit(void)
{
	struct memblk *block0;				/* Create a first struct memblk (first entry singly linked list) */
	block0 = (struct memblk *)&block;		/* The information of block0 is stored in the first bytes of block[] */

	block0->used = 1;				/* First block got a housekeeping entry */
	block0->size = 0;				/* Size that the caller wants to allocate */
	block0->next = NULL;				/* block0 is the (at the moment) the only struct memblk */
	block0->data = NULL;				/* block0 will not be used for holding user data */

	return;
}

/*
 *
 * |________|___________________|
 * |	    |			|
 * | struct |struct->data	|
 * |	    |			|
 * |	    |			|
 * |________|___________________|
 *
 * The housekeeping is done in the character array. The structure member 'data' points to the first address that comes AFTER the structure.
 * This mens that if we return a void pointer (which is the same address that struct->data points to) and the caller overwrites the struct,
 * The memory will be seen as corrupt. A core dump (segmentation fault) will be given.
 */

void *_mallocb(size_t size) {
	struct memblk *free;				/* A housekeeping entry for the singly linked list */
	
	free = get_blockb(size);				
	
	if(free == NULL) return NULL;			/* Memory allocation failed. Return NULL to the caller */

	free->used = 1;					/* This memory block is being used by now */
	free->size = size;				/* Set the allocated user allocated size (this does not include the struct) */
	free->data = ((char *)free) +			/* See the explanation above the function */ 
		     sizeof(struct memblk);
		
	return (void *) free->data;			/* Return a void pointer to the caller (This is the first mem location after the struct */
}

void _free(void *ptr)
{
	ptr = ((char *)ptr) - 
		 sizeof(struct memblk);
	((struct memblk *) ptr)->used = 0;		/* The memory block will now be seen as free (data is still present at this moment) */
	merge_blocks();					/* Each time we free a memory block, we try to see if we can merge free blocks */
}

void _memdump(void)
{
	struct memblk *blk;				/* Temporarry to gather information about the existing stuct blks */	
	
	blk = (struct memblk *)&block;			/* Point to the first (and only known) struct memblk */

	for( ; blk != NULL; )				/* While we are not pointing to 0x00 print the struct information */
	{
		printf("Block of \t %d bytes: %s", blk->size, (!blk->used) ? "free   " : "in use");
		printf("\t (address is %p)\n", blk);
		blk = blk->next;			/* Go to the next struct memblk, even if it is NULL */
	}	
}
