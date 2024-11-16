def f(n):
    cnt = 0 
    for i in range(1, n + 1):
        num = i
        digit_sum = 0

        while num > 0:
            digit_sum += num % 10
            num //= 10

        if i % digit_sum == 0:
            cnt += 1
            
    return cnt

n = int(input())

print(f(n))