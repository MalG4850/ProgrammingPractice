class Vehicle:
    name = ""
    type = "Car"
    colour = ""
    cost = None

    def __init__(self, name, type, colour, cost):
        self.name = name
        self.type = type
        self.colour = colour
        self.cost = cost

    def describe(self):
        description = f"This is a {self.type} called {self.name}, which is worth {self.cost} and is in {self.colour} here."
        return description


def main():
    V1 = Vehicle("Koenigsegg Agera", "car", "white", 100000000)
    V1.describe()


if __name__ == "__main__":
    main()
