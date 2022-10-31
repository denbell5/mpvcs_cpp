#include <stdio.h>

#define PRINTLN_D(d) printf("%d\n", d)
#define IS_DIVISIBLE(X, Y) ((X) % (Y) == 0 ? 1 : 0)
#define IF(cond) \
    if (cond) {  \
       
#define THEN(body) body; }
#define BEGIN {
#define END }
#define SET =
#define LESS_THAN <
#define LESS_THAN_OR_EQUAL <=
#define INC(i) i++
#define ZERO 0
#define ONE 1
#define TWO 2

int main()
BEGIN
    int num SET 25;

    for (int i SET TWO; i LESS_THAN_OR_EQUAL num; INC(i))
    BEGIN
        int is_prime SET ONE;
        for (int j SET TWO; j LESS_THAN i; INC(j))
        BEGIN
            IF(IS_DIVISIBLE(i, j)) THEN(is_prime SET ZERO; break);
        END
        IF(is_prime) THEN(PRINTLN_D(i));
    END

    return ZERO;
END
