// Copyright 2017 syzkaller project authors. All rights reserved.
// Use of this source code is governed by Apache 2 LICENSE that can be found in the LICENSE file.
//Kaspersky OS
#include <stdio.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/prctl.h>
//#include "nocover.h"
#include "core/VMM.cdl.h"

static void os_init(int argc, char** argv, void* data, size_t data_size)
{
if(mmap(data,data_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE | MAP_FIXED, -1, 0) != data)
fprintf(stderr,"mmap of data segment failed");
}

static intptr_t execute_syscall(const call_t* c, intptr_t a[kMaxArgs])
{

if (c->call) {
return c->call(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
}
return syscall(c->sys_nr,a[0], a[1], a[2], a[3], a[4], a[5]);
}
