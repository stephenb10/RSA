#include <stdio.h>

int isPrime(unsigned int number);
int getBitAt(int num, int position);
unsigned __int128 squareAndMultiply(int a, int b);
int* decToBinary(int num);

int main()
{
    int p, q, n, phin, e, d, m, c;

    while (1)
    {
        p = getPrimeNumberInput("p");
        q = getPrimeNumberInput("q");
        n = p * q;
        phin = (p - 1) * (q - 1);
        e = get_e(phin);
        m = getNumberBetween(0, n - 1, "m");
        c = squareAndMultiply(m, e) % n;
        printf("c = %d\n\n", c);
    }

    return 0;
}

// Asks for user input
// Loops until a prime number is entered
int getPrimeNumberInput(char* variable)
{
    int input;
    int valid = 0;
    do
    {
        printf("Enter a prime number for %s: ", variable);
        scanf("%d", &input);
        if (!isPrime(input))
            printf("%s must be prime!\n", variable);
        else
            valid = 1;
    } while (valid == 0);

    return input;
}

// Asks for user input
// Loops until a number between a and b is selected
int getNumberBetween(int a, int b, char* variable)
{
    int input;
    int valid = 0;
    do
    {
        printf("Enter a value for %s: ", variable);
        scanf("%d", &input);
        if (input <= a || input >= b)
            printf("%s must be a value between %d and %d!\n", variable, a, b);
        else
            valid = 1;
    } while (valid == 0);

    return input;
    printf("\n");
}

// Asks for user input
// Loops until a number between 1 and phi(n)
// is selected and is relatively prime to phi(n)
int get_e(int phin)
{
    int input;
    int valid = 0;
    do
    {
        input = getNumberBetween(1, phin, "e");
        if (gcd(input, phin) != 1)
            printf("e must be relativley prime to %d!\n", phin);

        else
            valid = 1;
    } while (valid == 0);

    return input;
}

// Square and multiply method 
unsigned __int128 squareAndMultiply(int a, int b)
{
    int i, * binary;
    binary = decToBinary(b);

    // find the first 1 bit from the left
    for (i = 0; i < 32; i++)
    {
        if (binary[i] == 1)
            break;
    }

    // First 1 adds the value a
    unsigned __int128 value = a;
    // Loop through the bits of b
    for (i += 1; i < 32; i++)
    {
        // 0 squares the value
        if (binary[i] == 0)
            value = value * value;
        // 1 squares the value and multiplies by a
        if (binary[i] == 1)
            value = (value * value) * a;
    }

    return value;
}

// Returns 1 for prime and 0 for not prime
int isPrime(unsigned int number) {
    if (number <= 1)
        return 0;

    unsigned int i;
    for (i = 2; i * i <= number; i++)
        if (number % i == 0)
            return 0;

    return 1;
}

// Returns an array of size 32 to represent bits 0-31
int* decToBinary(int num)
{
    static int binaryNumber[32];
    for (int i = 0; i < 32; i++)
    {
        binaryNumber[31 - i] = num % 2;
        num /= 2;
    }
    return binaryNumber;
}

// Returns the greatest commen devisor of a and b
int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}

