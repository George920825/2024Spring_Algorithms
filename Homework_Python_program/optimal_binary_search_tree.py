# def optimal_bst(p, q, n):
#     # Initialize tables e, w, and root
#     e = [[0] * (n + 2) for _ in range(n + 2)]
#     w = [[0] * (n + 2) for _ in range(n + 2)]
#     root = [[0] * (n + 1) for _ in range(n + 1)]
    
#     # Initialize e and w for the base cases
#     for i in range(1, n + 2):
#         e[i][i - 1] = q[i - 1]
#         w[i][i - 1] = q[i - 1]
    
#     # Calculate the optimal cost and root for each subtree length l
#     for l in range(1, n + 1):
#         for i in range(1, n - l + 2):
#             j = i + l - 1
#             e[i][j] = float('inf')
#             w[i][j] = w[i][j - 1] + p[j - 1] + q[j]
#             for r in range(i, j + 1):
#                 t = e[i][r - 1] + e[r + 1][j] + w[i][j]
#                 if t < e[i][j]:
#                     e[i][j] = t
#                     root[i][j] = r

#     return e, w, root

# # Example usage:
# # p = [0.15, 0.10, 0.05, 0.10, 0.20]
# # q = [0.05, 0.10, 0.05, 0.05, 0.05, 0.10]
# p = [5, 2, 4, 3]
# q = [3, 2, 3, 4, 2]
# n = len(p)

# e, w, root = optimal_bst(p, q, n)

# # Print the resulting tables
# print("e table:")
# for row in e:
#     print(row)

# print("\nw table:")
# for row in w:
#     print(row)

# print("\nroot table:")
# for row in root:
#     print(row)

def optimal_bst(p, q, n):
    # Initialize tables e, w, and root
    e = [[0] * (n + 2) for _ in range(n + 2)]
    w = [[0] * (n + 2) for _ in range(n + 2)]
    root = [[0] * (n + 1) for _ in range(n + 1)]
    
    # Initialize e and w for the base cases
    for i in range(1, n + 2):
        e[i][i - 1] = q[i - 1]
        w[i][i - 1] = q[i - 1]
    
    # Calculate the optimal cost and root for each subtree length l
    for l in range(1, n + 1):
        for i in range(1, n - l + 2):
            j = i + l - 1
            e[i][j] = float('inf')
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j]
            for r in range(i, j + 1):
                t = e[i][r - 1] + e[r + 1][j] + w[i][j]
                if t < e[i][j]:
                    e[i][j] = t
                    root[i][j] = r

    return e, w, root

# Example usage:
# p = [0.15, 0.10, 0.05, 0.10, 0.20]
# q = [0.05, 0.10, 0.05, 0.05, 0.05, 0.10]
p = [5, 2, 4, 3]
q = [3, 2, 3, 4, 2]
n = len(p)

e, w, root = optimal_bst(p, q, n)

# Print the resulting tables
print("e table:")
for row in e:
    print(row)

print("\nw table:")
for row in w:
    print(row)

print("\nroot table:")
for row in root:
    print(row)

# def optimal_bst(p, q, n):
#     # Initialize tables e, w, and root
#     e = [[0] * (n + 2) for _ in range(n + 2)]
#     w = [[0] * (n + 2) for _ in range(n + 2)]
#     root = [[0] * (n + 1) for _ in range(n + 1)]
    
#     # Initialize e and w for the base cases
#     for i in range(1, n + 2):
#         e[i][i - 1] = q[i - 1]
#         w[i][i - 1] = q[i - 1]
    
#     # Calculate the optimal cost and root for each subtree length l
#     for l in range(1, n + 1):
#         for i in range(1, n - l + 2):
#             j = i + l - 1
#             e[i][j] = float('inf')
#             w[i][j] = w[i][j - 1] + p[j - 1] + q[j]
#             for r in range(i, j + 1):
#                 t = e[i][r - 1] + e[r + 1][j] + w[i][j]
#                 if t < e[i][j]:
#                     e[i][j] = t
#                     root[i][j] = r

#     return e, root

# # Input values
# p = [5, 2, 4, 3]
# q = [3, 2, 3, 4, 2]
# n = len(p)

# # Calculate the optimal BST
# e, root = optimal_bst(p, q, n)

# # Print the resulting tables
# print("e table:")
# for row in e[1:n+2]:
#     print(row[1:n+2])

# print("\nroot table:")
# for row in root[1:n+1]:
#     print(row[1:n+1])
