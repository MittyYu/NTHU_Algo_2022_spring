import random

# for n in range(10000000, 30000000, 1000000):
#     print(n)
#     sample = random.sample(range(n+5000000), n)
#     #print(sample)
#     sample_str = ' '.join(str(i) for i in sample)
    
#     with open("/Users/mittyu/Desktop/BD4-2/Algo/HW5/test_"+str(n)+".txt", 'w', encoding = 'utf-8') as f:
#         f.write(str(n))
#         f.write("\n")
#         f.write(sample_str)

n=30000000
sample = random.sample(range(n+5000000), n)
#print(sample)
sample_str = ' '.join(str(i) for i in sample)

with open("/Users/mittyu/Desktop/BD4-2/Algo/HW5/test_"+str(n)+".txt", 'w', encoding = 'utf-8') as f:
    f.write(str(n))
    f.write("\n")
    f.write(sample_str)

for n in range(10000000, 30000001, 1000000):
    print(random.sample(range(n), 1))
    print()
