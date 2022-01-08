#include <stdio.h>
#include <stdlib.h>

double get_sum_of_divisors(int n);
int is_friendy_pair(int n1, int n2);
void test(int expected, int actual, const char* testName);

int main()
{
    /*int n, m;
    printf("Enter a natural number: ");
    scanf("%d", &n);
    printf("Enter a different natural number: ");
    scanf("%d", &m);*/



    double in;
    in  = 3/2;
    printf("i = %f", in);

    /*Testing*/
    test(1, is_friendy_pair(6, 28), "Friendly Pair 1");
    test(1, is_friendy_pair(30, 140), "Friendly Pair 2");
    test(1, is_friendy_pair(80, 200), "Friendly Pair 3");
    test(1, is_friendy_pair(40, 224), "Friendly Pair 4");
    test(1, is_friendy_pair(12, 234), "Friendly Pair 5");
    test(1, is_friendy_pair(84, 270), "Friendly Pair 6");
    test(1, is_friendy_pair(66, 308), "Friendly Pair 7");
    test(-1, is_friendy_pair(0, 1), "Not Friendly Pair 1");
    test(0, is_friendy_pair(1, 2), "Not Friendly Pair 2");
    test(0, is_friendy_pair(2, 3), "Not Friendly Pair 3");
    test(0, is_friendy_pair(2, 4), "Not Friendly Pair 4");
    test(0, is_friendy_pair(478392, 23123), "Not Friendly Pair 5");
    test(1, get_sum_of_divisors(1), "Sum of divisors of 1");
    test(3, get_sum_of_divisors(2), "Sum of divisors of 2");

    return 0;

}

/*Returns 1 if the input is a friendly pair, 0 if it is not a friendly pair, -1 if the input is invalid.*/
int is_friendy_pair(int n1, int n2)
{
    if(n1 < 1 || n1%1 != 0 || n2 < 1 || n2%1 != 0){
        return -1;
    }
    int n = n1;
    int m = n2;

    double n_abundancy = (get_sum_of_divisors(n)/n);
    double m_abundancy = (get_sum_of_divisors(m)/m);

    if(n_abundancy == m_abundancy){
        return 1;
    }
    else{
        return 0;
    }
}

double get_sum_of_divisors(int n)
{
    double sum_divisors = 0;
    for(int i = 1; i <= n/2; i++){
        if (n%i == 0){
            sum_divisors += i;
        }
    }
    sum_divisors += n;
    return sum_divisors;
}

void test(int expected, int actual, const char* testName)
{
    if(expected == actual){
        printf("\n%s PASSED", testName);
    }
    else{
        printf("\n%s FAILED expected: %d, actual: %d", testName, expected, actual);
    }
}
