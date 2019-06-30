#ifndef __LIBS_STRING_H__
#define __LIBS_STRING_H__

#include <stddef.h>

/*
 * brief : set each byte in a memory region to a fixed value
 * @s :	the start address of the memory region
 * @c : the fixed value
 * @n : the length of the memory region
 * @return : @s
 */	
void *memset(void *s, char c, size_t n);


#endif /* __LIBS_STRING_H__ */
