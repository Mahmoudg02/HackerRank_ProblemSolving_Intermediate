long taskOfPairing(int freq_count, long* freq) {
    long mod =0 ;
    long result = 0;

    for (long i =0 ;i < freq_count ;i++)
    {
        if (freq[i])
        {
            freq[i]+=mod ;
        }
        result += freq[i]/2 ;
        mod =freq[i]%2;
    }
    return result ;
}