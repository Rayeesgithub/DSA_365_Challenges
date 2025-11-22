Input: s = " -042"

Output: -42

int myAtoi(string s) 
{
    int i = 0;          // Pointer to traverse string
    int sign = 1;       // To track + or - sign, default is +
    long ans = 0;       // Store the converted number (long to handle overflow)

    // 1️⃣ Skip all leading spaces
    while(i < s.length() && s[i] == ' ')
        i++;

    // 2️⃣ Check sign of the number
    if(s[i] == '-')    
    {
        sign = -1;     // Negative number detected
        i++;
    }
    else if(s[i] == '+')
    {
        i++;           // Positive number (explicit +)
    }

    // 3️⃣ Convert digits until a non-digit character appears
    while(i < s.length())
    {
        // Check if current character is a digit
        if(s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * 10 + (s[i] - '0'); // Convert char → digit
            
            // 4️⃣ Check for overflow before applying sign
            if(ans > INT_MAX && sign == -1)
                return INT_MIN;  // Lower limit for 32-bit int

            else if(ans > INT_MAX && sign == 1)
                return INT_MAX;  // Upper limit for 32-bit int

            i++; // Move to next character
        }
        else
        {
            // If non-digit found, stop and return current value
            return ans * sign;
        }
    }
    
    // 5️⃣ Final result after applying sign
    return ans * sign;
}
