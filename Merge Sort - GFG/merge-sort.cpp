//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         vector<int> left(m-l+1,0);
         vector<int> right(r-m,0);
         
         for(int i=0;i<left.size();i++)
         {
             left[i] = arr[l+i];
         }
         
         for(int i=0;i<right.size();i++)
         {
             right[i] = arr[i+m+1];
         }
         
         int index = l;
         int i=0,j=0;
         
         while(i<left.size() && j<right.size())
         {
             if(left[i]<right[j])
             {
                 arr[index++] = left[i++];
             }
             else
             arr[index++] = right[j++];
         }
         
         while(i<left.size())
         {
             arr[index++] = left[i++];
         }
         
         while(j<right.size())
         {
             arr[index++] = right[j++];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        
        if(l>=r)
            return;
        
        int mid = l + (r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends