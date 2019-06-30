#ifndef __LIBS_STRING_H__
#define __LIBS_STRING_H__

#include <stddef.h>

void *memset(void *s, char c, size_t n){
	char *p = s;
	while(n-- > 0){
		*p++ = c;
	}
	return s;
}

#endif /* __LIBS_STRING_H__ */
