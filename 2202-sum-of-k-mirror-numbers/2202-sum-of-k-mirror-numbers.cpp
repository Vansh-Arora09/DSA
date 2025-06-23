class Solution 
{
public:
    long long kMirror(int k, int n) 
    {
        
        long long sum = 0;   
        
        
        int found = 0;       

       
        for (int len = 1; found < n; len++) 
        {
            int start = pow(10, (len - 1) / 2); 
            int end = pow(10, (len + 1) / 2);   

            
            for (int half = start; half < end; half++) 
            {
                long long pal = createPalindrome(half, len % 2 == 1);

                
                if (isBaseKPalindrome(pal, k)) 
                {
                    
                    sum += pal;     
                    
                    
                    found++;        
                    
                    
                    if (found == n)
                    {
                        return sum;
                    }
                }
            }
        }

        return sum;
    }

    
    long long createPalindrome(int half, bool odd) 
    {
        long long pal = half;
        if (odd)
        {
            half /= 10;
        }

        while (half > 0) 
        {
            pal = pal * 10 + (half % 10);
            half /= 10;
        }
        return pal;
    }

    
    bool isBaseKPalindrome(long long num, int k) 
    {
        long long rev = 0;
        long long orig = num;
        while (num > 0) 
        {
            rev = rev * k + num % k;
            num /= k;
        }
        
        return rev == orig;
    }
};