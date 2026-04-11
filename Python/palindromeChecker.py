def main():
    s = str(input("\n\nEnter a string to check if it is a palindrome or not: "))
    print("\n\n",s,"is a palindrome.\n\n") if s == s[::-1] else print("\n\n",s,"is not a palindrome.\n\n")


if __name__ == "__main__":
    main()