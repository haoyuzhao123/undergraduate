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
team_t team = {
    /* Team name */
    "2016011343",
    /* First member's full name */
    "Chenyao Lou",
    /* First member's email address */
    "loucy16@mails.tsinghua.edu.cn",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""
};

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~0x7)

#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))

/* Basic constants and macros */
#define WSIZE       4       /* Word and header/footer size (bytes) */
#define DSIZE       8       /* Double word size (bytes) */
#define CHUNKSIZE  (1<<12)  /* Extend heap by this amount (bytes) */
#define MAX(x, y) ((x) > (y)? (x) : (y))

/* Pack a size and allocated bit into a word */
#define PACK(size, alloc)  ((size) | (alloc))

/* Read and write a word at address p */
#define GET(p)       (*(unsigned int *)(p))
#define PUT(p, val)  (*(unsigned int *)(p) = (val))

/* Read the size and allocated fields from address p */
#define GET_SIZE(p)  (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)

/* Given block ptr bp, compute address of its header and footer */
#define HDRP(bp) ((char *)(bp) - WSIZE)
#define FTRP(bp) ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)

/* Given block ptr bp, compute address of next and previous blocks */
#define NEXT_BLKP(bp) ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE)))
#define PREV_BLKP(bp) ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)))

#define NEXTP(bp) ((char *)bp)
#define PREVP(bp) ((char *)bp + WSIZE)

#define NEXT_PTR(bp) (GET(NEXTP(bp)))
#define PREV_PTR(bp) (GET(PREVP(bp)))

void *heap_listp;

void *ptr_head_1;
void *ptr_head_2;

void list_add_(void ** ptr_head, void *p) {
    if (*ptr_head) {
        PUT(PREVP(*ptr_head), p);
    }

    PUT(NEXTP(p), *ptr_head);
    PUT(PREVP(p), 0);
    *ptr_head = p;
}

void list_del_(void ** ptr_head, void *p) {
    if (PREV_PTR(p)) {
        PUT(NEXTP(PREV_PTR(p)), NEXT_PTR(p));
    }
    if (NEXT_PTR(p)) {
        PUT(PREVP(NEXT_PTR(p)), PREV_PTR(p));
    }
    if (*ptr_head == p) {
        *ptr_head = NEXT_PTR(p);
    }
}

void *select_head(size_t s) {
    if (s <= 128) return ptr_head_1;
    else return ptr_head_2;
}

void list_del(void *p) {
    size_t s = GET_SIZE(HDRP(p));
    if (s <= 128) list_del_(&ptr_head_1, p);
    else list_del_(&ptr_head_2, p);
}

void list_add(void *p) {
    size_t s = GET_SIZE(HDRP(p));
    if (s <= 128) list_add_(&ptr_head_1, p);
    else list_add_(&ptr_head_2, p);
}


void debug() {
    char *bp = heap_listp;
    int size = GET_SIZE(HDRP(bp));
    int a = GET_ALLOC(HDRP(bp));
    void *p = ptr_head_1;

    printf("\n");
    while (size > 0) {
        printf("%d/%d - ", size, a);

        if (GET(HDRP(bp)) != GET(FTRP(bp))) {
            printf("(ERROR FTPR: %d/%d)", GET_SIZE(FTRP(bp)), GET_ALLOC(FTRP(bp)));
        }

        bp = NEXT_BLKP(bp);
        size = GET_SIZE(HDRP(bp));
        a = GET_ALLOC(HDRP(bp));
    }
    printf("%d/%d\n", size, a);



    //printf("ptr_head: %d\n", (int)p);
    
    printf("free_1: ");
    while (p) {
        printf("%d ", GET_SIZE(HDRP(p)));
        p = NEXT_PTR(p);
    }
    printf("\n");
    p = ptr_head_2;
    printf("free_2: ");
    while (p) {
        printf("%d ", GET_SIZE(HDRP(p)));
        p = NEXT_PTR(p);
    }
    printf("\n");
    fflush(stdout);
}

void* coalesce(void *bp) {
    size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
    size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
    size_t size = GET_SIZE(HDRP(bp));
    if (prev_alloc && next_alloc) {
        return bp;
    } else if (prev_alloc && !next_alloc) {
        list_del(NEXT_BLKP(bp));
        list_del(bp);
        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));

        PUT(HDRP(bp), PACK(size, 0));
        PUT(FTRP(bp), PACK(size, 0));
    } else if (!prev_alloc && next_alloc) {
        list_del(bp);
        list_del(PREV_BLKP(bp));

        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        PUT(FTRP(bp), PACK(size, 0));
        PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
        bp = PREV_BLKP(bp);
    } else {
        list_del(bp);
        list_del(PREV_BLKP(bp));
        list_del(NEXT_BLKP(bp));

        size += GET_SIZE(HDRP(PREV_BLKP(bp))) + GET_SIZE(FTRP(NEXT_BLKP(bp)));
        PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
        PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
        bp = PREV_BLKP(bp);
    }
    list_add(bp);
    return bp;
}

