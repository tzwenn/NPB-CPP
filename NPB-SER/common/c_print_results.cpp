/*
MIT License

Copyright (c) 2021 Parallel Applications Modelling Group - GMAP 
	GMAP website: https://gmap.pucrs.br
	
	Pontifical Catholic University of Rio Grande do Sul (PUCRS)
	Av. Ipiranga, 6681, Porto Alegre - Brazil, 90619-900

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

------------------------------------------------------------------------------

The original NPB 3.4.1 version was written in Fortran and belongs to: 
	http://www.nas.nasa.gov/Software/NPB/

------------------------------------------------------------------------------

The serial C++ version is a translation of the original NPB 3.4.1
Serial C++ version: https://github.com/GMAP/NPB-CPP/tree/master/NPB-SER

Authors of the C++ code: 
	Dalvan Griebler <dalvangriebler@gmail.com>
	Gabriell Araujo <hexenoften@gmail.com>
 	Júnior Löff <loffjh@gmail.com>
*/ 

#include <cstdlib>
#include <cstdio>
#include <cmath>

/*****************************************************************/
/******     C  _  P  R  I  N  T  _  R  E  S  U  L  T  S     ******/
/*****************************************************************/
void c_print_results(char* name,
		char class_npb,
		int n1, 
		int n2,
		int n3,
		int niter,
		double t,
		double mops,
		char* optype,
		int passed_verification,
		char* npbversion,
		char* compiletime,
		char* compilerversion,
		char* cc,
		char* clink,
		char* c_lib,
		char* c_inc,
		char* cflags,
		char* clinkflags,
		char* rand){
	fprintf(stderr, "\n\n %s Benchmark Completed\n", name);
	fprintf(stderr, " class_npb       =                        %c\n", class_npb);
	if((name[0]=='I')&&(name[1]=='S')){
		if(n3==0){
			long nn = n1;
			if(n2!=0){nn*=n2;}
			fprintf(stderr, " Size            =             %12ld\n", nn); /* as in IS */
		}else{
			fprintf(stderr, " Size            =             %4dx%4dx%4d\n", n1,n2,n3);
		}
	}else{
		char size[16];
		int j;
		if((n2==0) && (n3==0)){
			if((name[0]=='E')&&(name[1]=='P')){
				sprintf(size, "%15.0lf", pow(2.0, n1));
				j = 14;
				if(size[j] == '.'){
					size[j] = ' '; 
					j--;
				}
				size[j+1] = '\0';
				fprintf(stderr, " Size            =          %15s\n", size);
			}else{
				fprintf(stderr, " Size            =             %12d\n", n1);
			}
		}else{
			fprintf(stderr, " Size            =           %4dx%4dx%4d\n", n1, n2, n3);
		}
	}	
	fprintf(stderr, " Iterations      =             %12d\n", niter); 
	fprintf(stderr, " Time in seconds =           %12.4f\n", t);
	fprintf(stderr, " Mop/s total     =           %12.4f\n", mops);
	fprintf(stderr, " Operation type  = %24s\n", optype);
	if(passed_verification < 0){
		fprintf(stderr,  " Verification    =            NOT PERFORMED\n");
	}else if(passed_verification){
		fprintf(stderr, " Verification    =               SUCCESSFUL\n");
	}else{
		fprintf(stderr, " Verification    =             UNSUCCESSFUL\n");
	}
	fprintf(stderr, " Version         =             %12s\n", npbversion);
	fprintf(stderr, " Compiler ver    =             %12s\n", compilerversion);
	fprintf(stderr, " Compile date    =             %12s\n", compiletime);
	fprintf(stderr, "\n Compile options:\n");
	fprintf(stderr, "    CC           = %s\n", cc);
	fprintf(stderr, "    CLINK        = %s\n", clink);
	fprintf(stderr, "    C_LIB        = %s\n", c_lib);
	fprintf(stderr, "    C_INC        = %s\n", c_inc);
	fprintf(stderr, "    CFLAGS       = %s\n", cflags);
	fprintf(stderr, "    CLINKFLAGS   = %s\n", clinkflags);
	fprintf(stderr, "    RAND         = %s\n", rand);
#ifdef SMP
	evalue = getenv("MP_SET_NUMTHREADS");
	fprintf(stderr, "   MULTICPUS = %s\n", evalue);
#endif    
	/* 
	 * fprintf(stderr, " Please send the results of this run to:\n\n");
	 * fprintf(stderr, " NPB Development Team\n");
	 * fprintf(stderr, " Internet: npb@nas.nasa.gov\n \n");
	 * fprintf(stderr, " If email is not available, send this to:\n\n");
	 * fprintf(stderr, " MS T27A-1\n");
	 * fprintf(stderr, " NASA Ames Research Center\n");
	 * fprintf(stderr, " Moffett Field, CA  94035-1000\n\n");
	 * fprintf(stderr, " Fax: 650-604-3957\n\n");
	 */
	fprintf(stderr, "\n\n");
	
	fprintf(stderr, "----------------------------------------------------------------------\n");
	fprintf(stderr, "    NPB-CPP is developed by: \n");
	fprintf(stderr, "        Dalvan Griebler\n");
	fprintf(stderr, "        Gabriell Araujo (Sequential Porting)\n");
	fprintf(stderr, "        Júnior Löff (Parallel Implementation)\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "    In case of questions or problems, please send an e-mail to us:\n");	
	fprintf(stderr, "        dalvan.griebler; gabriell.araujo; junior.loff@edu.pucrs.br\n");
	fprintf(stderr, "----------------------------------------------------------------------\n");
	fprintf(stderr, "\n");
}
