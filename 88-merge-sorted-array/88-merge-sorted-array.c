

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
   int i=0,j=0,k=0;
   int result[m+n];
    
    while(i<m && j<n)
    {
        if(nums1[i] < nums2[j])
        {
            result[k++]=nums1[i++];
        }
        else
        {
            result[k++]=nums2[j++];
        }
    }
    
    for(;i<m;i++)
        result[k++]=nums1[i];
    
    for(;j<n;j++)
        result[k++]=nums2[j];
    
    for(int l=0;l<m+n;l++)
    {
        nums1[l]=result[l];
    }
}