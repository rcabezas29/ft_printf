#include "ft_printf.h"

int main(void)
{
    ft_printf("%i|%-i|%+i|% i|%0i\n", 0, 0, 0, 0, 0);
    printf("%i|%-i|%+i|% i|%0i\n", 0, 0, 0, 0, 0);
}