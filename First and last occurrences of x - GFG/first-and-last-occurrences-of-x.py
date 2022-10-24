#User function Template for python3


def find(arr,n,x):
    # code here
    res = [-1]*2
    flag = False
    for i in range(0,n):
        if(arr[i]==x and flag==False):
            flag = True
            res[0]=i
        elif(arr[i]==x):
            res[1]=i
    if(res[1]==-1 and res[0]!=-1):
        res[1]=res[0]
    return res


#{ 
 # Driver Code Starts
t=int(input())
for _ in range(0,t):
    l=list(map(int,input().split()))
    n=l[0]
    x=l[1]
    arr=list(map(int,input().split()))
    ans=find(arr,n,x)
    print(*ans)
# } Driver Code Ends