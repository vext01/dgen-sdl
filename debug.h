// dgen debugger
// (C) 2012, Edd Barrett <vext01@gmail.com>

#ifndef DEBUG_H_
#define DEBUG_H_

#ifdef WITH_DEBUGGER

#include "md.h"
#include "linenoise/linenoise.h"

#define MAX_BREAKPOINTS			64
#define MAX_WATCHPOINTS			64
#define MAX_DEBUG_TOKS			8
#define DEBUG_DFLT_DASM_LEN		8
#define DEBUG_DFLT_MEMDUMP_LEN		128

#define DBG_CONTEXT_M68K		0
#define DBG_CONTEXT_Z80			1

class md;

// break point
struct dgen_bp {
	uint32_t	addr;
#define BP_FLAG_USED		(1<<0)
	uint32_t	flags;
};

// watch point
struct dgen_wp {
	uint32_t	 start_addr;
	uint32_t	 end_addr;
#define WP_FLAG_USED		(1<<0)
#define WP_FLAG_FIRED		(1<<1)
	uint32_t	 flags;
	unsigned char	*bytes;
};

extern int m68k_bp_hit;
extern int m68k_wp_hit;

extern "C" void		debug_init(void);

// linenoise

#endif
#endif
