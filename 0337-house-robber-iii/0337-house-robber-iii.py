# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        mpp={}
        def f(root, canrob,mpp):
            if(root==None):
                return 0
            if(mpp.get((root,canrob),"NO")!="NO"):
                return mpp.get((root,canrob))
            rob = -1e9
            nrob = -1e9
            
            if(canrob):
                rob = root.val + f(root.left,False,mpp) + f(root.right,False,mpp)
            
            nrob = f(root.left,True,mpp) + f(root.right,True,mpp)
        
            mpp[(root,canrob)] = max(rob,nrob);
            return mpp[(root,canrob)]
        
        return f(root,True,mpp);
                
        