//
//  main.c
//  ujd
//
//  Created by Billy Doyle on 12/4/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include "ujd.h"

int main(int argc, char *argv[])
{
	char time[25];
	if (argv[1] == NULL)
	{
		printf("%s\n", UJDToUJD(time, GetCurrentUJD()));
		return 0;
	}
	printf("%s\n", UJDToOldtime(time, parseAbsoluteTimeToUJD(argv[1])));
	
	return 0;
}

