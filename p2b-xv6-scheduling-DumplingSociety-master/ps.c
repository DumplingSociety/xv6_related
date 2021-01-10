#include "pstat.h"
#include "types.h"
#include "user.h"
#include "types.h"

int main(int argc, char *argv[])
{
	struct pstat pinfo = {0};
	if (getpinfo(&pinfo) != 0 )
	{
	return 0;
	printf(1, "FAIL\n");
	}

	for(int i = 0; i < NPROC; i++)
	{
		if(pinfo.pid[i] !=0 )
			printf(1, "pid(%d) inuse(%d) tickets(%d) ticks(%d) \n", pinfo.pid[i], pinfo.inuse[i], pinfo.tickets[i], pinfo.ticks[i]);
	}
	exit();

}
