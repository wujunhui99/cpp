import torch
device = torch.device('cuda')
with open('n1.txt') as f:
    A = [[float(x) for x in line.split()] for line in f]
A = torch.tensor(A, device=device, dtype=torch.float64)

with open('n2.txt') as f:  
    B = [[float(x) for x in line.split()] for line in f]
B = torch.tensor(B, device=device, dtype=torch.float64)  

print(B.shape)
print(A.shape)
import time

p = time.time()
C = torch.matmul(A, B)
q = time.time()
print(q - p)