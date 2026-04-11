#include <iostream>

enum class DayPeriod { AM, PM };

class MilitaryTime {
    private:
        int minutes = 0, hours = 0;

    public:
        MilitaryTime(): hours(0), minutes(0) {}
        int getHours() const { return hours; }
        int getMinutes() const { return minutes; }
        void setHours(int h) { hours = h; }
        void setMinutes(int m) { minutes = m; }
};

class CivilianTime {
    private:
        int minutes = 0, hours = 0;
        DayPeriod period = DayPeriod::AM;

    public:
        CivilianTime(): hours(0), minutes(0), period(DayPeriod::AM) {}
        explicit CivilianTime(const MilitaryTime& mtime) {
            int mHours = mtime.getHours();
            minutes = mtime.getMinutes();

            if (mHours == 0) {
                hours = 12;
                period = DayPeriod::AM;
            } else if (mHours == 12) {
                hours = 12;
                period = DayPeriod::PM;
            } else if (mHours > 12) {
                hours = mHours - 12;
                period = DayPeriod::PM;
            } else {
                hours = mHours;
                period = DayPeriod::AM;
            }
        }

        void displayTime() const {
            std::cout << "\n" << hours << ":";
            if (minutes < 10) { std::cout << "0" << minutes; }
            else { std::cout << minutes; }
            if (period == DayPeriod::AM) { std::cout << " AM\n\n\n"; }
            else { std::cout << " PM\n\n"; }
        }
};

int main(void) {
    int h, m;
    MilitaryTime mTime;
    std::cout << "\nThis is a program to convert military time to civilian time, i.e. from a 24-hour clock to a 12-hour clock.\n\n";

    std::cout << "Enter the hours: ";
    std::cin >> h;
    mTime.setHours(h);

    std::cout << "Enter the minutes: ";
    std::cin >> m;
    mTime.setMinutes(m);

    CivilianTime cTime(mTime);

    cTime.displayTime();

    return 0;
}
