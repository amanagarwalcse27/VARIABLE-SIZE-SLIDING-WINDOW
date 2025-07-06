#include<bits/stdc++.h>
using namespace std;

int longest_substring_with_k_unique(string s,int n,int k)
{
   map<char,int> mp;
    int maxi = INT_MIN;
   int i = 0,j = 0;

   while(j < n)
   {
    mp[s[j]]++;

    if(mp.size() < k)
    {
        j++;
    }

    else if(mp.size() == k)
    {
      maxi = max(maxi,j-i+1);
      j++;
    }

    else
     {
        while(mp.size() > k)
        {
            mp[s[i]]--;
            if(mp[s[i]] == 0)
            {
                mp.erase(s[i]);
            }
            i++;
        }
        j++;
    }
   }
   return maxi;
}

int main()
{
    string s = "abcabdefab";
    int n = s.size();
    int k = 3;
    cout << "Length of the longest substring with 3 unique characters is  "<<longest_substring_with_k_unique(s,n,k);

    return 0;
}   