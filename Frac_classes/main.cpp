#include <iostream>
#include "Frac_act.h"
#include "Dyn_Drib.h"

using namespace std;

int main()
{
    Dyn_Drib x;
    cout << "START size of x:" << x.size() << endl;
    x.push_back(14);

    cout << "Element 0: " << x[0] << endl;
    cout << "size of x:" << x.size() << endl;

    for (int i=0; i<5; ++i)
        x.push_back(i+5);
    cout << "Set 5 more elements" << endl;
    cout << "size of x:" << x.size() << endl;
    for (int i=0; i<6; ++i)
        cout << "Element "<< i <<": " << x[i] << endl;

    x.show_frac();





  /*  Dyn_Drib mas2;
    Dyn_Drib mas;
    mas.set_frac();
    mas.show_frac();

    cout << "\n" << endl;

    mas2 = mas;
    mas2.show_frac();


  cout << "\n" << endl;

    Drib d1(2,4);
    Drib d2(5,-3);

    cout << d1.get_ch() << "/" << d1.get_zn() << endl;
    cout << d2.get_ch() << "/" << d2.get_zn() << endl;

    if (d1==d2)
        cout << "They are equal!" << endl;
    else
        cout << "They are not equal!" << endl;

    cout << endl;
    cout << "d1 * d2 - (d1 - d2) / d1 = ";
    Drib dr(1,1);
    dr = d1 * d2 - (d1 - d2) / d1;

    cout << dr.get_ch() << "/" << dr.get_zn() << endl;
    cout << endl;

    cout << "d1 * d2 - (2 * (d1 - d2)) / d1 = ";
    Drib drv(1,1);
    drv = d1 * d2 - ((d1 - d2) * 2) / d1;
    cout << drv.get_ch() << "/" << drv.get_zn() << endl;
*/


    return 0;
}
