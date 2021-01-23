/*

Copyright 2021 Micheal Colhoun
  
Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.
  
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define MILLION 1000000
#define BILLION 1000000000.0d

#ifdef DEBUG
#define DEBUG_PRINT(fmt, args...)    fprintf(stderr, fmt, ## args)
#else
#define DEBUG_PRINT(fmt, args...)    /* nothing */
#endif

struct timespec gettime()
{
   struct timespec tm;
   
   clock_gettime(CLOCK_REALTIME, &tm);

   return tm;
}


int main(int argc, char *argv[])
{

     long long diff = 0;
     long long extra = 0;
   
    if (argc > 1) {
         printf("Usage: bogomips \n");
         return 0;
    }  
	
    DEBUG_PRINT ("sizeof(int) = %d\n",sizeof(int));
    DEBUG_PRINT ("sizeof(long) = %d\n",sizeof(long));
    DEBUG_PRINT ("sizeof(unsigned long) = %d\n",sizeof(unsigned long));
    DEBUG_PRINT ("sizeof(long long) = %d\n",sizeof(long long));
	    
    volatile register int loop = 1000 * MILLION;
    DEBUG_PRINT("loop  : %09d\n", loop);   
    struct timespec start_time = gettime();
    while (loop--) {
	    
        ; // do nothing lots
    }
    struct timespec end_time = gettime();
	
    diff = end_time.tv_nsec - start_time.tv_nsec;
    DEBUG_PRINT("diff  : %09lld\n", diff);   
    if ( end_time.tv_sec > start_time.tv_sec) {	     
	     
        extra = end_time.tv_sec - start_time.tv_sec;
        
        DEBUG_PRINT("extra : %09lld\n", extra);
    }
	
    double ips = BILLION / ( (double)(extra * BILLION) + (double)diff ); // in nanoseconds
    DEBUG_PRINT("Instructions Per Nanosecond : %lf\n", ips);
    
    double bogomips = ips * 1000;
    printf("BogoMIPS : %0.2lf\n", bogomips);
    return 0;
}

	 
			       
			       
