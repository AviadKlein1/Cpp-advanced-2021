#include <iostream>
#include"date.h"
using namespace std;

int main() {
    int d, m, y, day1;
    char tav;
    cout << "Enter a date" << endl;
    cin >> d >> tav >> m >> tav >> y;
    date myDate(d, m, y);
    myDate.print();
    int choice;
    cout << "Enter an action code" << endl;
    cin >> choice;
    while (choice != -1) {
        switch (choice)
        {
        case 1: cout << "Enter a date " << endl;
            cin >> d >> tav >> m >> tav >> y;
            (myDate.setDate(d, m, y)).print();
            break;
        case 2: (++myDate).print();
            break;
        case 3: (myDate++).print();
            break;
        case 4:cout << "Enter #days" << endl;
            cin >> day1;
            (myDate += day1).print();
            break;
        case 5: { cout << "Enter a date" << endl;
            cin >> d >> tav >> m >> tav >> y;
            date myDate1(d, m, y);
            cout << ((myDate > myDate1) ? "<:true" : ">:false") << endl; }
              break;
        case 6: {cout << "Enter a date" << endl;
            cin >> d >> tav >> m >> tav >> y;
            date myDate2(d, m, y);
            cout << ((myDate < myDate2) ? ">:true" : "<:false") << endl; }
              break;
        case 7: {cout << "Enter a date" << endl;
            cin >> d >> tav >> m >> tav >> y;
            date myDate3(d, m, y);
            cout << ((myDate == myDate3) ? "==:true" : "!=false") << endl; }
              break;
        }
        cout << "Enter an action code" << endl;
        cin >> choice;
    }
    return 0;
}