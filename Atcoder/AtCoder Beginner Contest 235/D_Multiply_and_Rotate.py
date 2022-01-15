from cv2 import INTER_MAX
from sqlalchemy import false


a,n = [int(i) for i in input().split()]

def solve(a,n,rot):
    if n==1:
        return 0
    p=-1
    if n%a == 0:
        p = solve(a,n//a,False)
        if p!=-1:
            p+=1
    if rot:
        return p
    num = str(n)
    for i in range(1,n):
        temp = int(num[:i] + num[i:])
        t_ans = solve(a,temp,True)
        if t_ans!=-1:
            t_ans+=i
        if t_ans==-1: continue
        if p==-1: p=t_ans
        else: p=min(p,t_ans)
    return p

print(solve(a,n,False))