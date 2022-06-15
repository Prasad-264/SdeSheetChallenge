/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where 
start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one 
meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}

Output: 
4

Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)

Example 2:

Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}

Output: 
1

Explanation:
Only one meetings can be held
with given start and end timings.
*/

class Solution {
public:
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++) {
            vec.push_back({end[i], start[i]});
        }
        sort(vec.begin(), vec.end());
        int cnt = 0;
        int meet = -1;
        for(int i=0; i<n; i++) {
            if(meet < vec[i].second) {
                meet = vec[i].first;
                cnt++;
            }
        }
        return cnt;
    }
};

//* Alternative :)

struct meeting{
    int start;
    int end;
    int pos;
};
bool comparator(struct meeting m1,meeting m2){
    if(m1.end<m2.end) return true;
    else if(m1.end>m2.end) return false;
    else if(m1.pos<m2.pos) return true;
    else return false;
}
vector<int> maximumMeetings(vector<int> &s, vector<int> &e) {
    // Write your code here.
    int n=s.size();
    struct meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].start=s[i],meet[i].end=e[i],meet[i].pos=i+1;
    }
    sort(meet,meet+n,comparator);
    vector<int> ans;
    int ending=meet[0].end;
    //first meeting toh hoge hee hogii
    ans.push_back(meet[0].pos);
    //last mai humhe positions chhaiye bss
    for(int i=1;i<n;i++){
        if(meet[i].start>ending){
            ending=meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}

// Time complexity : O(n) + O(n log n) + O(n) ~> O(n log n)
// Space Complexity: O(n)  
