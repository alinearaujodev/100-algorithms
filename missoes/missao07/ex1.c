#include <stdio.h>

int
main ()
{
  int n, val = 0, i, c = 0, primo = 0;

  do{
      printf ("Digite o nmero: ");
      scanf ("%d", &n);

      c++;

      for (i = 1; i <= n; i++){
    	  if (n % i == 0){
    	      val++;
    	  }
	    }

      if (val == 2){
	      primo++;
    	}
      val = 0;
    }while (n > 1);

    printf ("Foram digitados %d número(s) ao total\n", c - 1);
    printf ("%d desses numero(s) são primos\n", primo);
    return 0;
}
