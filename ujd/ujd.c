#include "ujd.h"

ujd parseAbsoluteTimeToUJD(char * inputTime)
{
	ujd parsedTime;
	if (strstr(inputTime, "ſ") != NULL)
	{
		char solDecimal[14] = "";
		char timeBuf[25];
		strncpy(timeBuf, inputTime, sizeof(timeBuf));
		char *solPart = strtok(timeBuf, " ");
		while (solPart != NULL)
		{
			if (strcmp(solPart, "ſ") == 0)
				strncat(solDecimal, ".", 1);
			else
				strncat(solDecimal, solPart, sizeof(solPart));
			
			solPart = strtok(NULL, " ");
		}
		
		parsedTime.time = atof(solDecimal);
		parsedTime.absolute = true;
	}
	else
	{
		char timeBuf[24];
		strncpy(timeBuf, inputTime, sizeof(timeBuf));
		struct tm timeStruct;
		
		strptime(timeBuf, "%FT%T%z", &timeStruct);
		if (&timeStruct == NULL) return parsedTime;
		parsedTime.time = ((double)mktime(&timeStruct) / 86400);
		parsedTime.absolute = true;
	}
	
	return parsedTime;
}

char * formatAsOldtime(ujd time, char * oldtimeBuffer)
{
	return NULL;
}

char * formatAsUJD(ujd time, char * ujdBuffer)
{
	return NULL;
}

/*
// Utilities
*/

ujd GetCurrentUJD()
{
	ujd time;
	
	struct timeval tv;
	gettimeofday(&tv, NULL);
	
	time.absolute = true;
	time.time = (double)tv.tv_sec / 86400;
	
	return time;
}

char * UJDToUJD(char * ujdString, ujd ujdDecimal)
{
	char ujd[14];
	snprintf(ujd, 14, "%f", ujdDecimal.time);
	char * ujdWhole = strtok(ujd, "."); // Probably not the most efficient way to do this...
	char * ujdFraction = strtok(NULL, ".");
	
	int ujdSols = atoi(ujdWhole) % 1000;
	int ujdKilosols = floor(atoi(ujdWhole) / 1000);
	int ujdMillisols = floor(atoi(ujdFraction) / 1000);
	int ujdMicrosols = atoi(ujdFraction) % 1000;
	
	snprintf(ujdString, 18, "%d %d ſ %d %d\n", ujdKilosols, ujdSols, ujdMillisols, ujdMicrosols);
	return ujdString;
}

char * UJDToOldtime(char * oldtimeString, ujd ujdDecimal)
{
	time_t currentSeconds = (time_t)(ujdDecimal.time*86400);
	struct tm *currentTime = gmtime(&currentSeconds);
	strftime(oldtimeString, 25, "%FT%TZ", currentTime);
	
	return oldtimeString;
}
