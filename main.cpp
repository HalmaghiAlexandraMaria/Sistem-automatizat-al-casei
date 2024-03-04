#include "House.h"
using namespace std;
int main()
{

    //cout<<presiune.generatePresure()<<"\n";
    House casa;
    casa.addRoom(new IBedroom);
    casa.addRoom(new IBathroom);
    casa.addRoom(new IKitchen);
    casa.addRoom(new ILiving);
    casa.viewRoomData();
    casa.collectRoomData();
    return 0;
}
