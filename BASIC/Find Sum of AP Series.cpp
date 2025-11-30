Input:  n = 4, a = 2, d = 2  
Output: 20  
Explanation:  The series is 2, 4, 6, 8.  
The sum of the series is 2 + 4 + 6 + 8 = 20.

  Time Complexity: O(1), we are using direct formula.

Space Complexity: O(1), as we are using a constant amount of space.



  float sumofAp(float a, float d, int n)
{
    // Formula for sum of AP series: (n / 2) * (2a + (n-1) * d)
    float sum = (n / 2.0) * (2.0 * a + (n - 1) * d);

    return sum;  // Return the calculated sum
}
