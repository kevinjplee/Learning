class Solution {
public:
    string longestPalindrome(string s) {
        int s_len = s.size();
        std::vector<std::vector<bool>> memo(s_len, std::vector<bool>(s_len, false));
        int start_idx = 0;
        int maxlen= 1;
        for(int i = 0; i < s_len - 1; i++ )
        {
            memo[i][i] = true;
            //length 1 is always a palindrome
            if(s[i] == s[i + 1])
            {
                maxlen = 2;
                start_idx = i;
                memo[i][i+1] = true;
            }
            
            //check length 2 palindrome
            
        }
        memo[s_len - 1][s_len - 1] = true;
        
        for(int i = 3; i <= s_len; i++ )
        {
            for(int j = 0; j < s_len - i + 1; j++)
            {
                if(s[j] == s[j + i - 1])
                {
                    if(memo[j+1][j + i -2] == true)
                    {
                        memo[j][j + i - 1] = true;
                        if(maxlen < i)
                        {
                            maxlen =i;
                            start_idx = j;
                        }
                    }
                }
            }
        }
        return s.substr(start_idx, maxlen);
    }
};

// if we add one on left and one on the right it's a palindrome if left and right is the same and the middle was already a palindrome