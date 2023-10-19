def is_happy_number(num):
    seen = set()
    while num != 1 and num not in seen:
        seen.add(num)
        for x in str(num):
            num = int(x) ** 2
    if num == 1:
        return num


def happy_numbers_up_to_n(n):
    happy_nums = [num for num in range(1, n + 1) if is_happy_number(num)]
    return happy_nums
    
try:
    num = int(input("Enter a number: "))
    if num < 1:
        print("Please enter a positive integer.")
    else:
        happy_nums = happy_numbers_up_to_n(num)
        print(f"Happy numbers up to", num, "are:\n", " ".join(str(x) for x in happy_nums))
except ValueError:
    print("Invalid input. Please enter a positive integer.")

