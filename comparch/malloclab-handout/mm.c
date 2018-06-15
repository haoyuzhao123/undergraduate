/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 *
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team =
{
    /* Team name */
    "zzzzzhy",
    /* First member's full name */
    "Haoyu Zhao",
    /* First member's email address */
    "zhaohy16@mails.tsinghua.edu.cn",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""
};

//macros copy form the book
#define WSIZE 4
#define DSIZE 8
#define CHUNKSIZE (1<<12) 

#define MAX(x,y)    ((x)>(y)?(x):(y))

#define PACK(size,alloc)    ((size) | (alloc))

#define GET(p)  (*(unsigned int *)(p))
#define PUT(p,val)  (*(unsigned int *)(p) = (val))

#define GET_SIZE(p)  (GET(p) & ~0x7)
#define GET_ALLOC(p)    (GET(p) & 0x1)

#define HDRP(bp)    ((char *)(bp)-WSIZE)
#define FTRP(bp)    ((char *)(bp)+GET_SIZE(HDRP(bp))-DSIZE)

#define NEXT_BLKP(bp)   ((char *)(bp)+GET_SIZE(((char *)(bp)-WSIZE)))
#define PREV_BLKP(bp)   ((char *)(bp)-GET_SIZE(((char *)(bp)-DSIZE)))

//macro for the linked list
#define PREV_PTR(bp) ((char*)(bp))
#define NEXT_PTR(bp) ((char*)(bp)+WSIZE)


static void *extend_heap(size_t dwords);
static void *coalesce(void *bp);
static void *find_fit(size_t size);
static void place(void *bp,size_t asize);

//global variable
static char *heap_listp = NULL;
static char *list_head = NULL;

//insert node and delete node helper function
void insert_node(char *bp) {
    char *next = GET(list_head);
    if(next != NULL) {
        PUT(PREV_PTR(next),bp);
    }
    PUT(NEXT_PTR(bp),next);
    PUT(list_head,bp);
}
void delete_node(char *bp) {
    char *prev = GET(PREV_PTR(bp));
    char *next = GET(NEXT_PTR(bp));
    if(prev == NULL) {
        if(next != NULL)PUT(PREV_PTR(next),0);
        PUT(list_head,next);
    } else {
        if(next != NULL)PUT(PREV_PTR(next),prev);
        PUT(NEXT_PTR(prev),next);
    }
    PUT(NEXT_PTR(bp),0);
    PUT(PREV_PTR(bp),0);
}

int mm_init(void) {
    if((heap_listp = mem_sbrk(6*WSIZE))==(void *)-1) return -1;

    PUT(heap_listp,0);
    //space for the list_head
    PUT(heap_listp+(1*WSIZE),0);
    PUT(heap_listp+(2*WSIZE),0);
    PUT(heap_listp+(3*WSIZE),PACK(DSIZE,1));
    PUT(heap_listp+(4*WSIZE),PACK(DSIZE,1));
    PUT(heap_listp+(5*WSIZE),PACK(0,1));
    list_head = heap_listp + (1*WSIZE);

    heap_listp += (4*WSIZE);

    return 0;
}

static void *extend_heap(size_t words)
{
    char *bp;
    size_t size;

    //should use DSIZE instead of WSIZE
    size = (words % 2) ? (words+1) * DSIZE : words * DSIZE;

    if((long)(bp = mem_sbrk(size))==(void *)-1) {
        return NULL;
    }

    PUT(HDRP(bp),PACK(size,0));
    PUT(FTRP(bp),PACK(size,0));
    PUT(NEXT_PTR(bp),0);
    PUT(PREV_PTR(bp),0);

    PUT(HDRP(NEXT_BLKP(bp)),PACK(0,1));

    return coalesce(bp);
}

void *mm_malloc(size_t size) {
    
    if (size > 64 && size < 128) {
        size = 128;
    }
    
    size_t asize;
    size_t extendsize;
    char *bp;
    if(size ==0) return NULL;

    if(size <= DSIZE) {
        asize = 2*(DSIZE);
    } else {
        asize = (DSIZE)*((size+(DSIZE)+(DSIZE-1)) / (DSIZE));
    }

    if((bp = find_fit(asize))!= NULL) {
        place(bp,asize);
        return bp;
    }

    extendsize = MAX(asize,CHUNKSIZE);
    if((bp = extend_heap(extendsize/DSIZE))==NULL) {
        return NULL;
    }
    place(bp,asize);
    return bp;
}

