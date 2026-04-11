def main():
    #Briefing
    print("This is a program to convert Temperature Scales.")
    ch = int(input("Which conversion do you want to do? \n\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n\nEnter your choice: "))

    if(ch == 1):
        c = float(input("\nEnter the Temperature in °C: "))
        f = float((c * (9/5)) + 32)
        print("\n",c,"°C is",f,"°F.")
    
    elif(ch == 2):
        f = float(input("\nEnter the Temperature in °F: "))
        c = float((f-32)*(9/5))
        print("\n",f,"°F is",c,"°C.")


if __name__ == "__main__":
    main()