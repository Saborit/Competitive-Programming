// -- aumentar la memoria de la stack en ubuntu
#include <sys/resource.h>
rlimit r;
getrlimit(3, &r);
r.rlim_max = 1<<30;
r.rlim_cur = 1<<30;
setrlimit(3, &r);
