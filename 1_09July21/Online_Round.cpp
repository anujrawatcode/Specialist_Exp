// https://www.geeksforgeeks.org/infosys-interview-experience-for-specialist-profile/

#include <bits/stdc++.h>
using namespace std;

// Round 1: was a pure coding round  with two medium level coding questions to be solved in 1hr 30 min.

// 1.) There are  K events with start and end time and the total allocated time is N.
//     You have to arrange the events slots such that the events are as contiguous as possible,
//     thus maximizing the remaining time of the day.

// Example:

// N( total hour count)=15
// K( number of events)=3
// Next line contains the 3 events with [start_time  end_time] format.
// [0-5], [6-7], [8-10]

// Output: 7

int solve1(int st[], int fi[], int n, int M)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum > M) // if total time of events cross given time
            return -1;
        sum += fi[i] - st[i];
    }
    return M - sum;
}

// Goldmine
// https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1
// recursive
class SolutionRec
{

public:
    int solve(int i, int j, int n, int m, vector<vector<int>> &M)
    {
        if (i < 0 || i >= n || j >= m)
            return 0;
        if (j == m - 1)
            return M[i][j];
        else
            return M[i][j] + max(solve(i - 1, j + 1, n, m, M),
                                 max(solve(i + 1, j + 1, n, m, M), solve(i, j + 1, n, m, M)));
    }

public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, solve(i, 0, n, m, M));
        }
        return ans;
    }
};

class SolutionDP
{

    int dp[101][101];

public:
    int solve(int i, int j, int n, int m, vector<vector<int>> &M)
    {
        if (i < 0 || i >= n || j >= m)
            return 0;
        if (j == m - 1)
            return M[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        else
        {
            dp[i][j] = M[i][j] + max(solve(i - 1, j + 1, n, m, M),
                                     max(solve(i + 1, j + 1, n, m, M), solve(i, j + 1, n, m, M)));
            return dp[i][j];
        }
    }

public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        memset(dp, -1, sizeof(dp));
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, solve(i, 0, n, m, M));
        }
        return ans;
    }
};

// 2.) Gold Mine problem with a twist. You are in a nXn grid containing 0, 1 and -1s.

// 1 indicates it contains  1 unit of gold.

// 0 indicates that there is a path through that square

// -1 indicates that it is a blockage

// You need to reach [n-1][n-1], starting from [0][0] using down OR right movement.
// And then from [n-1][n-1] you need to go back to [0][0] using up  OR left movement.
// On the way, you have to choose the path through which you can pick maximum gold.
// Note that once you have picked the gold, that square becomes 0. The grid was of 100×100 size in worst case,
// so don’t use backtacking or any recursive approaches. Optimized code only.
// Example:
// N=4

// 1 1 -1

// 1 0 -1

// 1 1 1

// Ans: 6

int main()
{
    int st[] = {0, 6, 8};
    int fi[] = {5, 7, 10};
    int n = 3;
    int M = 15;
    // cout << solve1(st, fi, n, M);
}


// Round 2: (Technical Interview):
// It started off with basic introduction about myself, my projects and my interests.
// He then asked me to design a RESTful API to retrieve, update and edit a contacts database from your phone to a server. 
// I was asked to do this question because I had similar projects in my resume.
// I did not remember exact code for fetching and converting to JSON .
// But I was able to give him a good explanation regarding the whole process and part of the code.


// Then he gave me a problem to solve . There were a list of companies and their invoices(invoice ranges) for particular year. We had to find the missing invoices for that range, for every company. Its approach should be very similar to: Overlapping Intervals

 

// COMPANY	YEAR	INVOICE START	INVOICE END
// TCS   	2017	101	               105
// TCS	    2016	108	               110
// INFOSYS	2017	101	               104
// INFOSYS	2016	105	               109
// INFOSYS	2015	112	               113

//  Then we discussed my machine learning project in detail. 
//  I had used SVM and KNN in my project and also performed rigorous feature extraction as preprocessing in matlab.
//  I described each of the algorithms, why I used them and processing stages in detail.
 