def kaprekar_number(num):
    i = 10
    list_of_numbers = []
    while i <= num:
        sum = pow(i,2)
        string = str(sum)
        length = len(string) // 2
        left = string[:length]
        right = string[length:]
        
        if int(left) + int(right) == i:
            list_of_numbers.append(i)
    
        i += 1

    return list_of_numbers

def print_kaprekar_number(output):
    print("10 " + " ".join(str(x) for x in (output)))

num = int(input("Enter a number: "))
output = kaprekar_number(num)
print_kaprekar_number(output)



