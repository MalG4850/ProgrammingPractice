def greetName_compiled(name: String) raises:
    print("\nHello from the compiled side, " + name + "!\n")

def greetName_dynamic(name: String):
    print("Hello from the dynamic side, " + name + "!\n")

def main() raises:
    user = input("\nWhat's your name? ")
    greetName_compiled(user)
    greetName_dynamic(user)