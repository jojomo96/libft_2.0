#include "libft/libft.h"

double ft_sqrt(double x)
{
    if (x <= 0.0)
        return 0.0;

    /* Newton-Raphson */
    double g = (x >= 1.0) ? x : 1.0;

    for (int i = 0; i < 30; i++) {
        double ng = 0.5 * (g + x / g);
        /* cheap convergence check */
        if (ng == g)
            break;
        g = ng;
    }
    return g;
}
