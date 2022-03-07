def gauss(A):
    m = len(A)
    assert all(
        [len(row) == m + 1 for row in A[1:]]
    ), "Macierz nie jest symetryczna!"
    n = m + 1
    for k in range(m):
        pivots = [abs(A[i][k]) for i in range(k, m)]
        i_max = pivots.index(max(pivots)) + k
        assert A[i_max][k] != 0, "Macierz osobliwa!"
        A[k], A[i_max] = A[i_max], A[k]
        for i in range(k + 1, m):
            f = A[i][k] / A[k][k]
            for j in range(k + 1, n):
                A[i][j] -= A[k][j] * f
            A[i][k] = 0
    x = []
    for i in range(m - 1, -1, -1):
        x.insert(0, A[i][m] / A[i][i])
        for k in range(i - 1, -1, -1):
            A[k][m] -= A[k][i] * x[0]
    return x

print(gauss([[-1, 2, 1, -1], [1, -3, -2, -1], [3, -1, -1, 4]]))