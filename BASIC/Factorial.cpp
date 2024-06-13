//approach1
int factorial(int X) {
   int ans = 1;
   for (int i = 1; i <= X; i++) {
      ans = ans * i;
   }
   return ans;
}
//approach-2
int factorial(n)
{
   if(n == 0)
   {
     return 1;
   }

return n * factorial(n-1);

}
