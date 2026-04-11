#include <iostream>

class Box {
    private:
       double length, breadth, height;

   public:
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         std::cout <<"Constructor called." << "\n";
         length = l;
         breadth = b;
         height = h;
      }
      double Volume() {
         return length * breadth * height;
      }
      int compare(Box box) {
         return this -> Volume() > box.Volume();
      }
};

int main(void) {
   double length[2], breadth[2], height[2];

   for (int i = 0; i < 2; i++) {
       std::cout << "Enter the length of Box " << i+1 << ": ";
       std::cin >> length[i];

       std::cout << "Enter the breadth of Box " << i+1 << ": ";
       std::cin >> breadth[i];

       std::cout << "Enter the height of Box " << i+1 << ": ";
       std::cin >> height[i];
   }

   Box box1(length[0], breadth[0], height[0]), box2(length[1], breadth[1], height[1]);

   if(box1.compare(box2)) {
      std::cout << "Box2 is smaller than Box1" << "\n\n";
   } else {
      std::cout << "Box2 is equal to or larger than Box1" << "\n\n";
   }

   return 0;
}
