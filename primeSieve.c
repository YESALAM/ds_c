#include <stdio.h>
#include <string.h>
 
void SieveOfEratosthenes(int n)
{
    // Create a int array "prime[0..n]" and initialize
    // all entries it to 0. A value in prime[i] will
    // finally be 1 if i is Not a prime, else 0.
    int prime[n+1];
    memset(prime, 0, (n+1)*sizeof(prime[0]));

    for (int p=2; p*p<=n; p++)
    {
        
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == 0)
        {
            
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = 1;
        }
    }
 
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p] == 0)
          printf("%d ",p);
    printf("\n");
}
 
// Driver Program to test above function
int main()
{
    int n = 30;
    printf("Following are the prime numbers smaller than or equal to %d.\n",n);
    SieveOfEratosthenes(n);
    return 0;
}