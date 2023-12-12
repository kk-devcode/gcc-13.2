/* do not edit automatically generated by mc from Storage.  */
/* Storage.mod provides access to the dynamic Storage handler.

Copyright (C) 2001-2023 Free Software Foundation, Inc.
Contributed by Gaius Mulley <gaius.mulley@southwales.ac.uk>.

This file is part of GNU Modula-2.

GNU Modula-2 is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GNU Modula-2 is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#   if !defined (PROC_D)
#      define PROC_D
       typedef void (*PROC_t) (void);
       typedef struct { PROC_t proc; } PROC;
#   endif

#define _Storage_H
#define _Storage_C

#   include "GSysStorage.h"

extern "C" void Storage_ALLOCATE (void * *a, unsigned int Size);
extern "C" void Storage_DEALLOCATE (void * *a, unsigned int Size);
extern "C" void Storage_REALLOCATE (void * *a, unsigned int Size);
extern "C" unsigned int Storage_Available (unsigned int Size);

extern "C" void Storage_ALLOCATE (void * *a, unsigned int Size)
{
  SysStorage_ALLOCATE (a, Size);
}

extern "C" void Storage_DEALLOCATE (void * *a, unsigned int Size)
{
  SysStorage_DEALLOCATE (a, Size);
}

extern "C" void Storage_REALLOCATE (void * *a, unsigned int Size)
{
  SysStorage_REALLOCATE (a, Size);
}

extern "C" unsigned int Storage_Available (unsigned int Size)
{
  return SysStorage_Available (Size);
  /* static analysis guarentees a RETURN statement will be used before here.  */
  __builtin_unreachable ();
}

extern "C" void _M2_Storage_init (__attribute__((unused)) int argc,__attribute__((unused)) char *argv[],__attribute__((unused)) char *envp[])
{
}

extern "C" void _M2_Storage_fini (__attribute__((unused)) int argc,__attribute__((unused)) char *argv[],__attribute__((unused)) char *envp[])
{
}