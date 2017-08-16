/* 
 * File:   TAllocationBlock.h
 * Author: dvdemon
 *
 * Created on July 28, 2015, 9:17 AM
 */

#ifndef TALLOCATIONBLOCK_H
#define	TALLOCATIONBLOCK_H

#include <cstdlib>
class TAllocationBlock {
public:
    TAllocationBlock(uint64_t size,uint64_t count);
     void *allocate();
     void deallocate(void *pointer);
    bool has_free_blocks();
    
    virtual ~TAllocationBlock();
private:
    uint64_t _size;
    uint64_t _count;
    
    char  *_used_blocks;
    void  **_free_blocks;
    
    uint64_t _free_count;

        
};

#endif	/* TALLOCATIONBLOCK_H */

