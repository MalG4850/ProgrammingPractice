def main():
    L = [1, 2, 3, 3, 5, 8, 8, 6, 4, 23, 24]
    new_list = []

    for item in L:
        if item not in new_list:
            new_list.append(item)

    print("The unique elements in the given list are: ", end = "")
    print(new_list)

if __name__ == "__main__":
    main()
