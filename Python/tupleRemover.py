def main():
    tupleList = [(1, 2), (3, 4, 5), (6,), (7, 8, 9), (10, 11)]
    k = int(input("\nEnter the length of tuples for removal: "))
    newTupleList = [tup for tup in tupleList if len(tup) != k]
    print("\n", newTupleList)
    print()


if __name__ == "__main__":
    main()
