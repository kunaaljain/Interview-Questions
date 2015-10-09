<<<<<<< HEAD
#include <iostream>
using namespace std;
const int SIZE = 10;

class safearay
{
   private:
      int arr[SIZE];
   public:
      safearay() 
      {
         register int i;
         for(i = 0; i < SIZE; i++)
         {
           arr[i] = i;
         }
      }
      int operator[](int i)
      {
          if( i > SIZE )
          {
              cout << "Index out of bounds" <<endl; 
              // return first element.
              return arr[0];
          }
          return arr[i];
      }
};
int main()
{
   safearay A;

   cout << "Value of A[2] : " << A[2] <<endl;
   cout << "Value of A[5] : " << A[5]<<endl;
   cout << "Value of A[12] : " << A[12]<<endl;

   return 0;
} 
=======
#include<bits/stdc++.h>
using namespace std;

int power(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    while((A[A.length()-1] - '0') % 2 == 0)
    {
        //A[0] = (int)(A[0] - '0') /  2 + '0';
        int even = 1;
        for(int i =0; i < A.length() ; i++)
        {
            if(even){
                if(A[i]%2) even = 0;
                A[i] =(int)((A[i] - '0') / 2 )+ '0';
            }
            else
            {
                if(A[i]%2==0) even = 1;
                A[i] = ((int)((A[i] - '0')/2) + 5) + '0';
            }
        }
        cout<<A<<endl;
    }
    for(int i = 0; i < A.length() - 1;i++) if(A[i]!='0') return 0;
    if(A[A.length()-1]!='1') return 0;
    return 1;
}


int main()
{
    string a,b;
    a="10240";
    b="002";
    cout<<endl<<power(a);    
}
>>>>>>> bc713a7c05ecc991b74a7b099df23b84b1e96daa
