def double_value(value: Float64) -> Float64:
    return value * 2

def main() raises:
    try:
        rawInput = input("\nEnter the value of an integer to double it: ")
        count = Float64(rawInput)
        val: Float64 = double_value(count)
        print("Given Count: ", count, "\nDouble Value: ", val, end = "\n\n")

    except:
        print("\nError: Not a valid number!\n")