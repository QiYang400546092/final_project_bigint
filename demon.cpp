#include "bigint.hpp"
int main(void)
{
///////////////////////////////////////////////
    bigint A;
    cout<<A<<endl;
///////////////////////////////////////////////
    try
    {
        bigint B("ssafasfasd2424");
        cout<<B<<endl;
    }
    catch(const invalid_argument& e)
    {
        cout<<"Error: "<<e.what()<<endl;
    }
 //////////////////////////////////////////////   
    bigint C("564610467276851298754982765921657257229728975498101020450587924");
    cout<<C<<endl;
 //////////////////////////////////////////////
    try
    {
        bigint D("-13548487");
        cout<<D<<endl;
    }
    catch(const invalid_argument& e)
    {
        cout<<"Error: "<<e.what()<<endl;
    }
 //////////////////////////////////////////////
    try
    {
        bigint E("-000000017573548487");
        cout<<E<<endl;
    }
    catch(const invalid_argument& e)
    {
        cout<<"Error: "<<e.what()<<endl;
    }
 //////////////////////////////////////////////
    try
    {
        bigint F1("-17573548487");
        bigint F2("-17576222981");
        bigint F3("56168549");
        bigint F4("5616882");
        bigint F5("-17573548487");
        bigint F6("5616882");
        cout<<"F1 > F2 ? : " << (F1>F2) <<endl;
        cout<<"F3 > F4 ? : " << (F3>F4) <<endl;
        cout<<"F1 > F3 ? : " << (F1>F3) <<endl;
        cout<<"F4 > F2 ? : " << (F4>F2) <<endl;
        cout<<"F4 == F6 ? : " << (F4==F6) <<endl;
        cout<<"F4 >= F3 ? : " << (F4>=F3) <<endl;
        cout<<"F1 <= F5 ? : " << (F1<=F5) <<endl;
        cout<<"F1 < F6 ? : " << (F1<F6) <<endl;
    }
    catch(const invalid_argument& e)
    {
        cout<<"Error: "<<e.what()<<endl;
    }

/////////////////////////////////////////////////

    bigint G1("065168498");
    bigint G2("1315646");
    bigint G3("15168498498489");
    bigint G4("-15168498498489");
    bigint G5("-123");
    bigint G6("4534646");
    bigint G7("16549848615156484516514847862");
    bigint G8("2");
    bigint G9("-2");
    bigint G10("16549848615156484516514847862");
    bigint G11;

    // G1.two_positives_max_minus_min(G2);
    // G3.two_positives_max_plus_min(G1);
    G1+=G3;
    cout<<G1<<endl;

    G2-=G4;
    cout<<G2<<endl;

    G3*=G6;
    cout<<G3<<endl;

    G6 = G5;
    cout<<G6<<endl;

    G7/=G8;
    cout<<G7<<endl;

    G10/=G9;
    cout<<G10<<endl;

    G11-=G1;
    cout<<G11<<endl;

    cout<<(-G11)<<endl;

    G11 = G2;
    cout<<G11<<endl;

    cout<<bigint("564845")*bigint("-1544")<<endl;
}

