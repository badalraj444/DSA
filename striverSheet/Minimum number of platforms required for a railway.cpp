class Solution
{
public:
    int findPlatform(vector<int> &Arrival, vector<int> &Departure)
    {
        // your code goes here
        int n = Arrival.size();
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());
        int i = 0, j = 0, ans = 0, curr = 0;
        while (i < n && j < n)
        {
            if (Arrival[i] <= Departure[j])
            {
                curr++;
                ans = max(ans, curr);
                i++;
            }
            else
            {
                curr--;
                j++;
            }
        }
        return ans;
    }
};

/*
KEY-OBSERVATIONS & INSIGHTS:
. find the maximum overlap at a time. that is the answer

ALGO:


PROBLEMS:

*/