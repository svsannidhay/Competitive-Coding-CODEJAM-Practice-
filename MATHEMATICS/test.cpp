#include<iostream>
using namespace std;
typedef long long int lli;
const lli m = 1e9+7;
lli add(lli a, lli b){
   return ((a%m) + (b%m))%m;
}
lli mul(lli a, lli b){
   return ((a%m) * (b%m))%m;
}
class Solution {
   public:
   void multiply(lli A[5][5], lli B[5][5]){
      lli C[5][5];
      for(lli i =0;i<5;i++){
         for(lli j=0;j<5;j++){
            lli temp =0;
            for(lli k =0;k<5;k++){
               temp = add(temp,mul(A[i][k],B[k][j]));
            }
            C[i][j] = temp;
         }
      }
      for(lli i =0;i<5;i++){
         for(lli j =0;j<5;j++){
            A[i][j] = C[i][j];
         }
      }
   }
   lli solve(lli n){
      lli A[5][5] = { { 0, 1, 0, 0, 0 }, { 1, 0, 1, 0, 0 }, { 1, 1,
      0, 1, 1 }, { 0, 0, 1, 0, 1 }, { 1, 0, 0, 0, 0 } };
      lli result[5][5];
      for (lli i = 0; i < 5; i++) {
         for (lli j = 0; j < 5; j++) {
            if (i == j)
               result[i][j] = 1;
            else
               result[i][j] = 0;
         }
      }
      n--;
      for (int i = 1; i <= n; i++)
      multiply(result, A);
      lli sum = 0;
      for (lli i = 0; i < 5; i++) {
         for (lli j = 0; j < 5; j++) {
            sum = add(result[i][j], sum);
         }
      }
      return sum;
   }
   int countVowelPermutation(int n) {
      return solve(n);
   }
};
int main(){
   Solution ob;
   cout << (ob.countVowelPermutation(2));
   return 0;
}
