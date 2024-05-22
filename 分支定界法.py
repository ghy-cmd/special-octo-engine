import numpy as np
import heapq

def read_matrix(file_path):
    return np.loadtxt(file_path)

def branch_and_bound(M1, M2, start, end, max_fee):
    n = len(M1)
    pq = []  # 优先队列
    heapq.heappush(pq, (0, start, 0, [start]))  # (当前路径长度, 当前城市, 累积费用, 路径)
    visited = set()

    while pq:
        curr_len, curr_city, curr_fee, path = heapq.heappop(pq)

        if curr_city == end:
            return curr_len, curr_fee, path

        if (curr_city, curr_fee) in visited:
            continue

        visited.add((curr_city, curr_fee))

        for next_city in range(n):
            if M1[curr_city, next_city] > 0:  # 有路可走
                next_len = curr_len + M1[curr_city, next_city]
                next_fee = curr_fee + M2[curr_city, next_city]

                if next_fee <= max_fee:
                    heapq.heappush(pq, (next_len, next_city, next_fee, path + [next_city]))

    return None

# 读取矩阵
M1 = read_matrix('M1.txt')
M2 = read_matrix('M2.txt')

# 设定起点和终点
start_city = 0  # 城市Num.1
end_city = 49   # 城市Num.50
max_fee = 1500

# 执行分支定界算法
result = branch_and_bound(M1, M2, start_city, end_city, max_fee)

if result:
    min_length, total_fee, path = result
    print(f"最短路径长度: {min_length}")
    print(f"路径: {path}")
    print(f"总费用: {total_fee}")
else:
    print("没有找到符合条件的路径")
