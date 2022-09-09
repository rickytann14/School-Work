#include <math.h>
#include <vector>

int cos_sim(std::vector<int> A, std::vector<int>B)
{
	int Dot_Product = 0; // is the dot product  of A and B vectors
	int A_frequency = 0; // is the square root of the sum of A
	int B_frequency = 0; // is the square root of the sum of B
	
	std::vector<int>::iterator B_iter = B.begin();
	std::vector<int>::iterator A_iter = A.begin();
	
    for( ; A_iter != A.end(); A_iter++ , B_iter++ )// iterates though vectors to obtain frequency & Dot product
    {
        Dot_Product += *A_iter * *B_iter; // Dot product
        A_frequency += *A_iter * *A_iter;
        B_frequency += *B_iter * *B_iter;
    }
return Dot_Product / (sqrt(A_frequency) * sqrt(B_frequency)); // returns Cosine Similarity of Vectors A and B


}