void mm_free(void *bp) {
    if(bp == 0) {
        return;
    }

    size_t size = GET_SIZE(HDRP(bp));

    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    //set the pointer
    PUT(NEXT_PTR(bp),0);
    PUT(PREV_PTR(bp),0);

    coalesce(bp);
}

void *mm_realloc(void *ptr, size_t size) {
    if (size > 64 && size < 128) {
        size = 128;
    }
    
    size_t asize;
    size_t csize;
    size_t oldsize;
    void *newptr;

    if(size == 0) {
        mm_free(ptr);
        return 0;
    }

    if(ptr == NULL) {
        return mm_malloc(size);
    }
    oldsize = GET_SIZE(HDRP(ptr));

    //if there is a free block next to the current block
    if (size <= DSIZE) {
        asize = 2*DSIZE;
    } else {
        asize = DSIZE * ((size + (DSIZE) + (DSIZE-1)) / DSIZE);
    }

    csize = (GET_SIZE(HDRP(ptr))) + (GET_SIZE(HDRP(NEXT_BLKP(ptr))));
    if ((!GET_ALLOC(HDRP(NEXT_BLKP(ptr)))) && (csize >= asize)) {
        delete_node(NEXT_BLKP(ptr));
        PUT(HDRP(ptr), PACK(csize, 0));
        PUT(FTRP(ptr), PACK(csize, 0));
        insert_node(ptr);
        place(ptr, asize);
        
        return ptr;
    }
    // end of this situation, use the original malloc.
    

    newptr = mm_malloc(size);

    if(!newptr) {
        return 0;
    }

    /* Copy the old data. */
    oldsize = GET_SIZE(HDRP(ptr));
    if(size < oldsize) oldsize = size;
    memcpy(newptr, ptr, oldsize);

    /* Free the old block. */
    mm_free(ptr);

    return newptr;
}

/*coalesce the empty block*/
static void *coalesce(void *bp) {
    size_t  prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
    size_t  next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
    size_t size = GET_SIZE(HDRP(bp));

    if(prev_alloc && next_alloc) {
    }
    else if(prev_alloc && !next_alloc) {
        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));

        delete_node(NEXT_BLKP(bp));

        PUT(HDRP(bp), PACK(size,0));
        PUT(FTRP(bp), PACK(size,0));
    } else if(!prev_alloc && next_alloc) {
        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        delete_node(PREV_BLKP(bp));
        PUT(FTRP(bp),PACK(size,0));
        PUT(HDRP(PREV_BLKP(bp)),PACK(size,0));
        bp = PREV_BLKP(bp);
    } else {
        size +=GET_SIZE(FTRP(NEXT_BLKP(bp)))+ GET_SIZE(HDRP(PREV_BLKP(bp)));
        delete_node(PREV_BLKP(bp));
        delete_node(NEXT_BLKP(bp));
        PUT(FTRP(NEXT_BLKP(bp)),PACK(size,0));
        PUT(HDRP(PREV_BLKP(bp)),PACK(size,0));
        bp = PREV_BLKP(bp);
    }
    insert_node(bp);
    return bp;
}

static void *find_fit(size_t size) {
    /*first fit*/
    char *bp = GET(list_head);
    while(bp != NULL) {
        if(GET_SIZE(HDRP(bp))>=size) {
            return bp;
        }
        bp = GET(NEXT_PTR(bp));
    }
    return NULL;
}

static void place(void *bp,size_t asize) {
    size_t csize = GET_SIZE(HDRP(bp));
    delete_node(bp);
    if((csize-asize)>=(2*DSIZE)) {
        PUT(HDRP(bp),PACK(asize,1));
        PUT(FTRP(bp),PACK(asize,1));
        bp = NEXT_BLKP(bp);

        PUT(HDRP(bp),PACK(csize-asize,0));
        PUT(FTRP(bp),PACK(csize-asize,0));
        //set the pointer
        PUT(NEXT_PTR(bp),0);
        PUT(PREV_PTR(bp),0);

        coalesce(bp);
    } else {
        PUT(HDRP(bp),PACK(csize,1));
        PUT(FTRP(bp),PACK(csize,1));
    }
}