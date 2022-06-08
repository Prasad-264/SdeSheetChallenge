/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 
Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.

Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.
*/

class Solution {
#define ll long long
public:
    
    ll int inversionCount(ll arr[], ll n) {
        return mergeSortInitial(arr, 0, n-1);
    }
    
    ll mergeSortInitial(ll arr[], int l, int r) {
        ll temp[r-l+1];
        return mergeSort(arr,temp,l,r);
    }
    
    ll mergeSort(ll arr[], ll temp[], int l, int r) {
        ll cnt = 0;
        if(l < r) {
            ll m = (l+r) >> 1;
            cnt += mergeSort(arr, temp, l, m);
            cnt += mergeSort(arr, temp, m+1, r);
            cnt += merge(arr, temp, l, m, r);
        }
        return cnt;
    }
    
    ll merge(ll a[], ll temp[], int l, int m, int r) {
        ll c = 0; 
        int i = l, j = m+1; int k = l; 
        
        while(i <= m and j <= r) {
            if(a[i] <= a[j]) {
                temp[k++] = a[i++];
            }
            else {
                temp[k++] = a[j++];
                c += (m+1)-i;
            }
        }
        
        while(i<=m) {
            temp[k++] = a[i++];
        }
        while(j<=r) {
            temp[k++] = a[j++];
        }
        for(int i=l; i<=r; i++)
            a[i] = temp[i];
        
        return c;
    }
};

