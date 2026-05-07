class myClass:
    output = "Hello, World!"

    def speak(self):
        print(myClass.output)


def main():
    myObject = myClass()
    myObject.speak()


if __name__ == "__main__":
    main()
