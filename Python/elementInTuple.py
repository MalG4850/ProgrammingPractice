def main():
    t1 = (1, 2, 3, 4, 5)
    i = int(input("Enter the element you want to search in the tuple: "))
    print(
        f"{i} exists in the tuple." if i in t1 else f"{i} does not exist in the tuple."
    )


if __name__ == "__main__":
    main()
