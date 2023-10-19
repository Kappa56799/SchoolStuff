#Question 1
def sum_divisors(num):
    i = 1
    divisors = []
    while i <= num:

        if num % i == 0:
            divisors.append(i)
        i += 1

    print(" + ".join(str(x) for x in divisors) + " = " + str(sum(divisors)))

num = int(input("Enter a number: "))
sum_divisors(num)


