import HighOrLow_Variables
print("Hello.")
name = input('Enter your name here: ')
print('Hi ' + name + ". Lets play a game of high and low. The number is between 1 and 5.")
input("Press enter to generate a random number: ")
import random
number: int = int(random.randint(1, 5))
answer: int = int(input("Guess the number by typing it here: "))
if answer > number:
    input(HighOrLow_Variables.Text1 + str(number) + '. \n Press enter to end the game: ')
elif answer < number:
    input(HighOrLow_Variables.Text2 + str(number) + '. \n Press enter to end the game: ')
elif answer==number:
    input('Yay! You guessed it right! Congrats. \n Press enter to end the game:')
