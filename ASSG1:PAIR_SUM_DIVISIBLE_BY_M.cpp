const int mod=1e9+7;                                    //this is the mod value, by which we have to take the mod of our final answer
int Solution::solve(vector<int> &A, int B)
{
    /*the basic idea of doing this question is that first of all we will make an array 'count' of size B, 
    in this array we will store the count of this value A[i]%B, so basically we will be traversing from 0 to n-1
    in vector A, and for every modulus value, we will just add 1 at B[arr[i]%B]. after making this array 'count'.
    
    Now we will initialise a variable 'ans', which will carry our final answer, so now we will make pairs of
    count[1] with count[B-1], count[2] with count[B-2], count[3] with count[B-3] and so on. Since we have stores the count
    of every modulus value of A[i], now we will just pair them, eg. 1+(B-1) it is equal to B, Now we will just multiply them with each other
    like we have done in line 34 and then we will add them to our 'ans'. And for count[0], it will make it's pair with itself, so we will do this for
    their pairing nC2 which is equal to (n!)/((2!)(n-2!)), basically this is the combination formula as we used it in line 37 after simplying this formula.
    
    So same thing we will do for the case of count[B/2] if B is an even number.

    After that we will return our final answer just by taking it's modulus with mod as we done in line 38.
    
    */
    int n=A.size();                                                  
    long long int count[B]={0};                       
    for(int i=0;i<n;i++)                               
    {
        int ans=A[i]%B;
        count[ans]++;
    }
    long long int ans=0;
    for(int i=1;i<=B/2;i++)
    {
        if(i==B/2 and B%2==0)
        {
            ans+=(count[B/2]*(count[B/2]-1))/2;
            break;
        }
        int k=(count[i])*(count[B-i]);
        ans+=k;
    }
    ans+=(count[0]*(count[0]-1))/2;
    return ans%mod;
}
//notebook 2 page number 261-267