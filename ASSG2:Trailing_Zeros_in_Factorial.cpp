//notebook 1 page number 72-72
int Solution::trailingZeroes(int A) 
{
    int pow_of_5=5;
    int ans=0;
    while(A>=pow_of_5)
    {
        ans+=A/pow_of_5;
        pow_of_5*=5;
    }
    return ans;
}
/*
in this question, we can't do factorial and then calculate number of zeroes in factorial, because let's say 121, 
we don't have any datatype to store factorial of 121. you can check page number 72-74 of Notebook 1 for understanding.
*/
