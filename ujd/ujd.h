//
//  ujd.h
//  ujd
//
//  Created by Billy Doyle on 12/4/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef ujd_ujd_h
#define ujd_ujd_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>

typedef struct ujd_struct
{
	bool absolute;
	double time;
}
ujd;

ujd parseAbsoluteTimeToUJD(char * inputTime);
char * formatAsOldtime(ujd time, char * oldtimeBuffer);
char * formatAsUJD(ujd time, char * ujdBuffer);

ujd GetCurrentUJD(void);
char * UJDToUJD(char * ujdString, ujd ujdDecimal);
char * UJDToOldtime(char * oldtimeString, ujd ujdDecimal);

#endif
