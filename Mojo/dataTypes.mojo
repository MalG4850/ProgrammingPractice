def main():
    print("\nThis program shows declaration and printing of various data types.\n\n", end = "")

    comptime pi: Float64 = 3.14159265358979323                  # 64-bit float-point number
    x: Int32 = 10                                               # 32-bit integer
    y: Bool = True                                              # Boolean Value
    z: String = "Hello World!"                                  # String

    print("pi = ", pi, "\nx = ", x, "\ny = ", y, "\nz = ", z, end = "\n\n")