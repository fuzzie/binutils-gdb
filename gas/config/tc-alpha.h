/* This file is tc-alpha.h
   Copyright (C) 1994 Free Software Foundation, Inc.
   Written by Ken Raeburn <raeburn@cygnus.com>.

   This file is part of GAS, the GNU Assembler.

   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   GAS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to
   the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

#define TC_ALPHA

#define TARGET_ARCH			bfd_arch_alpha

#define TARGET_FORMAT (OUTPUT_FLAVOR == bfd_target_ecoff_flavour	\
		       ? "ecoff-littlealpha"				\
		       : OUTPUT_FLAVOR == bfd_target_elf_flavour	\
		       ? "elf64-alpha"					\
		       : "unknown-format")

#define NEED_LITERAL_POOL
#define TC_HANDLES_FX_DONE
#define REPEAT_CONS_EXPRESSIONS

extern int alpha_force_relocation PARAMS ((struct fix *));
extern int alpha_fix_adjustable PARAMS ((struct fix *));

extern unsigned long alpha_gprmask, alpha_fprmask;
extern valueT alpha_gp_value;

#define TC_FORCE_RELOCATION(FIXP)	alpha_force_relocation (FIXP)
#define tc_fix_adjustable(FIXP)		alpha_fix_adjustable (FIXP)
#define RELOC_REQUIRES_SYMBOL

#define md_convert_frag(b,s,f)		as_fatal ("alpha convert_frag\n")
#define md_create_long_jump(p,f,t,fr,s)	as_fatal("alpha_create_long_jump")
#define md_create_short_jump(p,f,t,fr,s) as_fatal("alpha_create_short_jump")
#define md_estimate_size_before_relax(f,s) \
			(as_fatal("estimate_size_before_relax called"),1)
#define md_operand(x)			0

extern unsigned long md_section_align PARAMS ((segT, unsigned long));

#define md_undefined_symbol(name)	(0)

#define LOCAL_LABEL(name)		((name)[0] == 'L')

#define md_number_to_chars		number_to_chars_littleendian

extern int alpha_do_align ();
#define md_do_align(n,fill,l)	if (alpha_do_align(n,fill)) goto l

extern void alpha_frob_file ();
#define tc_frob_file		alpha_frob_file
