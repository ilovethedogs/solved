bool arePermutation(string A, string B)
{
    // your code goes here
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    return A == B;
}