void* extend_heap(size_t words) {
    char *bp;
    size_t size;

    size = (words % 2) ? (words + 1) * WSIZE : words * WSIZE;
    if ((long)(bp = mem_sbrk(size)) == -1) return NULL;


    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));

    list_add(bp);

    return coalesce(bp);
}

/* 
 * mm_init - initialize the malloc package.
 */
int mm_init(void)
{
    char *bp;
    if ((heap_listp = mem_sbrk(4*WSIZE)) == (void *)-1) return -1;
    PUT(heap_listp, 0);
    // Prologue block
    PUT(heap_listp + 1*WSIZE, PACK(DSIZE, 1));
    PUT(heap_listp + 2*WSIZE, PACK(DSIZE, 1));
    // Epilogue block
    PUT(heap_listp + 3*WSIZE, PACK(0, 1));
    heap_listp += 2*WSIZE;
    ptr_head_1 = 0;
    ptr_head_2 = 0;
    if ((bp = extend_heap(CHUNKSIZE/WSIZE)) == NULL) return -1;

    //debug();
    return 0;
}


void place(void *bp, size_t size, int realloc) {
    size_t freesize = 0;
    if (size + DSIZE >= GET_SIZE(HDRP(bp))) {
        size = GET_SIZE(HDRP(bp));
    } else {
        freesize = GET_SIZE(HDRP(bp)) - size;
    }

    if (realloc == 0) list_del(bp);
    PUT(HDRP(bp), PACK(size, 1));
    PUT(FTRP(bp), PACK(size, 1));

    
    if (freesize > 0 ) {
        bp = NEXT_BLKP(bp);
        PUT(HDRP(bp), PACK(freesize, 0));
        PUT(FTRP(bp), PACK(freesize, 0));
        list_add(bp);
    }
}

void* find_fit(size_t s) {
    char *bp = heap_listp;
    size_t size = GET_SIZE(HDRP(bp));
    while (size > 0) {
        if (size >= s && GET_ALLOC(HDRP(bp)) == 0) {
            return bp;
        }

        bp = NEXT_BLKP(bp);
        size = GET_SIZE(HDRP(bp));
    }
    return NULL;
}

void* find_fit_in_list_(char *p, size_t s) {
    while(p) {
        if (GET_SIZE(HDRP(p)) >= s) {
            return p;
        }
        p = NEXT_PTR(p);
    }
    return NULL;
}

void* find_fit_in_list(size_t s) {
    char* bp;
    if (s <= 128 && (bp = find_fit_in_list_(ptr_head_1, s)) != NULL) {
        return bp;
    }
    return find_fit_in_list_(ptr_head_2, s);
}

/* 
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void* mm_malloc(size_t size)
{
    size_t asize;
    size_t extendsize;
    char *bp;

    if (size == 0) return NULL;

    if (size <= DSIZE) asize = 2*DSIZE;
    else asize = DSIZE * ((size + (DSIZE) + (DSIZE - 1)) / DSIZE);

    if ((bp = find_fit_in_list(asize)) != NULL) {
        place(bp, asize, 0);
        //debug();
        return bp;
    }

    extendsize = MAX(asize, CHUNKSIZE);
    if ((bp = extend_heap(extendsize/WSIZE)) == NULL) return NULL;
    place(bp, asize, 0);
    
    //debug();
    return bp;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *bp)
{
    size_t size = GET_SIZE(HDRP(bp));

    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    //debug();
    list_add(bp);
    coalesce(bp);

    //debug();
}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size)
{
    size_t sum = GET_SIZE(HDRP(NEXT_BLKP(ptr))) + GET_SIZE(HDRP(ptr));
    size_t asize;
    if (size <= DSIZE) asize = 2*DSIZE;
    else asize = DSIZE * ((size + (DSIZE) + (DSIZE - 1)) / DSIZE);

    if (GET_ALLOC(HDRP(NEXT_BLKP(ptr))) == 0 && sum >= asize) {

        list_del(NEXT_BLKP(ptr));
        PUT(HDRP(ptr), PACK(sum, 1));
        PUT(FTRP(ptr), PACK(sum, 1));

        place(ptr, asize, 1);
        return ptr;
    }

    void *oldptr = ptr;
    void *newptr;
    size_t copySize;
    
    newptr = mm_malloc(size);
    if (newptr == NULL)
      return NULL;
    copySize = GET_SIZE(HDRP(oldptr)) - DSIZE   ;
    if (size < copySize)
      copySize = size;
    memcpy(newptr, oldptr, copySize);
    mm_free(oldptr);
    return newptr;
}