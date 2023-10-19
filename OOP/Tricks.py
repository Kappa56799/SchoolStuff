#Using Enumerate instead of range(len())
'''
data = [1, 2, -3, -4]
for idx, num in enumerate(data):
    if num < 0:
        data[idx] = 0

print(data,idx)
'''

#Joining Strings together
'''
list_of_strings = ["Hello", "my", "friend"]
my_string = " ".join(list_of_strings)
print(my_string)
'''

#Instead of using multiple if Statements we can use if x in list
'''
colors = ["red", "green", "blue"]

c = "red"

# better:
if c in colors:
    print("is main color")
'''

#Use with open instead of open as it automatically closes the file even if it has an error
'''
with open("hello.txt") as my_file:
    print(my_file.read())
'''

#Lambda Functions instead of def
'''
x = lambda a : a + 10
print(x(5))
'''

#Init is used to initialize the object  and self is used to refer to the current object
'''
class Person:
  def __init__(self, name, age):
    self.name = name
    self.age = age

p1 = Person("John", 36)

print(p1.name)
print(p1.age)
'''

#Python Lets us iterate through strings,lists and tuples using this
'''
mystr = "banana" #this can be a string,list or tuple

for x in mystr:
  print(x, end="")
'''

'''
#Python lets us cast variables easily using this format
num = 5
string = str(num)
print(string)
'''

#Change Display list with no brackets,commas

items = [1,2,3,4,5,6]
print(items)
string = " ".join(str(x) for x in items)
print(string)
