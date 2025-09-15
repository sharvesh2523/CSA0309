/* reverse32.c
   Compile: gcc -std=c11 -Wall -o reverse32 reverse32.c
   Run:     ./reverse32
*/

#include <stdio.h>
#include <inttypes.h>  /* for SCNd32, PRId32 */
#include <stdint.h>    /* for int32_t, int64_t */
#include <limits.h>    /* for INT32_MAX, INT32_MIN */

int32_t reverse_int32(int32_t x) {
    int64_t rev = 0;        /* use 64-bit to detect overflow */
    int64_t y = x;

    if (y < 0) y = -y;      /* work with positive magnitude */

    while (y != 0) {
        int digit = y % 10;
        rev = rev * 10 + digit;
        if (rev > INT32_MAX)  /* overflow check */
            return 0;
        y /= 10;
    }

    return (int32_t)((x < 0) ? -rev : rev);
}

int main(void) {
    int32_t num;
    printf("Enter a 32-bit signed integer: ");
    if (scanf("%" SCNd32, &num) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    int32_t rev = reverse_int32(num);
    if (rev == 0 && num != 0) {
        /* This indicates overflow in this implementation's convention */
        printf("Reversed value overflows 32-bit signed range -> returning 0\n");
    }
    printf("Original: %" PRId32 "\nReversed: %" PRId32 "\n", num, rev);
    return 0;
}
