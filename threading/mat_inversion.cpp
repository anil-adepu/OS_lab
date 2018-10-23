#include<stdio.h>

#include<math.h>
#include <pthread.h>
#include <stdlib.h>

float a[25][25], k, d,inverse[25][25];

void inverse_matrix() {
  printf("\n\n\nThe inverse of matrix is : \n");
  for (int i = 0;i < k; i++) {
      for (int j = 0;j < k; j++) {
	     printf("%.2f", inverse[i][j]);
	}
    printf("\n");
  }
}

float determinant(float a[25][25], float k){

float s = 1, det = 0, b[25][25];
int i, j, m, n, c;

if (k == 1)
     return (a[0][0]);
else {
 det = 0;
 for (c = 0; c < k; c++) {
      m = 0;
      n = 0;
      for (i = 0;i < k; i++) {
            for (j = 0 ;j < k; j++) {
                b[i][j] = 0;
                if (i != 0 && j != c){
                      b[m][n] = a[i][j];
                      if (n < (k - 2))
                          n++;
                      else {
                           n = 0;
                           m++;
                      }
                }
             }
      }
   det = det + s * (a[0][c] * determinant(b, k - 1));
   s = -1 * s;
 }
}
    return (det);
}

void transpose(float num[25][25], float fac[25][25], float r) {
  int i, j;
  float b[25][25], d;
  for (i = 0;i < r; i++) {
     for (j = 0;j < r; j++)
         b[i][j] = fac[j][i];
  }

  d = determinant(num, r);
  for (i = 0;i < r; i++) {
     for (j = 0;j < r; j++) {
        inverse[i][j] = b[i][j] / d;
        }
    }
}

void cofactor(float num[25][25], float f)
{
 float b[25][25], fac[25][25];
 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
    m = 0;
    n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f);
}

void *compute_determinant()
{
	d = determinant(a,k);
	pthread_exit(0);
}

void *compute_adjoint()
{
	cofactor(a,k);
	pthread_exit(0);
}

int main() {
  int i, j;
  printf("Enter the order of the Matrix : ");
  scanf("%f", &k);
  printf("Enter the elements of %.0fX%.0f Matrix : \n", k, k);
  for (i = 0;i < k; i++) {
     for (j = 0;j < k; j++)
       {
        scanf("%f", &a[i][j]);
       }
    }
    pthread_t tid[2];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&tid[0],&attr,compute_determinant,NULL);

    pthread_attr_init(&attr);
    pthread_create(&tid[1],&attr,compute_adjoint,NULL);

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    if(d == 0 )
    {
    	printf("determinant is zero.Inverse cant be computed\n");
    }
    else
    {
    	inverse_matrix();

    }
return 0;
}
