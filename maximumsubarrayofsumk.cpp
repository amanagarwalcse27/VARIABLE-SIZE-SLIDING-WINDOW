//if positive numbers
#include<bits/stdc++.h>
using namespace std;
 int maximumsubarrayofsumk(int a[],int n,int k)
{
    int sum = 0;
    int maxi = -1;
    int i = 0;
    int j = 0;

    while(j<n)
    {
        sum = sum + a[j]; //calculations

        if(sum<k) //calculation done less than given only incremnt in j
        {
            j++;
        }

        else if(sum == k) //condition obtain
        {
            maxi = max(maxi,j-i+1); //answer based on calcualtions
            j++; //increment in j
        }
        else if(sum > k) //
        {
            while(sum > k) //sliding of i to remove it
            {
                sum = sum - a[i];
                i++; //increment in i
            
            if(sum == k)  //htane ke baad bhi sum aas skat h eg 4 1 4
            {
                maxi = max(maxi,j-i+1);
            }
            }
            j++;
        } 
    } 
 return maxi;
    }
    int main()
    {
        int a[] = { 4,1,1,1,2,3,5};
        int n = sizeof(a)/sizeof(a[0]);
        int k = 5;

        cout<<"MAXIMUM SUBARRAY SUM K"<<" "<<maximumsubarrayofsumk(a,n,k)<<endl;

        return 0;

    }
