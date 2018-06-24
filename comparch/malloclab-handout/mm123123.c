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
//use an unsigned int value to represent the address of the list head
//static unsigned int list_head_addr;
static unsigned int list_head_addr1;
static unsigned int list_head_addr2;
static unsigned int list_head_addr3;
static unsigned int list_head_addr4;
static unsigned int list_head_addr5;
static unsigned int list_head_addr6;
static unsigned int list_head_addr7;
static unsigned int list_head_addr8;
static unsigned int list_head_addr9;
static unsigned int list_head_addr10;
static unsigned int list_head_addr11;
static unsigned int list_head_addr12;
static unsigned int list_head_addr13;
static unsigned int list_head_addr14;
static unsigned int list_head_addr15;
static unsigned int list_head_addr16;
static unsigned int list_head_addr17;

//search size
static unsigned int * get_size_head_ptr(size_t sz){    
    if(sz<=4){
        return &list_head_addr10;  
    } else if(sz<=8) {
        return &list_head_addr11;
    } else if(sz<=16) {
        return &list_head_addr1;
    } else if(sz<=32) {
        return &list_head_addr2;
    } else if(sz<=64) {
        return &list_head_addr3;
    } else if(sz<=128) {
        return &list_head_addr4;
    } else if(sz<=256) {
        return &list_head_addr5;
    } else if(sz<=512) {
        return &list_head_addr6;
    } else if(sz<=1024) {
        return &list_head_addr7;
    } else if(sz<=2048) {
        return &list_head_addr8;
    } else if(sz<=4096) {
        return &list_head_addr9;
    } else {
        return &list_head_addr14;
    }
}

//insert node and delete node helper function
void insert_node(char *bp, size_t size) {
    //char *next = (char *)list_head_addr;
    unsigned int * ptr = get_size_head_ptr(size);
    //ptr = &list_head_addr;
    char *next = (char *)(*ptr);
    if(next != NULL) {
        PUT(PREV_PTR(next),(unsigned int)bp);
    }
    PUT(NEXT_PTR(bp),(unsigned int)next);
    //list_head_addr = (unsigned int)bp;
    *ptr = (unsigned int)bp;
}
void delete_node(char *bp, size_t size) {
    char *prev = (char *)GET(PREV_PTR(bp));
    char *next = (char *)GET(NEXT_PTR(bp));
    unsigned int * ptr = get_size_head_ptr(size);
    //ptr = &list_head_addr;
    if(prev == NULL) {
        if(next != NULL)PUT(PREV_PTR(next),0);
        //list_head_addr = (unsigned int)next;
        //PUT(ptr, (unsigned int)bp);
        *ptr = (unsigned int)next;
    } else {
        if(next != NULL) {
            PUT(PREV_PTR(next),(unsigned int)prev);
        }
        PUT(NEXT_PTR(prev),(unsigned int)next);
    }
    PUT(NEXT_PTR(bp),0);
    PUT(PREV_PTR(bp),0);
}

int mm_init(void) {
    if((heap_listp = mem_sbrk(4*WSIZE))==(void *)-1) return -1;

    PUT(heap_listp,0);
    //space for the list_head
    PUT(heap_listp+(1*WSIZE),PACK(DSIZE,1));
    PUT(heap_listp+(2*WSIZE),PACK(DSIZE,1));
    PUT(heap_listp+(3*WSIZE),PACK(0,1));

    heap_listp += (4*WSIZE);
    //list_head_addr = 0;
    list_head_addr1 = 0;
    list_head_addr2 = 0;
    list_head_addr3 = 0;
    list_head_addr4 = 0;
    list_head_addr5 = 0;
    list_head_addr6 = 0;
    list_head_addr7 = 0;
    list_head_addr8 = 0;
    list_head_addr9 = 0;
    list_head_addr10 = 0;
    list_head_addr11 = 0;
    list_head_addr12 = 0;
    list_head_addr13 = 0;
    list_head_addr14 = 0;
    list_head_addr15 = 0;
    list_head_addr16 = 0;
    list_head_addr17 = 0;

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
        delete_node(NEXT_BLKP(ptr), GET_SIZE(HDRP(NEXT_BLKP(ptr))));
        PUT(HDRP(ptr), PACK(csize, 0));
        PUT(FTRP(ptr), PACK(csize, 0));
        insert_node(ptr, GET_SIZE(HDRP(ptr)));
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
    size_t next_size = GET_SIZE(HDRP(NEXT_BLKP(bp)));
    size_t prev_size = GET_SIZE(HDRP(PREV_BLKP(bp)));

    if(prev_alloc && next_alloc) {
    }
    else if(prev_alloc && !next_alloc) {
        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));

        delete_node(NEXT_BLKP(bp), next_size);

        PUT(HDRP(bp), PACK(size,0));
        PUT(FTRP(bp), PACK(size,0));
    } else if(!prev_alloc && next_alloc) {
        size += GET_SIZE(HDRP(PREV_BLKP(bp)));

        delete_node(PREV_BLKP(bp), prev_size);
        PUT(FTRP(bp),PACK(size,0));
        PUT(HDRP(PREV_BLKP(bp)),PACK(size,0));
        bp = PREV_BLKP(bp);
    } else {
        size +=GET_SIZE(FTRP(NEXT_BLKP(bp)))+ GET_SIZE(HDRP(PREV_BLKP(bp)));

        delete_node(PREV_BLKP(bp), prev_size);
        delete_node(NEXT_BLKP(bp), next_size);
        PUT(FTRP(NEXT_BLKP(bp)),PACK(size,0));
        PUT(HDRP(PREV_BLKP(bp)),PACK(size,0));
        bp = PREV_BLKP(bp);
    }
    insert_node(bp,size);
    return bp;
}

static void *find_fit(size_t size) {
    /*first fit*/
    unsigned int * ptr = get_size_head_ptr(size);
    //ptr = &list_head_addr;
    //char *bp = (char *)list_head_addr;
    if (size > 1<<17) {
        char *bp = (char *)(*ptr);
        while(bp != NULL) {
            if(GET_SIZE(HDRP(bp))>=size) {
                return bp;
            }
            bp = (char *)GET(NEXT_PTR(bp));
        }
    } else {
        while (size <= 1<<18) {
            char *bp = (char *)(*ptr);
            while(bp != NULL) {
                if(GET_SIZE(HDRP(bp))>=size) {
                    return bp;
                }
                bp = (char *)GET(NEXT_PTR(bp));
            }
            size *= 2;
            ptr = get_size_head_ptr(size);
        }
    }
    return NULL;
}

static void place(void *bp,size_t asize) {
    size_t csize = GET_SIZE(HDRP(bp));
    delete_node(bp, csize);
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
