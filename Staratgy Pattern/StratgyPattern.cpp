#include <iostream>
using namespace std;
class MachineControl{// Abstract class for any machine control type
    public:
        virtual void controlType() = 0;
};
class Machine { // Abstract class for any electric machine
    private:
        char type;
        char supply;
        MachineControl *controller;
    public:
        Machine( char typec,char supplyc, MachineControl *controllerc){
            type = typec;
            supply = supplyc;
            controller = controllerc;
        }
        void setController( MachineControl *Input){
            controller = Input;
        }
        void startControl(){
            controller->controlType();
        } 
};
class FOC : public MachineControl{
        void controlType(){
            cout <<"foc is applied"<<"\n";
               }        
};
class DTC : public MachineControl{
        void controlType(){
            cout <<"DTC is applied"<<"\n";
               }        
};
class VoltageControl : public MachineControl{
        void controlType(){
            cout <<"VoltageControl is applied"<<"\n";
               }        
};



int main(){
    // diffrent control algos
 FOC foc;
 DTC dtc;
 VoltageControl vc;
    // diffrent machine types
    // settinf diffrent control algo to each machine
 Machine Sync( 0 , 3 , &foc );
 Machine Induction( 1 , 3 , &dtc);
 Machine DC( 0 , 0 , &vc);
    // excuting the algos
 Sync.startControl();
 Induction.startControl();
 DC.startControl();
    // changing the algo during run time
 Sync.setController(&dtc);
 Sync.startControl();   

}