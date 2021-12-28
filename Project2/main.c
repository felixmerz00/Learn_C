#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_scoops_vanilla = 1;
    int num_scoops_chocolate = 3;

    printf("Test\n");
    char var[4];
    itoa(get_price(0, 2), var, 10);
    printf("%s", var);
    return 0;
}

int get_price(int num_scoops_vanilla, int num_scoops_chocolate)
{
    double price_cone = 0.7;
    double price_per_scoop_vanilla = 1.00;
    double price_per_scoop_chocolate = 1.10;

    double price = num_scoops_vanilla * (price_cone + price_per_scoop_vanilla) + num_scoops_chocolate * (price_cone + price_per_scoop_chocolate);
    return price;
}
