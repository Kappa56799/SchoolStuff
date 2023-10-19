#Question 2
def encrypt(string):
    encrypted_string = ""

    for i, x in enumerate(string):
        encrypted_string +=  chr(ord(x) + i)

    print(encrypted_string)

string = input("Enter a String: ")
encrypt(string)
