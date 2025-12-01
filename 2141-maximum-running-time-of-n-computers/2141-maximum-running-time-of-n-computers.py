class Solution(object):
    def maxRunTime(self, n, batteries):
        """
        :type n: int
        :type batteries: List[int]
        :rtype: int
        """
        batteries.sort()   
        extra = sum(batteries[:-n])
        
        live = batteries[-n:]
        
       
        for i in range(n - 1):
            
            if extra // (i + 1) < live[i + 1] - live[i]:
                return live[i] + extra // (i + 1)
            
           
            extra -= (i + 1) * (live[i + 1] - live[i])
        
        return live[-1] + extra // n
        