#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prime.h"

/*

   This program is written to calculate the primes in the first billion
   numbers.

    Written by James M. Rogers
    04 May 1999

    A test in memory to see if it can be made faster
*/

char z[(MAXSIZE/8)+1];

void set_not_prime(unsigned long i) {

    ldiv_t results;
    char   c;

    results=ldiv(i, 16);

    switch (results.rem) {

        case 1:
             c='\xFE';
             break;
        case 3:
             c='\xFD';
             break;
        case 5:
             c='\xFB';
             break;
        case 7:
             c='\xF7';
             break;
        case 9:
             c='\xEF';
             break;
        case 11:
             c='\xDF';
             break;
        case 13:
             c='\xBF';
             break;
        case 15:
             c='\x7F';
             break;
        default:
             break;
    }
    z[results.quot]=(z[results.quot] & c);
}

int is_prime(unsigned long i) {

    ldiv_t results;
    char   c;

    results=ldiv(i, 16);

    switch (results.rem) {

        case 1:
             c='\x01';
             break;
        case 3:
             c='\x02';
             break;
        case 5:
             c='\x04';
             break;
        case 7:
             c='\x08';
             break;
        case 9:
             c='\x10';
             break;
        case 11:
             c='\x20';
             break;
        case 13:
             c='\x40';
             break;
        case 15:
             c='\x80';
             break;
        default:
             break;
    }
    return (int) (z[results.quot] & c);
}

void set_matrix(unsigned long i) {

    unsigned long    j;
    unsigned long offset = 2*i;

    for(j=i*i; j<MAXSIZE; j+=offset) {
        set_not_prime(j);
    }
}

void factors( unsigned long x) {

    unsigned long i;
    unsigned long max_factor;
    unsigned long current_factor;
    ldiv_t results;

    /* set the max_factor to square root of variable */
    max_factor = sqrt(x)+1;

    /* see if the variable is more than MAXSIZE^2 */
    if ( max_factor > MAXSIZE ) {
        printf ("Too large to solve, the largest number I can factor is %d.", MAXSIZE);
        exit (1);
    }
    printf ("%d: ", x);
    
    /* while current_factor < max_factor */
    for(i=2; i<max_factor; i++, i++) {

        /* Test factor */
        results = ldiv(x, i);
    
        /* If there is no remainder, print the current_factor, continue. */
        if ( results.rem == 0 ) {
            printf ("%d ", i);
            x = results.quot;
            max_factor = sqrt(x)+1 ;
            i--; i--;
        }
        if (i==2) i=1;
    }
    printf ("%d\n", x);
}

main(int argc, char *argv[]){

    unsigned long        i;
    unsigned long        max_num_to_check;
    div_t	results;
    int         c,
                j;

    /* Initialize the array */

    for(i=0;i<MAXSIZE/16;i++) {
        z[i]='\xFF';
    }

    /* For loop is the main loop that controls the function of the program */

    max_num_to_check = sqrt(MAXSIZE)+1;

    for(i=3;i<max_num_to_check; i+=2)
        if (is_prime(i)){ 
            set_matrix(i);
	    printf("%d\n", i);
	}

//    for(i=1;i<10000; i++)
 //       factors(i);

    /* Done, flush and close */
/*
    for (i=0; i<MAXSIZE/16;i++)
         putc(z[i], stdout);
*/
    exit (0);

}

