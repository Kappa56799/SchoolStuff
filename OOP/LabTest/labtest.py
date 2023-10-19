'''
Author: Kacper Palka C22376553
OS : Arch Linux
IDE: NeoVim
Description: A Concundrum Code game where the user has to guess the a random 3 digit value in python. The user has 5 lives which allows the user to make 4 mistakes before
finding the correct number.
'''
from random import randint #Only imports randint so we can generate a random number

#Main function which handels user input and allows the game to function
def User_input(random_number, lives):
    #Used for testing purposes
    #print(random_number)
    
    #Checks if 5 lives have been used and asks the user if they want to try again
    if lives == 5:
        print(f"\nYou have run out of tries! The number was: ", random_number)
        continue_game = input("Do you want to play again? (y\\n): ") #two escape characters to prevent any formatting errors

        #We cast it to lower case to ensure the user is able to quit and we have an error check which exits the program if y or n are not inputted
        if continue_game.lower() == 'n':
            print("Thank you for playing!")
            exit() #Quits the program

        elif continue_game.lower() == 'y':
            random_number = randint(100, 1000)
            lives = 0
            User_input(random_number, lives)

        elif continue_game.lower() != 'n' or 'y':
            print("Invalid Input please use (y or n)! ")
            exit() #made the program quit if user inputs anything that isn't y or n

    #This loop checks if the user still has any lives yet
    while lives != 5:
        
        #User guess
        user_guess = int(input(f"\nGuess a number: "))

        #Checks to see if the user inputted a 3 digit number
        if len(str(user_guess)) != 3:
            print("Not a 3 value number try again!")

        #If it is a 3 digit number the game plays
        else:
            Guess_game(user_guess, random_number, lives)
            break

#Function for our guessing game
def Guess_game(user_guess, random_number, lives):
    #we cast our numbers to strings to easily compare them
    string = str(user_guess)
    random_string = str(random_number)

    #Used to count our lives in the game
    lives += 1

    #Our checks to see if the numbers are in the correct order etc
    for i in range(len(string)):
        if string[i] == random_string[i]:
            print("Bullseye", end=" ")
        
        elif string[i] in random_string:
            print("Off-target", end=" ")

        elif string[i] != random_string[i]:
            print("Null", end=" ")

    #If the user guesses the number correctly they are asked if they want to play again or exit
    if user_guess == random_number:
        #Displays to the user if they want to play again
        print(f"\nYou have guessed the number correctly!")
        continue_game = input("Do you want to play again? (y\\n): ")
    
        #Same as before we cast it to lower to prevent and error if user in puts Y or N instead
        if continue_game.lower() == 'n':
            print("Thank you for playing!")
            exit()
        
        #restarts the game if the user wants to and generates a new number to guess and resets the users guesses
        elif continue_game.lower() == 'y':
            random_number = randint(100, 1000)
            lives = 0
            User_input(random_number, lives)

        elif continue_game.lower() != 'n' or 'y':
            print("Invalid Input please use (y or n)! ")
            exit()
    
    User_input(random_number,lives)

#Function which displays the rules to the user at the start of the program
def Print_Information():
    print(f"Welcome to 'Conundrum Code'. Try to guess the three digit number.\n")
    print("Here are some clues:")
    print("When I say 'Off-target' that means one of your digits is correct but in the wrong position.")
    print("When I say 'Bullseye' that means one of your digits is correct but in the right position.")
    print("When I say 'Null' that means one of your digits is incorrect.")

#Running out two functions to start the game and running our random_number generator
Print_Information()
random_number = randint(100, 1000)
User_input(random_number, 0)

