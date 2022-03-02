#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

class matrix
{
    public:
    	void Create(int X, int Y)
       	{
           	matrix = new int *[X];
   	        for (int z = 0; z < X; z++)
    	    {
    	    	matrix[z] = new int [Y];
    	   	}
    	}
        void getsize()
        {
            printf("\nX size: ");
            scanf("%d", &X);

            printf("Y size: ");
            scanf("%d", &Y);
            Create(X, Y);
        }
		        
		void nonmatrix()
		{
			for(int x = 0; x < X; x++)
			{
			    for(int y = 0; y < Y; y++)
			    {
			    	matrix[x][y] = 0;
				}
			}
		}

		void Ematrix()
		{
			nonmatrix();
			for(int xy = 0; xy < X; xy++)
			{
				matrix[xy][xy] = 1;
			}
		}
        
        void randmatrix()
        {
            for(int x = 0; x < X; ++x)
            {
                for(int y = 0; y < Y; ++y)
                {
                    int randnum = rand() % 11;
                    matrix[x][y] = randnum;
                }
            }
        }

        void retmatrix()
        {
        	for(int y = 0; y < Y; y++)
        	{
        		printf("\n");
        		for(int x = 0; x < X; x++)
        	    {
        	    	printf("%d ", matrix[x][y]);
        	    }
        	}
        	printf("\n");
        }

        void multmatrix()
        {
        	int a;
            printf("\nmultiply: ");
            scanf("%d", &a);
        	for(int y = 0; y < Y; y++)
        	{
        		for(int x = 0; x < X; x++)
        		{
        			matrix[x][y] *= a;
        		}
       		}	
        }
		
        int retx()
        {
        	return X;
        }
        
        int rety()
        {
        	return Y;
        }

		int retxy(int x, int y)
		{
			return matrix[x][y];
		}

		void setxy(int x, int y, int z)
		{
			matrix[x][y] = z;
		}
        
    private:
    	int X;
        int Y;
    	int **matrix;
};

matrix mult(matrix matrix1, matrix matrix2)
{
	matrix MATRIX;
	MATRIX.getsize();
	MATRIX.nonmatrix();
	if(matrix1.retx() == matrix2.rety())
	{
		for(int x = 0; x < MATRIX.retx(); x++)
		{
			for(int y = 0; y < MATRIX.rety(); y++)
			{
				int c = 0;
				for(int i = 0; i < matrix1.retx(); i++)
				{
					int a = matrix1.retxy(i, y);
					int b = matrix2.retxy(x, i);
					c += a * b;
				}
				MATRIX.setxy(x, y, c);
			}
		}
	}else{
		printf("Pipec skazal otec");
	}
	return MATRIX;
}

matrix add(matrix matrix1, matrix matrix2)
{
	matrix MATRIX;
	MATRIX.getsize();
	MATRIX.nonmatrix();
	if(matrix1.retx() == matrix2.retx() && matrix1.rety() == matrix2.rety())
	{
		for(int n = 0; n < matrix1.retx(); n++)
		{
			for(int m = 0; m < matrix1.rety(); m++)
			{
				int ad = matrix1.retxy(n, m) + matrix2.retxy(n, m);
				MATRIX.setxy(n, m, ad);
			}
		}
	}
	return MATRIX;
}

int main()
{
	srand(time(NULL));
    matrix Matrix;
    matrix Matrix2;
    Matrix.getsize();
    Matrix.randmatrix();
    Matrix2.getsize();
    Matrix2.Ematrix();
    Matrix.retmatrix();
	Matrix2.retmatrix();
	matrix Matrix3 = mult(Matrix, Matrix2);
	Matrix3.retmatrix();
    return 0; 
}
